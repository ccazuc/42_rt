/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:45:30 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:45:31 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_obj_line(t_env env, char *data)
{
	char	**result;

	if (!(result = ft_strsplit(data, ' ')) || !result[0])
		return ;
	if (ft_array_len(result) != 4)
		return ;
	if (!ft_strcmp(result[0], "v"))
		parse_obj_vertex(env, result);
	else if (!ft_strcmp(result[0], "f"))
		parse_obj_point(env, result);
	else if (!ft_strcmp(result[0], "vn"))
		parse_obj_normal(env, result);
}

void	parse_obj(t_env *env, int fd)
{
	char	*data;

	while (get_next_line(fd, &data) == 1)
	{
		parse_obj_line(env, data);
		free(data);
	}
}
