/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:03:23 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 10:49:07 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		check_collision(t_env *env, t_ray *ray)
{
	t_rtlist	*list;
	double		dist;
	double		tmp_dist;

	list = env->object_list;
	dist = 10000;
	while (list)
	{
		if (list->object->type == SPHERE && collide_sphere(ray, list->object, &tmp_dist) && tmp_dist < dist)
			dist = tmp_dist;
		list = list->next;
	}
	//printf("final dist: %f\n", dist);
	if (dist != 10000)
		printf("Collision distance: %f\n", dist);
	return (dist != 10000);
}
