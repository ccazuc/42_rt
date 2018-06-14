/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:42:45 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 11:57:43 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_specular(t_collision *collision,
t_vector *normal, t_vector *light_dir)
{
	float		value;
	t_vector	reflect;
	float		dot;

	dot = dot_product(&collision->dir, normal);
	reflect.x = -2. * dot * normal->x + collision->dir.x;
	reflect.y = -2. * dot * normal->y + collision->dir.y;
	reflect.z = -2. * dot * normal->z + collision->dir.z;
	vector_normalize(&reflect);
	value = dmax(0.0, pow(cos(ft_math_dabs(vector_angle(light_dir,
	&reflect))), 600));
	collision->color.r = dmin(255, collision->color.r + value);
	collision->color.g = dmin(255, collision->color.g + value);
	collision->color.b = dmin(255, collision->color.b + value);
}
