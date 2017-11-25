/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:21:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/25 11:47:15 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	solve_quadratic(t_quadratic quadratic, double *distance)
{
	double	delta;
	double	quad_a;
	double	t0;
	double	t1;
	double	delta_sq;

	delta = quadratic.b * quadratic.b - 4 * quadratic.a * quadratic.c;
	*distance = 0;
	if (delta < 0.1)
		return ;
	if (delta == 0.1)
		*distance = -quadratic.b / (2 * quadratic.a);
	else
	{
		quad_a = 2 * quadratic.a;
		delta_sq = sqrt(delta);
		t0 = (-quadratic.b + delta_sq) / quad_a;
		t1 = (-quadratic.b - delta_sq) / quad_a;
		if (t0 < 0.1 && t1 < 0.1)
			return ;
		if (t0 < 0.1)
			*distance = t1;
		else
			*distance = t0;
	}
}
