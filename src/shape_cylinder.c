/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:26:18 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/22 00:30:44 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cylinder_normal(t_vector *vector, t_object *object, t_vector *pos)
{
	t_vector rot;

	vector->x = pos->x - object->pos.x;
	vector->y = pos->y - object->pos.y;
	vector->z = pos->z - object->pos.z;
	rot = object->rot;
	vector_unrotate(vector, &object->rot);
	vector->y = 0;
	rot.y = 0;
	vector_rotate(vector, &rot);
}

void	collide_cylinder(t_ray *ray, t_object *object,
		t_collision *collision, t_object *previous_object)
{
	t_vector	new;
	t_vector	dir;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos.x - object->pos.x;
	new.y = ray->pos.y - object->pos.y;
	new.z = ray->pos.z - object->pos.z;
	dir = ray->dir;
	vector_unrotate(&new, &object->rot);
	vector_unrotate(&dir, &object->rot);
	quadratic.a = dir.x * dir.x + dir.z * dir.z;
	quadratic.b = 2.0 * dir.x * new.x + 2.0 * dir.z * new.z;
	quadratic.c = new.x * new.x + new.z * new.z - object->scale * object->scale;
	if (!solve_quadratic(&quadratic, &result))
		return ;
	if (result >= collision->distance || result < 0)
		return ;
	if (previous_object == object && result < 0.0001)
		return ;
	collision->distance = result;
	collision->pos.x = ray->pos.x + ray->dir.x * result;
	collision->pos.y = ray->pos.y + ray->dir.y * result;
	collision->pos.z = ray->pos.z + ray->dir.z * result;
	collision->object = object;
}
