/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pieces_datas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:26:27 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/15 13:15:24 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_position(t_object *object, char **datas, int *start)
{
	printf("Position: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for position.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2]) ||
	!ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Position's parameters are invalid.", -1);
	object->pos_x = ft_atoi(datas[*start + 1]);
	object->pos_y = ft_atoi(datas[*start + 2]);
	object->pos_z = ft_atoi(datas[*start + 3]);
	start += 3;
}

void	parse_rotation(t_object *object, char **datas, int *start)
{
	printf("Rotation: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for rotation.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2]) ||
	!ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Rotation's parameters are invalid.", -1);
	object->rot_x = ft_atoi(datas[*start + 1]);
	object->rot_y = ft_atoi(datas[*start + 2]);
	object->rot_z = ft_atoi(datas[*start + 3]);
	*start += 3;
}

void	parse_color(t_object *object, char **datas, int *start)
{
	printf("Color: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
	{
		printf("1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
		ft_exit("Error, invalid file. Not enough parameters for color.", -1);
	}
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2]) ||
	!ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Color's parameters are invalid.", -1);
	object->color_r = ft_atoi(datas[*start + 1]);
	object->color_g = ft_atoi(datas[*start + 2]);
	object->color_b = ft_atoi(datas[*start + 3]);
	if (object->color_r < 0 || object->color_g < 0 || object->color_b < 0)
		ft_exit("Error, invalid file.", -1);
	*start += 3;
}
