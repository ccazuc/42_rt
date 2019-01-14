/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <lufranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:13:30 by lufranco          #+#    #+#             */
/*   Updated: 2019/01/14 16:13:31 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_sepia_color(int rgb)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	t_color_mask	mask;

	r = get_color_r(rgb);
	g = get_color_g(rgb);
	b = get_color_b(rgb);
	mask.r = dmin(255, r * .393 + g * .769 + b * .189);
	mask.g = dmin(255, r * .349 + g * .686 + b * .168);
	mask.b = dmin(255, r * .272 + g * .534 + b * .131);
	return (conv_rgb_to_int(mask.r, mask.g, mask.b));
}

int		get_grayscale_color(int rgb)
{
	unsigned char	res;

	res = (get_color_r(rgb) + get_color_g(rgb) + get_color_b(rgb)) / 3;
	return (conv_rgb_to_int(res, res, res));
}
