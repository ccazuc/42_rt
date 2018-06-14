/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_transparency.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:06:33 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 13:36:50 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	light_transparency(t_env *env, t_collision *collision, int recursion)
{
	t_ray	ray;
	int		tmp_color;
	int		color_res;

	if (collision->distance <= .000000001)
		return ;
	ray.dir.x = collision->dir.x;
	ray.dir.y = collision->dir.y;
	ray.dir.z = collision->dir.z;
	ray.pos.x = collision->pos.x;
	ray.pos.y = collision->pos.y;
	ray.pos.z = collision->pos.z;
	vector_normalize(&ray.dir);
	tmp_color = get_pixel_color(env, &ray, recursion, collision->object);
	color_res = color_add(color_factor(conv_rgb_to_int(collision->color.r,
	collision->color.g, collision->color.b), 1. -
	collision->object->transparency), color_factor(tmp_color,
	collision->object->transparency));
	collision->color.r = get_color_r(color_res);
	collision->color.g = get_color_g(color_res);
	collision->color.b = get_color_b(color_res);
}
