/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:29:17 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 09:07:35 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	vector->z = -tmp_x * sin(angle) + z * cos(angle);
}

void		vector_rotate_z(t_vector *vector, float angle)
{
	double		tmp_x;

	tmp_x = vector->x;
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = tmp_x * sin(angle) + vector->y * cos(angle);
}
