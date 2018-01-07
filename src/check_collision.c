/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:03:23 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/31 15:28:10 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			check_collision(t_env *env, t_ray *ray, t_collision *collision)
{
	t_object_list	*list;

	list = env->object_list;
	collision->distance = 1000000;
	collision->object = NULL;
	while (list)
	{
		if (list->object->type == SPHERE)
		{
			collide_sphere(ray, list->object, collision);
			//printf("collide sphere \n");
		}
		else if (list->object->type == CYLINDRE)
			collide_cylinder(ray, list->object, collision);
		else if (list->object->type == CONE)
			collide_cone(ray, list->object, collision);
		else if (list->object->type == PLANE)
			collide_plane(ray, list->object, collision);
		list = list->next;
	}
	return (collision->object ? 1 : 0);
}
