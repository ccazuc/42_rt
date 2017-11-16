/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:21:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 07:29:47 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	solve_quadratic(t_quadratic, double *distance)
{
	double	delta;

	delta = quadratic.b * quadratic.b - 4 * quadratic.a * quadratic.c;
	*distance = 0;
	if (delta < 0)
		return ;
	if (delta == 0)
		*distance = -quadratic.b / (2 * quadratic.a)
	else
		*distance = min((-quadratic.b + sqrt(d)) / (2 * quadratic.a),
		(-quadratic.b - sqrt(d)) / (2 * quadratic.a));
}
