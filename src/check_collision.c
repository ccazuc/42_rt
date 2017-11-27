/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:03:23 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 15:37:25 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_collision_color(t_collision *collision)
{
	collision->color.r = collision->object->color_r;
	collision->color.g = collision->object->color_g;
	collision->color.b = collision->object->color_b;
}

int		check_collision(t_env *env, t_ray *ray, t_collision *collision)
{
	t_rtlist	*list;
	t_collision	*tmp_collision;

	list = env->object_list;
	tmp_collision = create_collision();
	collision->distance = 1000000;
	collision->object = NULL;
	while (list)
	{
		//printf("list iter\n");
		if (list->object->type == SPHERE)
			collide_sphere(ray, list->object, tmp_collision);
		else if (list->object->type == CYLINDRE)
			 collide_cylinder(ray, list->object, tmp_collision);
		if (tmp_collision->distance > 0 && tmp_collision->distance < collision->distance)
		{
			collision->distance = tmp_collision->distance;
			collision->object = list->object;
			collision->pos.x = tmp_collision->pos.x;
			collision->pos.y = tmp_collision->pos.y;
			collision->pos.z = tmp_collision->pos.z;
			init_collision_color(collision);
		}
		list = list->next;
	}
	free_collision(tmp_collision);
	return (collision->object ? 1 : 0);
}
