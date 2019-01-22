/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:48:47 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/22 16:36:19 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float		add_color(float color, double factor)
{
	if (color * factor > 255.)
		return (255.);
	return (color * factor);
}

static unsigned int	check_ambient(t_env *env, unsigned int color)
{
	t_color_mask	mask;
	t_color_mask	clr;

	clr.r = get_color_r(color);
	clr.g = get_color_g(color);
	clr.b = get_color_b(color);
	if (clr.r < get_color_r(env->light_ambient))
		mask.r = add_color(clr.r, env->ambient_power);
	else
		mask.r = clr.r;
	if (clr.g < get_color_g(env->light_ambient))
		mask.g = add_color(clr.g, env->ambient_power);
	else
		mask.g = clr.g;
	if (clr.b < get_color_b(env->light_ambient))
		mask.b = add_color(clr.b, env->ambient_power);
	else
		mask.b = clr.b;
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
		color = check_ambient(env, color);
	}
	return (color);
}
