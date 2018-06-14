/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 13:29:27 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			check_ambient(t_env *env, t_collision *collision)
{
	if (collision->color.r < get_color_r(env->light_ambient))
		collision->color.r = dmin(255, collision->color.r +
		get_color_r(env->light_ambient) * .2);
	if (collision->color.g < get_color_g(env->light_ambient))
		collision->color.g = dmin(255, collision->color.g +
		get_color_g(env->light_ambient) * .2);
	if (collision->color.b < get_color_b(env->light_ambient))
		collision->color.b = dmin(255, collision->color.b +
		get_color_b(env->light_ambient) * .2);
}

unsigned int	get_light_color(t_env *env, t_collision *collision,
int recursion)
{
	t_vector		normal;

	if (recursion > REFLECTION_DEPTH)
		return (0);
	get_normal_vector(&normal, collision->object, collision);
	vector_normalize(&normal);
	collision->color.r = 0;
	collision->color.g = 0;
	collision->color.b = 0;
	find_light(env, collision, &normal);
	check_reflection(env, collision, &normal, recursion);
	light_transparency(env, collision, recursion);
	return (conv_rgb_to_int(collision->color.r, collision->color.g,
	collision->color.b));
}
