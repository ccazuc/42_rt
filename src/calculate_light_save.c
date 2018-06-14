/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 11:03:58 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_shadow_color(t_env *env, t_collision *collision, t_ray *ray, t_light *light)
{
	t_collision 	find_collision;
	t_ray			new_ray;
	t_color_mask	mask;
	int				collision_found;
//	t_vector		normal;

	new_ray.pos.x = ray->pos.x;
	new_ray.pos.y = ray->pos.y;
	new_ray.pos.z = ray->pos.z;
	new_ray.dir.x = ray->dir.x;
	new_ray.dir.y = ray->dir.y;
	new_ray.dir.z = ray->dir.z;
	//new_ray.pos = ray->pos;
	//new_ray.dir = ray->dir;
	mask.r = 1;
	mask.g = 1;
	mask.b = 1;
	find_collision.object = collision->object;
	collision_found = 0;
	while (check_collision(env, &new_ray, &find_collision, find_collision.object) && find_collision.distance < vector_distance(&light->pos, &collision->pos) && find_collision.distance > 0.00001)
	{
//		if (find_collision.object->transparency <= 0)
//			return ;
		mask.r *= find_collision.object->color_r / 255. * .5 /** light->color_r / 255.*/;
		mask.g *= find_collision.object->color_g / 255. * .5 /** light->color_g / 255.*/;
		mask.b *= find_collision.object->color_b / 255. * .5 /** light->color_b / 255.*/;
		/*get_normal_vector(&normal, find_collision.object, &find_collision);
		vector_normalize(&normal);
		mask.r *= dmax(0, cos(vector_angle(&normal, &ray->dir))) * light->power / 5 * .1 * find_collision.object->color_r / 255.;
		mask.g *= dmax(0, cos(vector_angle(&normal, &ray->dir))) * light->power / 5 * .1 * find_collision.object->color_g / 255.;
		mask.b *= dmax(0, cos(vector_angle(&normal, &ray->dir))) * light->power / 5 * .1 * find_collision.object->color_b / 255.;*/
		new_ray.pos.x = find_collision.pos.x;
		new_ray.pos.y = find_collision.pos.y;
		new_ray.pos.z = find_collision.pos.z;
		collision_found = 1;
	}
	if (!collision_found)
		return (0);
	collision->color.r = mask.r * light->color_r / 255. + collision->color.r;
	collision->color.g = mask.g * light->color_g / 255. + collision->color.g;
	collision->color.b = mask.b * light->color_b / 255. + collision->color.b;
	return (1);
}

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
	/*	if (get_shadow_color(env, collision, &ray, list->light))
		{
			list = list->next;
			continue ;
		}*/
		if (check_collision(env, &ray, &find_collision, collision->object) && find_collision.object
		&& find_collision.distance < vector_distance(&list->light->pos, &collision->pos) && find_collision.distance > 0.0001)
		{
		//	printf("\n\n\n\nfind_collision: pos.x: %f, pos.y: %f, pos.z: %f, dir.x: %f, dir.y: %f, dir.z: %f, object: %p, distance: %f\n", find_collision.pos.x, find_collision.pos.y, find_collision.pos.z, find_collision.dir.x, find_collision.dir.y, find_collision.dir.z, find_collision.object, find_collision.distance);
			//printf("find_light pos.x: %f, pos.y: %f, pos.z: %f, dir.x: %f, dir.y: %f, dir.z: %f\n", ray.pos.x, ray.pos.y, ray.pos.z, ray.dir.x, ray.dir.y, ray.dir.z);
			get_shadow_color(env, collision, &ray, list->light);
			list = list->next;
			continue ;
		}
		norm_angle = dmax(0, cos(vector_angle(&ray.dir, normal)));
		if (norm_angle)
		{
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

unsigned int	get_light_color(t_env *env, t_collision *collision, int recursion)
{
	t_vector		normal;

	if (recursion > REFLECTION_DEPTH)
		return (0);
	get_normal_vector(&normal, collision->object, collision);
	vector_normalize(&normal);
	collision->color.r = 0;
	collision->color.g = 0;
	collision->color.b = 0;
	find_light(env, collision, &normal);
	check_reflection(env, collision, &normal, recursion);
	light_transparency(env, collision, recursion);
	//if (color != 0)
	//printf("light final value: %u\n", find_light(env, collision));
	//check_ambient(env, collision);
	return (conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b));
}
