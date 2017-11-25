/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:21:14 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/25 16:13:40 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		collide_cylinder(t_ray *ray, t_object *object, double *distance)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos->x - object->pos_x;
	new.y = ray->pos->y - object->pos_y;
	new.z = ray->pos->z - object->pos_z;
	//quadratic.a = ray->dir->x * ray->dir->x + ray->dir->z * ray->dir->z;
	//quadratic.b = 2.0 * ray->dir->x * new.x +  2.0 * ray->dir->z * new.z;
	quadratic.c = new.x * new.x + new.z * new.z - object->scale * object->scale;
	quadratic.a = ray->dir->y * ray->dir->y + ray->dir->z * ray->dir->z;
	quadratic.b = 2.0 * (ray->dir->y * new.y + ray->dir->z * new.z);
	solve_quadratic(quadratic, &result);
	//result = (-quadratic.b - sqrt(quadratic.b * quadratic.b - quadratic.a * quadratic.c)) / quadratic.a;
	if (result != 0 && result != 0.0)
		printf("delta: %f\n", result);
	*distance = result;
	return (result);
}
