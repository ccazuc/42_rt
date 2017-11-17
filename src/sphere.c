/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:13:35 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 10:51:59 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		collide_sphere(t_ray *ray, t_object *object, double *distance)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos->x - object->pos_x;
	new.y = ray->pos->y - object->pos_y;
	new.z = ray->pos->z - object->pos_z;
	quadratic.a = dot_product(ray->dir, ray->dir);
	quadratic.b = 2 * dot_product(ray->dir, &new);
	quadratic.c = dot_product(&new, &new) - object->scale * object->scale;
	//printf("dot_product: %f\n", dot_product(&new, &new));
	//printf("quad | a: %f, b: %f, c: %f\n", quadratic.a, quadratic.b, quadratic.c);
	solve_quadratic(quadratic, &result);
	*distance = result;
	//printf("distance: %f\n", *distance);
	return (result);
}
