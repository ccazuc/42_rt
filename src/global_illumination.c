/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_illumination.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:25:29 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/16 17:25:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		rnew_vector(void)
{
	static double const	range_max = 50.0;
	static double const	offset = 25.0;
	t_vector			v;

	v.x = (double)(((double)rand() / RAND_MAX * range_max) - offset);
	v.y = (double)(((double)rand() / RAND_MAX * range_max) - offset);
	v.z = (double)(((double)rand() / RAND_MAX * range_max) - offset);
	return (v);
}

static void			find_gi_light(t_env *env, t_collision *collision, t_vector *normal)
{
	t_light_list	*list;
	t_ray			ray;
	t_collision		hit;
	double			norm_angle;

	list = env->light_list;
	ray.pos = collision->pos;
	while (list)
	{
		init_find_light_loop_datas(&ray, list->light, collision);
		if (check_collision(env, &ray, &hit, collision->object) && hit.object
				&& hit.distance < vector_distance(&list->light->pos,
					&collision->pos) && hit.distance > 0.0001)
		{
			list = list->next;
			continue ;
		}
		norm_angle = dmax(0, cos(vector_angle(&ray.dir, normal)));
		if (norm_angle)
			fill_light_data(collision, list->light, norm_angle);
		list = list->next;
	}
	collision->color.r = dmin(255, collision->color.r * 255);
	collision->color.g = dmin(255, collision->color.g * 255);
	collision->color.b = dmin(255, collision->color.b * 255);
}

static unsigned int	get_gi_light_color(t_env *env, t_collision *collision,
		int recursion)
{
	t_vector		normal;

	if (recursion > REFLECTION_DEPTH)
		return (0);
	get_normal_vector(&normal, collision->object, collision);
	vector_normalize(&normal);
	ft_bzero(&collision->color, sizeof(collision->color));
	find_gi_light(env, collision, &normal);
	check_reflection(env, collision, &normal, recursion);
	light_transparency(env, collision, recursion);
	if (collision->object->has_gi == 0)
		return (0);
	return (conv_rgb_to_int(collision->color.r, collision->color.g,
				collision->color.b));
}

static unsigned int	get_gi_pixel_color(t_env *env, t_ray *ray,
		int recursion, t_object *previous_object)
{
	unsigned int	color;
	t_collision		collision;

	color = BG_COLOR;
	if (recursion > REFLECTION_DEPTH)
		return (color);
	ft_bzero(&collision.color, sizeof(collision.color));
	if (check_collision(env, ray, &collision, previous_object)
			&& collision.object)
		color = get_gi_light_color(env, &collision, recursion);
	return (color);
}

t_color_mask		glob_illum(t_env *env,
		t_vector const obj_hit,
		t_vector const obj_normal)
{
	t_ray			ray;
	t_color_mask	gi;
	t_vector		random_angle;
	unsigned int	pxl;
	unsigned int	idx_iter;

	ft_bzero((void *)&gi, sizeof(t_color_mask));
	ray.pos = obj_hit;
	idx_iter = 0;
	while (idx_iter < env->n_sample_ray)
	{
		ray.dir = obj_normal;
		random_angle = rnew_vector();
		vector_rotate(&(ray.dir), &random_angle);
		pxl = get_gi_pixel_color(env, &ray, 0, NULL);
		gi.r += ((pxl >> 16) & 0xff) / 255.0;
		gi.g += ((pxl >> 8) & 0xff) / 255.0;
		gi.b += (pxl & 0xff) / 255.0;
		++idx_iter;
	}
	gi.r = gi.r / env->n_sample_ray * 255.0;
	gi.g = gi.g / env->n_sample_ray * 255.0;
	gi.b = gi.b / env->n_sample_ray * 255.0;
	return (gi);
}
