/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_transparency_shadow.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:47:38 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 13:39:19 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_shadow_color_data(t_ray *new_ray, t_ray *ray,
t_color_mask *mask, int *collision_found)
{
	new_ray->pos = ray->pos;
	new_ray->dir = ray->dir;
	mask->r = 1;
	mask->g = 1;
	mask->b = 1;
	*collision_found = 0;
}

static void		fill_shadow_data(t_color_mask *mask,
t_collision *find_collision, t_light *light)
{
	mask->r *= find_collision->object->color_r / 255. *
	find_collision->object->transparency * light->color_r / 255.;
	mask->g *= find_collision->object->color_g / 255. *
	find_collision->object->transparency * light->color_g / 255.;
	mask->b *= find_collision->object->color_b / 255. *
	find_collision->object->transparency * light->color_b / 255.;
}

int				get_shadow_color(t_env *env, t_collision *collision,
t_ray *ray, t_light *light)
{
	t_collision		find_collision;
	t_ray			new_ray;
	t_color_mask	mask;
	int				collision_found;

	init_shadow_color_data(&new_ray, ray, &mask, &collision_found);
	find_collision.object = collision->object;
	while (check_collision(env, &new_ray, &find_collision,
	find_collision.object)
	&& find_collision.distance < vector_distance(&light->pos, &collision->pos)
	&& find_collision.distance > 0.00001)
	{
		fill_shadow_data(&mask, &find_collision, light);
		new_ray.pos = find_collision.pos;
		collision_found = 1;
	}
	if (!collision_found)
		return (0);
	collision->color.r = mask.r * light->color_r / 255. + collision->color.r;
	collision->color.g = mask.g * light->color_g / 255. + collision->color.g;
	collision->color.b = mask.b * light->color_b / 255. + collision->color.b;
	return (1);
}
