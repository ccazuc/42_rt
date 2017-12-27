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

void	*get_normal_vector(t_vector *result, t_object *object, t_collision *collision)
{
	if (object->type == SPHERE)
		get_sphere_normal(result, object, &collision->pos);
	else if (object->type == CYLINDRE)
		get_cylinder_normal(result, object, &collision->pos);
	else if (object->type == CONE)
		get_cone_normal(result, object, &collision->pos);
	else if (object->type == PLANE)
		get_plane_normal(result, object, collision);
}
