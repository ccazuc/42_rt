/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:38:20 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 08:45:18 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse(t_env *env, int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_exit("Error, invalid arguments.", EXIT_FAILURE);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit("Error, invalid file.", EXIT_FAILURE);
	parse_args(env, fd);
	if (!env->camera)
		ft_exit("Error, no camera found.", EXIT_FAILURE);
}

void	parse_line(t_env *env, char *datas)
{
	char	**result;

	printf("parse_line start\n");
	if (!datas[0] || !(result = ft_strsplit(replace_tab_by_space(datas), ' '))
	|| !result[0])
		return ;
	printf("parse_line after split\n");
	printf("result[0]: %s\n", result[0]);
	if (!ft_strcmp_ignrcase(result[0], "cube") ||
	!ft_strcmp_ignrcase(result[0], "cylindre") ||
	!ft_strcmp_ignrcase(result[0], "triangle") ||
	!ft_strcmp_ignrcase(result[0], "sphere"))
		parse_general_object(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "camera"))
		parse_camera(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "light"))
		parse_light(env, result);
	else if (result[0][0] != '#')
		ft_exit("Error, invalid file.", EXIT_FAILURE);
	free_2d_array(result);
	printf("parse_line end\n");
}

void	parse_args(t_env *env, int fd)
{
	char	*result;
	printf("parse_args start\n");
	while (get_next_line(fd, &result) == 1)
	{
		printf("result: '%s'\n", result);
		parse_line(env, result);
		free(result);
	}
	printf("parse_args end\n");
}
