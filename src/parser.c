/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:38:20 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/29 13:24:34 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse(t_env *env, int argc, char *file_name)
{
	int		fd;

	if (argc < 2)
		ft_exit("Error, invalid arguments.", EXIT_FAILURE);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_exit("Error, can't open file.", EXIT_FAILURE);
	parse_args(env, fd);
	if (!env->camera)
		ft_exit("Error, no camera found.", EXIT_FAILURE);
}

static void	parse_line2(t_env *env, char **result)
{
	if (!ft_strcmp_ignrcase(result[0], "plane") ||
	!ft_strcmp_ignrcase(result[0], "cylindre") ||
	!ft_strcmp_ignrcase(result[0], "cone") ||
	!ft_strcmp_ignrcase(result[0], "sphere"))
		parse_general_object(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "triangle"))
		parse_triangle(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "camera"))
		parse_camera(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "light"))
		parse_light(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "material"))
		parse_material(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "define"))
		parse_define(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "config"))
		parse_config(env, result);
	else if (result[0][0] != '#')
		ft_exit("Error, invalid file. Unknown object type.", EXIT_FAILURE);
}

static void	parse_line(t_env *env, char *datas)
{
	char	**result;

	result = NULL;
	if (!datas[0] || !(result = ft_strsplit(replace_tab_by_space(datas), ' '))
	|| !result[0])
	{
		if (result)
			free(result);
		return ;
	}
	parse_line2(env, result);
	free_2d_array(result);
}

void		parse_args(t_env *env, int fd)
{
	char	*result;

	while (get_next_line(fd, &result) == 1)
	{
		parse_line(env, result);
		free(result);
	}
}
