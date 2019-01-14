/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_transparency_shadow.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:47:38 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 14:25:26 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_shadow_color_data(t_ray *new_ray, t_ray *ray,
		t_color_mask *mask)
{
	new_ray->pos = ray->pos;
	new_ray->dir = ray->dir;
	mask->r = 1;
	mask->g = 1;
	mask->b = 1;
}

static void		fill_shadow_data(t_color_mask *mask,
		t_collision *find_collision)
{
	mask->r *= find_collision->object->color_r / 255.
		* find_collision->object->transparency;
	mask->g *= find_collision->object->color_g / 255.
		* find_collision->object->transparency;
	mask->b *= find_collision->object->color_b / 255.
		* find_collision->object->transparency;
}

static	void	update_color(t_collision *collision, t_color_mask *mask,
		t_light *light)
{
	collision->color.r = mask->r * light->color_r / 255.
		* light->power / 5. + collision->color.r;
	collision->color.g = mask->g * light->color_g / 255.
		* light->power / 5. + collision->color.g;
	collision->color.b = mask->b * light->color_b / 255.
		* light->power / 5. + collision->color.b;
}

int				get_shadow_color(t_env *env, t_collision *collision,
		t_ray *ray, t_light *light)
{
	t_collision		find_collision;
	t_ray			new_ray;
	t_color_mask	mask;
	int				collision_found;

	collision_found = 0;
	init_shadow_color_data(&new_ray, ray, &mask);
	find_collision.object = collision->object;
	while (check_collision(env, &new_ray, &find_collision,
				find_collision.object)
			&& find_collision.distance < vector_distance(&light->pos, &collision->pos)
			&& find_collision.distance > 0.0001)
	{
		if (find_collision.object->transparency <= 0
				|| find_collision.object->is_light)
			return (0);
		fill_shadow_data(&mask, &find_collision);
		new_ray.pos = find_collision.pos;
		collision_found = 1;
	}
	if (!collision_found)
		return (0);
	update_color(collision, &mask, light);
	return (1);
}
