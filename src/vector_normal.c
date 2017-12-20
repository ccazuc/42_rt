/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:54:43 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 12:02:05 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*get_normal_vector(t_object *object, t_collision *collision)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(object, &collision->pos));
	if (object->type == CYLINDRE)
		return (get_cylinder_normal(object, &collision->pos));
	if (object->type == CONE)
		return (get_cone_normal(object, &collision->pos));
	if (object->type == PLANE)
		return (get_plane_normal(object, collision));
	return (NULL);
}
