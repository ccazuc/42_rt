/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:05:37 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/25 15:24:45 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	vector_normalize(t_vector *vector)
{
	double		length;

	length = vector_length(vector);
	if (length == 0)
		return ;
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;
}
