/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:26:10 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/31 13:03:22 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cone_normal(t_vector *vector, t_object *object, t_vector *pos)
{
	vector->x = pos->x - object->pos.x;
	vector->y = pos->y - object->pos.y;
	vector->z = pos->z - object->pos.z;
}

void	collide_cone(t_ray *ray, t_object *object, t_collision *collision)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos.x - object->pos.x;
	new.y = ray->pos.y - object->pos.y;
	new.z = ray->pos.z - object->pos.z;
	quadratic.a = ray->dir.x * ray->dir.x - ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z;
	quadratic.b = 2.0 * (ray->dir.x * new.x - ray->dir.y * new.y + ray->dir.z * new.z);
	quadratic.c = new.x * new.x - new.y * new.y + new.z * new.z;
	if (!solve_quadratic(&quadratic, &result))
		return ;
	if (result >= collision->distance)
		return ;
	collision->distance = result;
	collision->pos.x = ray->pos.x + ray->dir.x * result;
	collision->pos.y = ray->pos.y + ray->dir.y * result;
	collision->pos.z = ray->pos.z + ray->dir.z * result;
	collision->dir.x = ray->dir.x;
	collision->dir.y = ray->dir.y;
	collision->dir.z = ray->dir.z;
	collision->object = object;
}
