/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:21:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/31 18:54:02 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		solve_quadratic(t_quadratic *quadratic, double *distance)
{
	double	delta;
	double	quad_a;
	double	t0;
	double	t1;
	double	delta_sq;

	delta = quadratic->b * quadratic->b - 4 * quadratic->a * quadratic->c;
	*distance = 0;
	//printf("a: %f, b: %f, c: %f, delta: %f\n", quadratic->a, quadratic->b, quadratic->c, delta);
	if (delta < 0)
		return (0);
	//printf("delta: %f\n", delta);
	if (delta == 0)
		*distance = -quadratic->b / (2 * quadratic->a);
	else
	{
		quad_a = 2 * quadratic->a;
		delta_sq = sqrt(delta);
		t0 = (-quadratic->b + delta_sq) / quad_a;
		t1 = (-quadratic->b - delta_sq) / quad_a;
		if (t0 < 0.0000001 && t1 < 0.0000001)
			return (0);
		*distance = t0 < t1 ? t0 : t1;
	}
	return (1);
}
