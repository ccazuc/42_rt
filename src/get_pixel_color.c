/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:48:47 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/17 19:53:19 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float		add_color(float color, double factor)
{
	if (color * factor > 255.)
		return (255.);
	return (color * factor);
}

static unsigned int	check_ambient(t_env *env, t_collision *hit,
		unsigned int color)
{
	t_color_mask	mask;
	t_color_mask	obj_clr;

	if (hit->object->has_texture)
		obj_clr = texture_checkboard(hit->pos, hit->object->rot,
				hit->object->texu_offs, hit->object->texu_size);
	else
	{
		obj_clr.r = hit->object->color_r;
		obj_clr.g = hit->object->color_g;
		obj_clr.b = hit->object->color_b;
	}
	if (get_color_r(color) < get_color_r(env->light_ambient))
		mask.r = add_color(obj_clr.r, env->ambient_power);
	else
		mask.r = get_color_r(color);
	if (get_color_g(color) < get_color_g(env->light_ambient))
		mask.g = add_color(obj_clr.g, env->ambient_power);
	else
		mask.g = get_color_g(color);
	if (get_color_b(color) < get_color_b(env->light_ambient))
		mask.b = add_color(obj_clr.b, env->ambient_power);
	else
		mask.b = get_color_b(color);
	return (conv_rgb_to_int(mask.r, mask.g, mask.b));
}

unsigned int		get_pixel_color(t_env *env, t_ray *ray,
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
		color = get_light_color(env, &collision, recursion);
		color = check_ambient(env, &collision, color);
	}
	return (color);
}
