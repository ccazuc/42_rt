/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:39:39 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	if (!collision->object->is_light)
	{
		check_reflection(env, collision, &normal, recursion);
		light_transparency(env, collision, recursion);
	}
	check_refraction(env, collision, &normal, recursion);
	return (conv_rgb_to_int(collision->color.r, collision->color.g,
	collision->color.b));
}
