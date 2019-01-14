/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:28:48 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 14:24:49 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		fill_light_data(t_collision *collision, t_light *light,
		double norm_angle)
{
	if (collision->object->is_light)
		return ;
	collision->color.r = dmin(255, collision->color.r + norm_angle
			* light->power / 5. * light->color_r / 255.
			* collision->object->color_r / 255.);
	collision->color.g = dmin(255, collision->color.g + norm_angle
			* light->power / 5. * light->color_g / 255.
			* collision->object->color_g / 255.);
	collision->color.b = dmin(255, collision->color.b + norm_angle
			* light->power / 5. * light->color_b / 255.
			* collision->object->color_b / 255.);
}

static void		init_find_light_loop_datas(t_ray *ray, t_light *light,
		t_collision *collision)
{
	if (light->is_direc && (light->rot.x || light->rot.y || light->rot.z))
	{
		ray->dir.x = -light->rot.x / 10.;
		ray->dir.y = -light->rot.y / 10.;
		ray->dir.z = -light->rot.z / 10.;
	}
	else
	{
		ray->dir.x = light->pos.x - collision->pos.x;
		ray->dir.y = light->pos.y - collision->pos.y;
		ray->dir.z = light->pos.z - collision->pos.z;
	}
	vector_normalize(&ray->dir);
}

static void		calc_light_angle(t_ray *ray, t_vector *normal,
		t_collision *collision, t_light *light)
{
	double	norm_angle;

	norm_angle = dmax(0, cos(vector_angle(&ray->dir, normal)));
	if (norm_angle)
	{
		fill_light_data(collision, light, norm_angle);
		add_specular(collision, normal, &ray->dir);
	}
}

void			find_light(t_env *env, t_collision *collision, t_vector *normal)
{
	t_light_list	*list;
	t_ray			ray;
	t_collision		find_collision;

	list = env->light_list;
	ray.pos = collision->pos;
	while (list)
	{
		init_find_light_loop_datas(&ray, list->light, collision);
		if (check_collision(env, &ray, &find_collision, collision->object)
				&& find_collision.object
				&& find_collision.distance < vector_distance(&list->light->pos,
					&collision->pos) && find_collision.distance > 0.0001)
		{
			get_shadow_color(env, collision, &ray, list->light);
			list = list->next;
			continue ;
		}
		calc_light_angle(&ray, normal, collision, list->light);
		list = list->next;
	}
	collision->color.r = dmin(255, collision->color.r * 255);
	collision->color.g = dmin(255, collision->color.g * 255);
	collision->color.b = dmin(255, collision->color.b * 255);
}
