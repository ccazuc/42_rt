/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:24:43 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/21 01:18:20 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	get_uv_sphere_mapping(t_collision *hit, double *uv)
{
	t_vector	vp;
	t_vector	vn;
	t_vector	ve;
	t_vector	vw;
	double		phi;
	double		theta;

	vp = sub_vector(hit->pos, hit->object->pos);
	vector_normalize(&vp);
	vw = get_x_normal(hit->object->rot);
	vn = get_y_normal(hit->object->rot);
	ve = get_z_normal(hit->object->rot);
	phi = acos(dot_product(&vn, &vp));
	theta = (acos(dot_product(&vp, &vw) / sin(phi))) / (2.0 * M_PI);
    if (dot_product(&ve, &vp) < 0)
		uv[0] = theta;
	else
		uv[0] = 1.0 - theta;
	uv[1] = phi / M_PI;
}

t_color_mask	get_texu_pxl_sphere(t_collision *hit)
{
	t_color_mask	c;
	double			uv[2];
	size_t			idx;
	size_t			x;
	size_t			y;

	get_uv_sphere_mapping(hit, uv);
	x = (size_t)((double)(hit->object->texu.size_x) * uv[0]);
	y = (size_t)((double)(hit->object->texu.size_y) * uv[1]);
	idx = x + y * hit->object->texu.size_x;
	c.r = hit->object->texu.buf[idx + 2];
	c.g = hit->object->texu.buf[idx + 1];
	c.b = hit->object->texu.buf[idx];
	return (c);
}

static void	get_uv_cylinder_mapping(t_collision *hit, double *uv)
{
	t_vector	vp;
	t_vector	vn;
	t_vector	ve;
	t_vector	vw;
	double		vp_len;

	vp = sub_vector(hit->pos, hit->object->pos);
	vw = get_x_normal(hit->object->rot);
	vn = get_y_normal(hit->object->rot);
	ve = get_z_normal(hit->object->rot);
	vp_len = vector_length(&vp);
	vector_normalize(&vp);
	uv[0] = (acos(dot_product(&vp, &vw) / sin(acos(dot_product(&vp, &vn)))))
		/ (2 * M_PI);
	if (dot_product(&vp, &ve) < 0)
		uv[0] = 1.0 - uv[0];
	uv[1] = dot_product(&vp, &vn) * vp_len / (hit->object->texu.scale * .01);
}

t_color_mask	get_texu_pxl_cylinder(t_collision *hit)
{
	t_color_mask	c;
	double			uv[2];
	size_t			idx;
	int				x;
	int				y;

	get_uv_cylinder_mapping(hit, uv);
	x = (int)(hit->object->texu.size_x * uv[0]);
	y = (hit->object->texu.size_y / 2) - (int)uv[1];
	y %= hit->object->texu.size_y;
	if (y < 0)
		y = hit->object->texu.size_y + y;
	idx = x + y * hit->object->texu.size_x;
	c.r = hit->object->texu.buf[idx + 2];
	c.g = hit->object->texu.buf[idx + 1];
	c.b = hit->object->texu.buf[idx];
	return (c);
}
