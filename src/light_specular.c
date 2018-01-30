/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:42:45 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 15:20:26 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_specular(t_collision *collision, t_vector *normal, t_vector *light_dir)
{
	float		value;
	t_vector	reflect;
	float		dot;

	dot = dot_product(&collision->dir, normal);
	reflect.x = -2. * dot * normal->x + collision->dir.x;
	reflect.y = -2. * dot * normal->y + collision->dir.y;
	reflect.z = -2. * dot * normal->z + collision->dir.z;
	vector_normalize(&reflect);
	//dot = dot_product(&collision->dir, &reflect);
	//printf("dot: %f\n", dot);
	//value = powf(dot, 1);
	value = dmax(0.0, pow(cos(ft_math_dabs(vector_angle(light_dir, &reflect))), 600));
	//value = pow(cos(ft_math_dabs(vector_angle(&collision->dir, normal) - vector_angle(light_dir, normal))), 200);
	//if (value > 0.00001)
		//printf("specular_value: %f, collis_angle: %f, light_dir_angle: %f, abs: %f, cos: %f\n", value, ft_todegrees(vector_angle(&collision->dir, &reflect)), ft_todegrees(vector_angle(light_dir, &reflect)), ft_math_dabs(vector_angle(light_dir, &reflect)), cos(ft_math_dabs(vector_angle(&collision->dir, normal) - vector_angle(light_dir, normal))));
	collision->color.r = dmin(255, collision->color.r + value);
	collision->color.g = dmin(255, collision->color.g + value);
	collision->color.b = dmin(255, collision->color.b + value);
}

/*void	add_specular(t_collision *collision, t_vector *normal, t_vector *light_dir)
{
	float		value;
	t_vector	reflect;
	float		dot;

	dot = dot_product(light_dir, normal);
	reflect.x = -2. * dot * normal->x + light_dir->x;
	reflect.y = -2. * dot * normal->y + light_dir->y;
	reflect.z = -2. * dot * normal->z + light_dir->z;
	//dot = dot_product(&collision->dir, &reflect);
	//printf("dot: %f\n", dot);
	//value = powf(dot, 1);
	value = powf(dmax(0.0, cos(vector_angle(&collision->dir, &reflect))), 10);
	//value = pow(cos(ft_math_dabs(vector_angle(&collision->dir, normal) - vector_angle(light_dir, normal))), 200);
	//if (value > 0.00001)
		printf("specular_value: %f, collis_angle: %f, light_dir_angle: %f, abs: %f, cos: %f\n", value, ft_todegrees(vector_angle(&collision->dir, &reflect)), ft_todegrees(vector_angle(light_dir, &reflect)), ft_math_dabs(vector_angle(light_dir, &reflect)), cos(ft_math_dabs(vector_angle(&collision->dir, normal) - vector_angle(light_dir, normal))));
	collision->color.r = dmin(255, collision->color.r + value * collision->object->color_r);
	collision->color.g = dmin(255, collision->color.g + value * collision->object->color_g);
	collision->color.b = dmin(255, collision->color.b + value * collision->object->color_b);
}*/
