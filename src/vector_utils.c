/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:17:51 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:45:30 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	add_vector(t_vector const a, t_vector const b)
{
	t_vector	n;

	n.x = a.x + b.x;
	n.y = a.y + b.y;
	n.z = a.z + b.z;
	return (n);
}

t_vector	sub_vector(t_vector const a, t_vector const b)
{
	t_vector	n;

	n.x = a.x - b.x;
	n.y = a.y - b.y;
	n.z = a.z - b.z;
	return (n);
}

t_vector	mul_vector(t_vector const a, float const b)
{
	t_vector	n;

	n.x = a.x * b;
	n.y = a.y * b;
	n.z = a.z * b;
	return (n);
}
