/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:13:35 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 09:21:20 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*get_sphere_normal(t_object *object, t_vector *pos)
{
	t_vector	*result;

	if (!(result = malloc(sizeof(*result))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	result->x = pos->x - object->pos.x;
	result->y = pos->y - object->pos.y;
	result->z = pos->z - object->pos.z;
	//printf("Sphere normal x: %f, y: %f, z: %f\n", result->x, result->y, result->z);
	//printf("Sphere vec pos: x: %f, y: %f, z: %f, object->pos: x: %f, y: %f, z: %f\n", pos->x, pos->y, pos->z, object->pos->x, object->pos->y, object->pos->z);
	return (result);
}

int			collide_sphere(t_ray *ray, t_object *object, t_collision *collision)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	result = 0;
	new.x = ray->pos->x - object->pos.x;
	new.y = ray->pos->y - object->pos.y;
	new.z = ray->pos->z - object->pos.z;
	quadratic.a = dot_product(ray->dir, ray->dir);
	quadratic.b = 2 * dot_product(ray->dir, &new);
	quadratic.c = dot_product(&new, &new) - object->scale * object->scale;
	if (!solve_quadratic(&quadratic, &result))
		return (result);
	collision->distance = result;
	collision->pos.x = ray->pos->x + ray->dir->x * result;
	collision->pos.y = ray->pos->y + ray->dir->y * result;
	collision->pos.z = ray->pos->z + ray->dir->z * result;
	return (result);
}
