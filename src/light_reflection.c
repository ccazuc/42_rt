/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:54:47 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 11:57:09 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	check_reflection(t_env *env, t_collision *collision,
t_vector *normal, int recursion)
{
	t_ray		ray;
	int			tmp_color;
	float		dot;
	int			color_res;

	if (collision->object->reflection == 0)
		return (0);
	dot = dot_product(&collision->dir, normal);
	ray.dir.x = -2. * dot * normal->x + collision->dir.x;
	ray.dir.y = -2. * dot * normal->y + collision->dir.y;
	ray.dir.z = -2. * dot * normal->z + collision->dir.z;
	vector_normalize(&ray.dir);
	ray.pos.x = collision->pos.x;
	ray.pos.y = collision->pos.y;
	ray.pos.z = collision->pos.z;
	tmp_color = get_pixel_color(env, &ray, recursion + 1, collision->object);
	color_res = color_add(color_factor(conv_rgb_to_int(collision->color.r,
	collision->color.g, collision->color.b), 1. -
	collision->object->reflection), color_factor(tmp_color,
	collision->object->reflection));
	collision->color.r = get_color_r(color_res);
	collision->color.g = get_color_g(color_res);
	collision->color.b = get_color_b(color_res);
	return (tmp_color);
}
