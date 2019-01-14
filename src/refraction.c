/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:17:57 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:46:38 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	get_refraction_dir(t_vector ray_dir, t_vector obj_hit_normal,
		float const obj_ior)
{
	t_vector	refrac_dir;
	float		dot;
	float		eta;
	float		k;

	dot = dot_product(&obj_hit_normal, &ray_dir);
	if (dot < 0.f)
	{
		dot = -dot;
		eta = 1.0f / obj_ior;
	}
	else
		eta = obj_ior;
	k = 1.0f - eta * eta * (1.0f - dot * dot);
	if (k < 0.f)
	{
		eta = 1.0f;
		k = 1.0f - dot * dot;
	}
	refrac_dir = add_vector(mul_vector(ray_dir, eta),
			mul_vector(obj_hit_normal, eta * dot - sqrt(k)));
	vector_normalize(&refrac_dir);
	return (refrac_dir);
}

int				check_refraction(t_env *env, t_collision *collision,
		t_vector *normal, int recursion)
{
	t_ray		ray;
	int			tmp_color;
	int			color_res;

	if (collision->object->refraction == 0)
		return (0);
	ray.dir = get_refraction_dir(collision->dir,
		*normal, collision->object->refraction);
	vector_normalize(&ray.dir);
	ray.pos.x = collision->pos.x;
	ray.pos.y = collision->pos.y;
	ray.pos.z = collision->pos.z;
	tmp_color = get_pixel_color(env, &ray, recursion + 1, collision->object);
	color_res = color_add(color_factor(conv_rgb_to_int(collision->color.r,
					collision->color.g, collision->color.b),
				1. - collision->object->refraction),
			color_factor(tmp_color, collision->object->refraction));
	collision->color.r = get_color_r(color_res);
	collision->color.g = get_color_g(color_res);
	collision->color.b = get_color_b(color_res);
	return (tmp_color);
}
