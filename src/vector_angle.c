/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:35:23 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 10:18:16 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	vector_angle(t_vector *v1, t_vector *v2)
{
	return (acos((dot_product(v1, v2)) / (vector_length(v1) * vector_length(v2))));
}
