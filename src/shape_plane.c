/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:27:04 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:28:09 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_plane_normal(t_vector *vector,
t_object *object, t_collision *collision)
{
	double		angle;

	vector->x = 0;
	vector->y = 1;
	vector->z = 0;
	vector_rotate(vector, &object->rot);
	object = NULL;
	angle = vector_angle(vector, &collision->dir) * 180. / M_PI;
	if (angle <= 90)
	{
		vector->x = -vector->x;
		vector->y = -vector->y;
		vector->z = -vector->z;
	}
}

void	collide_plane(t_ray *ray, t_object *object,
t_collision *collision, t_object *previous_object)
{
	double		result;
	t_vector	new;
	t_vector	norm;
	double		dist;

	norm.x = 0;
	norm.y = 1;
	norm.z = 1;
	new.x = object->pos.x - ray->pos.x;
	new.y = object->pos.y - ray->pos.y;
	new.z = object->pos.z - ray->pos.z;
	vector_rotate(&norm, &object->rot);
	result = dot_product(&norm, &ray->dir);
	if (!result)
		return ;
	dist = dot_product(&norm, &new) / result;
	if (dist < 0.001 || dist >= collision->distance)
		return ;
	if (previous_object == object && dist < 0.0001)
		return ;
	collision->distance = dist;
	collision->pos.x = ray->pos.x + ray->dir.x * dist;
	collision->pos.y = ray->pos.y + ray->dir.y * dist;
	collision->pos.z = ray->pos.z + ray->dir.z * dist;
	collision->object = object;
}
