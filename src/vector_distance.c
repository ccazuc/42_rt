/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 14:28:13 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 14:21:36 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	vector_distance(t_vector *pos1, t_vector *pos2)
{
	return (sqrt(pow(pos1->x - pos2->x, 2) + pow(pos1->y - pos2->y, 2)
				+ pow(pos1->z - pos2->z, 2)));
}
