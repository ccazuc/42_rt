/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:19:15 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:15:09 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	mul_vec_tri(t_vector const a, t_vector const b)
{
	t_vector	n;

	n.x = a.y * b.z;
	n.y = a.z * b.x;
	n.z = a.x * b.y;
	return (n);
}

static void	get_determinant(t_ray const *ray, t_object const *object,
		t_triangle_collision *tri_coll)
{
	tri_coll->e1 = sub_vector(object->rot, object->pos);
	tri_coll->e2 = sub_vector(object->p3, object->pos);
	tri_coll->p = sub_vector(mul_vec_tri(ray->dir, tri_coll->e2),
			mul_vec_tri(tri_coll->e2, ray->dir));
	tri_coll->det = dot_product(&tri_coll->e1, &tri_coll->p);
}

void	get_triangle_normal(t_vector *vector, t_object *object,
		t_collision *collision)
{
	t_vector	u;
	t_vector	v;
	double		angle;

	u = sub_vector(object->rot, object->pos);
	v = sub_vector(object->p3, object->pos);
	*vector = sub_vector(mul_vec_tri(u, v), mul_vec_tri(v, u));
	angle = vector_angle(vector, &collision->dir) * 180. / M_PI;
	if (angle <= 90)
		*vector = mul_vector(*vector, -1.0f);
}

void	collide_triangle(t_ray *ray, t_object *object,
t_collision *collision, t_object *previous_object)
{
	t_triangle_collision	tri_coll;
	double					factor;

	get_determinant(ray, object, &tri_coll);
	if (tri_coll.det == 0)
		return ;
	tri_coll.det = 1. / tri_coll.det;
	tri_coll.t = sub_vector(ray->pos, object->pos);
	tri_coll.u = dot_product(&tri_coll.t, &tri_coll.p) * tri_coll.det;
	if (tri_coll.u < 0.00001 || tri_coll.u > 1.00001)
		return ;
	tri_coll.q = sub_vector(mul_vec_tri(tri_coll.t, tri_coll.e1),
			mul_vec_tri(tri_coll.e1, tri_coll.t));
	tri_coll.v = dot_product(&ray->dir, &tri_coll.q) * tri_coll.det;
	if (tri_coll.v < 0.00001 || tri_coll.u + tri_coll.v > 1.00001)
		return ;
	factor = dot_product(&tri_coll.e2, &tri_coll.q) * tri_coll.det;
	if (factor >= collision->distance || factor <= 0
			|| (object == previous_object && factor < 0.0001))
		return ;
	collision->pos = add_vector(mul_vector(ray->dir, (float)factor), ray->pos);
	collision->object = object;
	collision->distance = factor;
}
