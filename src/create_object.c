/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:01:33 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 11:03:54 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object	*create_object(void)
{
	t_object	*object;

	if (!(object = malloc(sizeof(*object))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	if (!(object->pos = malloc(sizeof(*object->pos))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	object->has_parsed_color = 0;
	object->has_parsed_position = 0;
	object->has_parsed_rotation = 0;
	object->has_parsed_scale = 0;
	object->rot_x = 0;
	object->rot_y = 0;
	object->rot_z = 0;
	object->color_r = DEFAULT_COLOR_R;
	object->color_g = DEFAULT_COLOR_G;
	object->color_b = DEFAULT_COLOR_B;
	object->scale = 1;
	return (object);
}
