/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:26:18 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/31 13:01:01 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cylinder_normal(t_vector *vector, t_object *object, t_vector *pos)
{
	vector->x = pos->x - object->pos.x;
	vector->z = pos->z - object->pos.z;
}

void	collide_cylinder(t_ray *ray, t_object *object, t_collision *collision)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos.x - object->pos.x;
	new.y = ray->pos.y - object->pos.y;
	new.z = ray->pos.z - object->pos.z;
	quadratic.a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	quadratic.b = 2.0 * ray->dir.x * new.x + 2.0 * ray->dir.z * new.z;
	quadratic.c = new.x * new.x + new.z * new.z - object->scale * object->scale;
	if (!solve_quadratic(&quadratic, &result))
		return ;
	collision->distance = result;
	collision->pos.x = ray->pos.x + ray->dir.x * result;
	collision->pos.y = ray->pos.y + ray->dir.y * result;
	collision->pos.z = ray->pos.z + ray->dir.z * result;
	collision->dir.x = ray->dir.x;
	collision->dir.y = ray->dir.y;
	collision->dir.z = ray->dir.z;
}
