/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_object_material.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:09:30 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 12:57:54 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	fill_object_with_material2(t_object *object, t_material *material)
{
	if (material->has_parsed_scale && !object->has_parsed_scale)
	{
		object->scale = material->scale;
		object->has_parsed_scale = 1;
	}
	if (material->has_parsed_reflection && !object->has_parsed_reflection)
	{
		object->reflection = material->reflection;
		object->has_parsed_reflection = 1;
	}
	if (material->has_parsed_transparency && !object->has_parsed_transparency)
	{
		object->transparency = material->transparency;
		object->has_parsed_transparency = 1;
	}
}

void		fill_object_with_material(t_object *object, t_material *material)
{
	if (material->has_parsed_color && !object->has_parsed_color)
	{
		object->color_r = material->color_r;
		object->color_g = material->color_g;
		object->color_b = material->color_b;
		object->has_parsed_color = 1;
	}
	if (material->has_parsed_position && !object->has_parsed_position)
	{
		object->pos.x = material->pos.x;
		object->pos.y = material->pos.y;
		object->pos.z = material->pos.z;
		object->has_parsed_position = 1;
	}
	if (material->has_parsed_rotation && !object->has_parsed_rotation)
	{
		object->rot.x = material->rot.x;
		object->rot.y = material->rot.y;
		object->rot.z = material->rot.z;
		object->has_parsed_rotation = 1;
	}
	fill_object_with_material2(object, material);
}
