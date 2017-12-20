/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:03:23 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 12:11:26 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_collision_color(t_collision *collision)
{
	collision->color.r = collision->object->color_r;
	collision->color.g = collision->object->color_g;
	collision->color.b = collision->object->color_b;
}

static void	fill_collision_datas(t_collision *collision,
t_collision *tmp, t_object *object)
{
	collision->distance = tmp->distance;
	collision->object = object;
	collision->pos.x = tmp->pos.x;
	collision->pos.y = tmp->pos.y;
	collision->pos.z = tmp->pos.z;
	init_collision_color(collision);
}

int			check_collision(t_env *env, t_ray *ray, t_collision *collision)
{
	t_rtlist	*list;
	t_collision	*tmp_collision;

	list = env->object_list;
	tmp_collision = create_collision();
	collision->distance = 1000000;
	collision->object = NULL;
	while (list)
	{
		if (list->object->type == SPHERE)
			collide_sphere(ray, list->object, tmp_collision);
		else if (list->object->type == CYLINDRE)
			collide_cylinder(ray, list->object, tmp_collision);
		else if (list->object->type == CONE)
			collide_cone(ray, list->object, tmp_collision);
		else if (list->object->type == PLANE) {
			collide_plane(ray, list->object, tmp_collision);
			//if (tmp_collision->distance)
			//printf("plane dist: %f, min dist: %f\n", tmp_collision->distance, collision->distance);
}
		if (tmp_collision->distance > 0
		&& tmp_collision->distance < collision->distance)
			fill_collision_datas(collision, tmp_collision, list->object);
		list = list->next;
	}
	free_collision(tmp_collision);
	return (collision->object ? 1 : 0);
}
