/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:03:23 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 10:51:15 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	check_collision(t_env *env, t_ray *ray,
t_collision *collision, t_object *previous_object)
{
	t_object_list	*list;

	list = env->object_list;
	collision->distance = 100000000;
	collision->object = NULL;
	collision->dir.x = ray->dir.x;
	collision->dir.y = ray->dir.y;
	collision->dir.z = ray->dir.z;
	while (list)
	{
		if (list->object->type == SPHERE)
			collide_sphere(ray, list->object, collision, previous_object);
		else if (list->object->type == CYLINDRE)
			collide_cylinder(ray, list->object, collision, previous_object);
		else if (list->object->type == CONE)
			collide_cone(ray, list->object, collision, previous_object);
		else if (list->object->type == PLANE)
			collide_plane(ray, list->object, collision, previous_object);
		list = list->next;
	}
	if (collision->object == previous_object)
		return (0);
	return (collision->object ? 1 : 0);
}
