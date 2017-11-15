/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:38:20 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/15 13:31:23 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse(t_env *env, int argc, char **argv)
{
	int		fd;

	printf("parse start\n");
	if (argc != 2)
		ft_exit("Error, invalid arguments.", -1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit("Error, invalid file.", -1);
	parse_args(env, fd);
	printf("parse end\n");
}

void	parse_line(t_env *env, char *datas)
{
	char	**result;

	printf("parse_line start\n");
	if (!datas[0] || datas[0] == ' ')
		return ;
	if (!(result = ft_strsplit(datas, ' ')))
		return ;
	//printf("split result: '%s'\n", result[0]);
	if (!ft_strcmp_ignrcase(result[0], "cube") ||
	!ft_strcmp_ignrcase(result[0], "cylindre") ||
	!ft_strcmp_ignrcase(result[0], "triangle"))
		parse_general_object(env, result);
	else if (!ft_strcmp_ignrcase(result[0], "sphere"))
		//parse_sphere(env, result);
		;
	else if (result[0][0] != '#')
	{
		printf("result[0][0]: %c\n", result[0][0]);
		ft_exit("Error, invalid file.", -1);
	}
	printf("parse_line end\n");
}

void	parse_args(t_env *env, int fd)
{
	char	*result;
	printf("pars_args start\n");
	while (get_next_line(fd, &result) == 1)
	{
		printf("result: '%s'\n", result);
		parse_line(env, result);
	}
	printf("parse_args end\n");
}
