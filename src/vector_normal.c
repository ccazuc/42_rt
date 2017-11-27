/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:54:43 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 15:15:39 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*get_normal_vector(t_object *object, t_vector *pos)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(object, pos));
	if (object->type == CYLINDRE)
		return (get_cylinder_normal(object, pos));
	return (NULL);
}
