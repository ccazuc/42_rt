/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 12:21:38 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	find_light(t_env *env, t_collision *collision)
{
	t_light_list	*list;
	t_ray			ray;
	t_collision		find_collision;
	t_vector		normal;
	double			norm_angle;

	list = env->light_list;
	ray.pos.x = collision->pos.x;
	ray.pos.y = collision->pos.y;
	ray.pos.z = collision->pos.z;
	get_normal_vector(&normal, collision->object, collision);
	vector_normalize(&normal);
	while (list)
	{
		ray.dir.x = list->light->pos.x - collision->pos.x;
		ray.dir.y = list->light->pos.y - collision->pos.y;
		ray.dir.z = list->light->pos.z - collision->pos.z;
		vector_normalize(&ray.dir);
		if (check_collision(env, &ray, &find_collision) && find_collision.object)
		{
			list = list->next;
			continue ;
		}
		norm_angle = dmax(0, cos(vector_angle(&ray.dir, &normal)));
		if (norm_angle)
		{
			collision->color.r = dmin(255, collision->color.r + norm_angle *
			list->light->power * list->light->color_r / 255 * collision->object->color_r / 255);
			collision->color.g = dmin(255, collision->color.g + norm_angle *
			list->light->power * list->light->color_g / 255 * collision->object->color_g / 255);
			collision->color.b = dmin(255, collision->color.b + norm_angle *
			list->light->power * list->light->color_b / 255 * collision->object->color_b / 255);
		}
		list = list->next;
	}
	return (conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b));
}

void			check_ambient(t_env *env, t_collision *collision)
{
	if (collision->color.r < env->light_ambient)
		collision->color.r = get_color_r(env->light_ambient);
	if (collision->color.g < env->light_ambient)
		collision->color.g = get_color_g(env->light_ambient);
	if (collision->color.b < env->light_ambient)
		collision->color.b = get_color_b(env->light_ambient);
}

unsigned int	get_light_color(t_env *env, t_collision *collision)
{
	unsigned int	color;

	collision->color.r = 0;
	collision->color.g = 0;
	collision->color.b = 0;
	color = find_light(env, collision);
	//if (color != 0)
	//printf("light final value: %u\n", find_light(env, collision));
	//check_ambient(env, collision);
	return (conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b));
}
