/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_object_define.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:11:17 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 16:48:35 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_object_color_define(t_object *object, t_define *define, int *i)
{
	if (define->nb_value != 3)
		ft_exit("Error, invalid file. Define has not enough argument for color.", EXIT_FAILURE);
	if (define->x < 0 || define->x > 255 || define->y < 0 || define->y > 255 || define->z < 0 || define->z > 255)
		ft_exit("Error, invalid file. Define has negative value for an object color.", EXIT_FAILURE);
	object->color_r = define->x;
	object->color_g = define->y;
	object->color_b = define->z;
	object->has_parsed_color = 1;
	*i += 1;
}

void	fill_object_position_define(t_object *object, t_define *define, int *i)
{
	if (define->nb_value != 3)
		ft_exit("Error, invalid file. Define has not enough argument for position.", EXIT_FAILURE);
	object->pos.x = define->x;
	object->pos.y = define->y;
	object->pos.z = define->z;
	object->has_parsed_position = 1;
	*i += 1;
}

void	fill_object_rotation_define(t_object *object, t_define *define, int *i)
{
	if (define->nb_value != 3)
		ft_exit("Error, invalid file. Define has not enough argument for rotation.", EXIT_FAILURE);
	object->rot.x = define->x;
	object->rot.y = define->y;
	object->rot.z = define->z;
	object->has_parsed_rotation = 1;
	*i += 1;
}