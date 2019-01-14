/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:06:34 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 14:22:00 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		vector_length(t_vector *vector)
{
	return (sqrt((vector->x * vector->x) + (vector->y * vector->y)
				+ (vector->z * vector->z)));
}
