/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 15:25:37 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	find_light(t_env *env, t_collision *collision, t_vector *normal)
{
	t_light_list	*list;
	t_ray			ray;
	t_collision		find_collision;
	double			norm_angle;

	list = env->light_list;
	ray.pos.x = collision->pos.x;
	ray.pos.y = collision->pos.y;
	ray.pos.z = collision->pos.z;
	while (list)
	{
		ray.dir.x = list->light->pos.x - collision->pos.x;
		ray.dir.y = list->light->pos.y - collision->pos.y;
		ray.dir.z = list->light->pos.z - collision->pos.z;
		vector_normalize(&ray.dir);
		//printf("collision pos.x: %f, pos.y: %f, pos.z: %f\nray dir.x: %f, dir.y: %f, dir.z: %f\nnorm dir.x: %f, dir.y: %f, dir.z: %f\n\n", collision->pos.x, collision->pos.y, collision->pos.z, ray.dir.x, ray.dir.y, ray.dir.z, normal.x, normal.y, normal.z);
		if (check_collision(env, &ray, &find_collision) && find_collision.object
		&& find_collision.distance < vector_distance(&list->light->pos, &collision->pos))
		{
			//printf("object: %p, collision_distance: %f, vector_distance: %f\n", find_collision.object, find_collision.distance, vector_distance(&list->light->pos, &collision->pos));
			list = list->next;
			continue ;
		}
		norm_angle = dmax(0, cos(vector_angle(&ray.dir, normal)));
		//printf("ray.dir.x: %f, ray.dir.y: %f, ray.dir.z: %f, normal.x: %f, normal.y: %f, normal.z: %f, norm_angle: %f, vector_angle: %f, cos: %f\n", ray.dir.x, ray.dir.y, ray.dir.z, normal.x, normal.y, normal.z, norm_angle, vector_angle(&ray.dir, &normal), cos(vector_angle(&ray.dir, &normal)));
		if (norm_angle)
		{
			//printf("angle: %f\n", norm_angle);
			collision->color.r = dmin(255, collision->color.r + norm_angle *
			list->light->power / 5. * list->light->color_r / 255. * collision->object->color_r / 255.);
			collision->color.g = dmin(255, collision->color.g + norm_angle *
			list->light->power / 5. * list->light->color_g / 255. * collision->object->color_g / 255.);
			collision->color.b = dmin(255, collision->color.b + norm_angle *
			list->light->power / 5. * list->light->color_b / 255. * collision->object->color_b / 255.);
			add_specular(collision, normal, &ray.dir);
		}
		list = list->next;
	}	
	collision->color.r = dmin(255, collision->color.r * 255);
	collision->color.g = dmin(255, collision->color.g * 255);
	collision->color.b = dmin(255, collision->color.b * 255);
}

void			check_ambient(t_env *env, t_collision *collision)
{
	if (collision->color.r < get_color_r(env->light_ambient))
		collision->color.r = dmin(255, collision->color.r + get_color_r(env->light_ambient) * .2);
	if (collision->color.g < get_color_g(env->light_ambient))
		collision->color.g = dmin(255, collision->color.g + get_color_g(env->light_ambient) * .2);
	if (collision->color.b < get_color_b(env->light_ambient))
		collision->color.b = dmin(255, collision->color.b + get_color_b(env->light_ambient) * .2);
}

unsigned int	get_light_color(t_env *env, t_collision *collision)
{
	t_vector		normal;

	get_normal_vector(&normal, collision->object, collision);
	vector_normalize(&normal);
	collision->color.r = 0;
	collision->color.g = 0;
	collision->color.b = 0;
	find_light(env, collision, &normal);
	//if (color != 0)
	//printf("light final value: %u\n", find_light(env, collision));
	//check_ambient(env, collision);
	return (conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b));
}
