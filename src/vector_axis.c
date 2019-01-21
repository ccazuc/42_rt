/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:18:09 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/21 01:18:29 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		get_x_normal(t_vector rot)
{
	t_vector	n;

	n.x = -1.0;
	n.y = 0.0;
	n.z = 0.0;
	vector_rotate(&n, &rot);
	return (n);
}

t_vector		get_y_normal(t_vector rot)
{
	t_vector	n;

	n.x = 0.0;
	n.y = 1.0;
	n.z = 0.0;
	vector_rotate(&n, &rot);
	return (n);
}

t_vector		get_z_normal(t_vector rot)
{
	t_vector	n;

	n.x = 0.0;
	n.y = 0.0;
	n.z = 1.0;
	vector_rotate(&n, &rot);
	return (n);
}
