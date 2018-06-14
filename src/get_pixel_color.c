/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:48:47 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 11:55:57 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	get_pixel_color(t_env *env, t_ray *ray,
int recursion, t_object *previous_object)
{
	unsigned int	color;
	t_collision		collision;

	color = BG_COLOR;
	if (recursion > REFLECTION_DEPTH)
		return (color);
	collision.color.r = 0;
	collision.color.g = 0;
	collision.color.b = 0;
	if (check_collision(env, ray, &collision, previous_object)
	&& collision.object)
	{
		color = conv_rgb_to_int(collision.object->color_r,
		collision.object->color_g, collision.object->color_b);
		color = get_light_color(env, &collision, recursion);
	}
	return (color);
}
