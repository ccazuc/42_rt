/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_factor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:41:43 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 12:41:45 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	color_factor(int color, double factor)
{
	int	result;

	if (factor <= 0)
		return (0);
	result = 0;
	if (get_color_r(color) * factor > 255.)
		result += 0xFF0000;
	else
		result += (int)((get_color_r(color) * factor)) << 16;
	if (get_color_g(color) * factor > 255.)
		result += 0x00FF00;
	else
		result += (int)((get_color_g(color) * factor)) << 8;
	if (get_color_b(color) * factor > 255.)
		result += 0x0000FF;
	else
		result += (int)((get_color_b(color) * factor));
	return (result);
}
