/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:25:23 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/23 21:23:48 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	conv_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int				get_color_r(unsigned int color)
{
	return ((color & 0xFF0000) >> 16);
}

int				get_color_g(unsigned int color)
{
	return ((color & 0x00FF00) >> 8);
}

int				get_color_b(unsigned int color)
{
	return (color & 0x0000FF);
}

void			pixel_put(t_env *env, int x, int y, unsigned int color)
{
	size_t			pos;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x < 0 || x >= env->window_width || y < 0
			|| y >= env->window_height)
		return ;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	pos = y * env->window_width * env->bpp / 8 + env->bpp / 8 * x;
	env->mlx_img_data[pos] = b;
	env->mlx_img_data[pos + 1] = g;
	env->mlx_img_data[pos + 2] = r;
}
