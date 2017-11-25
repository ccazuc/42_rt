/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pieces_datas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:26:27 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/25 15:26:45 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_position(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_position)
		ft_exit("Error, invalid file. Position duplicate for an object."
		, EXIT_FAILURE);
	printf("Position: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for position."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Position's parameters are invalid."
		, EXIT_FAILURE);
	object->pos_x = ft_atoi(datas[*start + 1]);
	object->pos_y = ft_atoi(datas[*start + 2]);
	object->pos_z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_position = 1;
}

void	parse_rotation(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_rotation)
		ft_exit("Error, invalid file. Rotation duplicate for an object."
		, EXIT_FAILURE);
	printf("Rotation: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for rotation."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Rotation's parameters are invalid."
		, EXIT_FAILURE);
	object->rot_x = ft_atoi(datas[*start + 1]);
	object->rot_y = ft_atoi(datas[*start + 2]);
	object->rot_z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_rotation = 1;
}

void	parse_color(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_color)
		ft_exit("Error, invalid file. Color duplicate for an object."
		, EXIT_FAILURE);
	printf("Color: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for color.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Color's parameters are invalid."
		, EXIT_FAILURE);
	object->color_r = ft_atoi(datas[*start + 1]);
	object->color_g = ft_atoi(datas[*start + 2]);
	object->color_b = ft_atoi(datas[*start + 3]);
	if (object->color_r < 0 || object->color_g < 0 || object->color_b < 0)
		ft_exit("Error, invalid file. Color's value is invalid."
		, EXIT_FAILURE);
	*start += 3;
	object->has_parsed_color = 1;
}

void	parse_scale(t_object *object, char **datas, int *start)
{
	if (object->has_parsed_scale)
		ft_exit("Error, invalid file. Scale duplicate for an object."
		, EXIT_FAILURE);
	printf("Scale: %s\n", datas[*start + 1]);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for color."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Color's parameters are invalid."
		, EXIT_FAILURE);
	object->scale = ft_atoi(datas[*start + 1]);
	if (object->scale <= 0)
		ft_exit("Error, invalid file. Scale's value is invalid."
		, EXIT_FAILURE);
	*start += 1;
	object->has_parsed_scale = 1;
}
