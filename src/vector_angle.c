/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:35:23 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/29 10:38:51 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	vector_angle(t_vector *v1, t_vector *v2)
{
	/*double	v1_l;
	double	v2_l;

	if ((v1_l = vector_length(v1)) == 0.)
		v1_l = 1;
	if ((v2_l = vector_length(v2)) == 0.)
		v2_l = 1;
	return (acos((dot_product(v1, v2)) /
	(v1_l * v2_l)));*/
	return (acos(dot_product(v1, v2)) /
	(vector_length(v1) * vector_length(v2)));
}
