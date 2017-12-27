/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:26:25 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 12:32:13 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	*get_sphere_normal(t_vector *vector, t_object *object, t_vector *pos)
{
	vector->x = pos->x - object->pos.x;
	vector->y = pos->y - object->pos.y;
	vector->z = pos->z - object->pos.z;
}

void	collide_sphere(t_ray *ray, t_object *object, t_collision *collision)
{
	t_vector	new;
	t_quadratic	quadratic;
	double		result;

	new.x = ray->pos->x - object->pos.x;
	new.y = ray->pos->y - object->pos.y;
	new.z = ray->pos->z - object->pos.z;
	quadratic.a = dot_product(ray->dir, ray->dir);
	quadratic.b = 2 * dot_product(ray->dir, &new);
	quadratic.c = dot_product(&new, &new) - object->scale * object->scale;
	if (!solve_quadratic(&quadratic, &result))
		return ;
	collision->distance = result;
	//printf("sphere dist: %f\n", result);
	collision->pos.x = ray->pos->x + ray->dir->x * result;
	collision->pos.y = ray->pos->y + ray->dir->y * result;
	collision->pos.z = ray->pos->z + ray->dir->z * result;
	collision->dir.x = ray->dir->x;
	collision->dir.y = ray->dir->y;
	collision->dir.z = ray->dir->z;
}
