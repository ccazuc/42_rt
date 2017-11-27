/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:21:14 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 15:16:34 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*get_cylinder_normal(t_object *object, t_vector *pos)
{
	t_vector	*vector;

	if (!(vector = malloc(sizeof(*vector))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	vector->x = pos->x - object->pos->x;
	vector->z = pos->z - object->pos->z;
	return (vector);
}

int			collide_cylinder(t_ray *ray, t_object *object, t_collision *collision)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos->x - object->pos->x;
	new.y = ray->pos->y - object->pos->y;
	new.z = ray->pos->z - object->pos->z;
	quadratic.a = ray->dir->x * ray->dir->x + ray->dir->z * ray->dir->z;
	quadratic.b = 2.0 * ray->dir->x * new.x + 2.0 * ray->dir->z * new.z;
	quadratic.c = new.x * new.x + new.z * new.z - object->scale * object->scale;
	if (!solve_quadratic(&quadratic, &result))
		return (result);
	collision->distance = result;
	collision->pos.x = ray->pos->x + ray->dir->x * result;
	collision->pos.y = ray->pos->y + ray->dir->y * result;
	collision->pos.z = ray->pos->z + ray->dir->z * result;
	return (result);
}
