/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:19:15 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/29 13:59:04 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_triangle_normal(t_vector *vector, t_object *object,
t_collision *collision)
{
	t_vector	u;
	t_vector	v;
	double		angle;

	u.x = object->rot.x - object->pos.x; 
	u.y = object->rot.y - object->pos.y; 
	u.z = object->rot.z - object->pos.z; 
	v.x = object->p3.x - object->pos.x;
	v.y = object->p3.y - object->pos.y;
	v.z = object->p3.z - object->pos.z;
	vector->x = u.y * v.z - u.z * v.y;
	vector->y = u.z * v.x - u.x * v.z;
	vector->z = u.x * v.y - u.y * v.x;
	angle = vector_angle(vector, &collision->dir) * 180. / M_PI;
	if (angle <= 90)
	{
		vector->x = -vector->x;
		vector->y = -vector->y;
		vector->z = -vector->z;
	}
}

void	collide_triangle(t_ray *ray, t_object *object,
t_collision *collision, t_object *previous_object)
{
	t_triangle_collision	tri_coll;
	double					factor;

	tri_coll.e1.x = object->rot.x - object->pos.x;
	tri_coll.e1.y = object->rot.y - object->pos.y;
	tri_coll.e1.z = object->rot.z - object->pos.z;
	tri_coll.e2.x = object->p3.x - object->pos.x;
	tri_coll.e2.y = object->p3.y - object->pos.y;
	tri_coll.e2.z = object->p3.z - object->pos.z;
	tri_coll.p.x = ray->dir.y * tri_coll.e2.z - ray->dir.z * tri_coll.e2.y;
	tri_coll.p.y = ray->dir.z * tri_coll.e2.x - ray->dir.x * tri_coll.e2.z;
	tri_coll.p.z = ray->dir.x * tri_coll.e2.y - ray->dir.y * tri_coll.e2.x;
	tri_coll.det = dot_product(&tri_coll.e1, &tri_coll.p);
	printf("p1 | x: %f, y: %f, z: %f\n", object->pos.x, object->pos.y, object->pos.z);
	printf("p2 | x: %f, y: %f, z: %f\n", object->rot.x, object->rot.y, object->rot.z);
	printf("p3 | x: %f, y: %f, z: %f\n", object->p3.x, object->p3.y, object->p3.z);
	//printf("det: %f\n", tri_coll.det);
	if (tri_coll.det == 0)
		return ;
	tri_coll.det = 1. / tri_coll.det;
	tri_coll.t.x = ray->pos.x - object->pos.x;
	tri_coll.t.y = ray->pos.y - object->pos.y;
	tri_coll.t.z = ray->pos.z - object->pos.z;
	tri_coll.u = dot_product(&tri_coll.t, &tri_coll.p) * tri_coll.det;
	printf("u: %f\n", tri_coll.u);
	if (tri_coll.u < 0.0001 || tri_coll.u > 1.0001)
		return ;
	tri_coll.q.x = tri_coll.t.y * tri_coll.e1.z - tri_coll.t.z * tri_coll.e1.y;
	tri_coll.q.y = tri_coll.t.z * tri_coll.e1.x - tri_coll.t.x * tri_coll.e1.z;
	tri_coll.q.z = tri_coll.t.x * tri_coll.e1.y - tri_coll.t.y * tri_coll.e1.x;
	tri_coll.v = dot_product(&ray->dir, &tri_coll.q) * tri_coll.det;
	printf("v: %f\n", tri_coll.v);
	if (tri_coll.v < 0.0001 || tri_coll.v > 1.0001)
		return ;
	factor = dot_product(&tri_coll.e2, &tri_coll.q) * tri_coll.det;
	if (factor >= collision->distance || factor <= 0)
		return ;
	if (object == previous_object && factor < 0.0001)
		return ;
	printf("distance: %f\n", factor);
	collision->pos.x = ray->pos.x + ray->dir.x * factor;
	collision->pos.y = ray->pos.y + ray->dir.y * factor;
	collision->pos.z = ray->pos.z + ray->dir.z * factor;
	collision->object = object;
	collision->distance = factor;
}
