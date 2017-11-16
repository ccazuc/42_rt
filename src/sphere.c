/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:13:35 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 12:14:58 by ccazuc           ###   ########.fr       */
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
	quadratic.b = 2 * dot_product(ray->dir, new);
	quadratic.c = dot_product(new, new) - object->scale;
	solve_quadratic(quadratic, &result);
	return (result);
}
