/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_transparency_shadow.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:47:38 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/21 01:47:11 by kehuang          ###   ########.fr       */
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
		t_collision *hit)
{
	t_color_mask	c;

	c = get_object_color(hit);
	mask->r *= c.r / 255. * hit->object->transparency;
	mask->g *= c.g / 255. * hit->object->transparency;
	mask->b *= c.b / 255. * hit->object->transparency;
}

static	void	update_color(t_collision *collision, t_color_mask *mask,
		t_light *light)
{
	t_color_mask	c;

	c = get_object_color(collision);
	c.r /= 255.0;
	c.g /= 255.0;
	c.b /= 255.0;
	collision->color.r = mask->r * light->color_r / 255.
		* light->power / 5. + c.r;
	collision->color.g = mask->g * light->color_g / 255.
		* light->power / 5. + c.g;
	collision->color.b = mask->b * light->color_b / 255.
		* light->power / 5. + c.b;
}

int				get_shadow_color(t_env *env, t_collision *collision,
		t_ray *ray, t_light *light)
{
	t_collision		hit;
	t_ray			new_ray;
	t_color_mask	mask;
	int				collision_found;

	collision_found = 0;
	init_shadow_color_data(&new_ray, ray, &mask);
	hit.object = collision->object;
	while (check_collision(env, &new_ray, &hit, hit.object)
			&& hit.distance < vector_distance(&light->pos, &collision->pos)
			&& hit.distance > 0.0001)
	{
		if (hit.object->transparency <= 0)
			return (0);
		fill_shadow_data(&mask, &hit);
		new_ray.pos = hit.pos;
		collision_found = 1;
	}
	if (!collision_found)
		return (0);
	update_color(collision, &mask, light);
	return (1);
}
