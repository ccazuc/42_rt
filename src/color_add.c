/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:46:30 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 12:46:31 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	color_add(int c1, int c2)
{
	int	r;
	int	g;
	int	b;

	r = get_color_r(c1) + get_color_r(c2);
	if (r > 255)
		r = 255;
	g = get_color_g(c1) + get_color_g(c2);
	if (g > 255)
		g = 255;
	b = get_color_b(c1) + get_color_b(c2);
	if (b > 255)
		b = 255;
	return ((r << 16) + (g << 8) + b);
}
