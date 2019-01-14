/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle_attribute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:36:30 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:52:17 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_triangle_p1(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_position)
		ft_exit("Error, invalid file. p1 duplicate for a triangle."
				, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for triangle p1."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
			|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Triangle's p1's parameters are invalid."
				, EXIT_FAILURE);
	object->pos.x = ft_atoi(datas[*start + 1]);
	object->pos.y = ft_atoi(datas[*start + 2]);
	object->pos.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_position = 1;
}

void	parse_triangle_p2(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_rotation)
		ft_exit("Error, invalid file. p2 duplicate for a triangle."
				, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for triangle p2."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
			|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Triangle's p2's parameters are invalid."
				, EXIT_FAILURE);
	object->rot.x = ft_atoi(datas[*start + 1]);
	object->rot.y = ft_atoi(datas[*start + 2]);
	object->rot.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_rotation = 1;
}

void	parse_triangle_p3(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_p3)
		ft_exit("Error, invalid file. p3 duplicate for a triangle."
				, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for triangle p3."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
			|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Triangle's p3's parameters are invalid."
				, EXIT_FAILURE);
	object->p3.x = ft_atoi(datas[*start + 1]);
	object->p3.y = ft_atoi(datas[*start + 2]);
	object->p3.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_p3 = 1;
}
