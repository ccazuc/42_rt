/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:29:17 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 14:49:08 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		vector_rotate(t_vector *vector, t_vector *angle)
{
	vector_rotate_x(vector, ft_toradians(angle->x));
	vector_rotate_y(vector, ft_toradians(angle->y));
	vector_rotate_z(vector, ft_toradians(angle->z));
}

void		vector_unrotate(t_vector *vector, t_vector *angle)
{
	vector_rotate_x(vector, -ft_toradians(angle->x));
	vector_rotate_y(vector, -ft_toradians(angle->y));
	vector_rotate_z(vector, -ft_toradians(angle->z));
}

void		vector_rotate_x(t_vector *vector, float angle)
{
	double		tmp_y;

	tmp_y = vector->y;
	vector->y = vector->y * cos(angle) - vector->z * sin(angle);
	vector->z = tmp_y * sin(angle) + vector->z * cos(angle);
}

void		vector_rotate_y(t_vector *vector, float angle)
{
	double		tmp_x;

	tmp_x = vector->x;
	vector->x = vector->x * cos(angle) + vector->z * sin(angle);
	vector->z = -tmp_x * sin(angle) + vector->z * cos(angle);
}

void		vector_rotate_z(t_vector *vector, float angle)
{
	double		tmp_x;

	tmp_x = vector->x;
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = tmp_x * sin(angle) + vector->y * cos(angle);
}
