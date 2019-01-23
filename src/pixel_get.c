/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:41:42 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/23 21:21:22 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	get_pixel(t_env *env, char *img, int x, int y)
{
	size_t			pos;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	pos = (y * env->window_width * env->fsaa_factor / 2 + x) * env->bpp / 8;
	r = img[pos + 2];
	g = img[pos + 1];
	b = img[pos];
	return (conv_rgb_to_int(r, g, b));
}

void			pixel_put_fsaa(t_env *env, int x, int y, unsigned int color)
{
	size_t			pos;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x < 0 || x >= env->window_width * env->fsaa_factor / 2 || y < 0
			|| y >= env->window_height * env->fsaa_factor / 2)
		return ;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	pos = y * env->window_width * env->fsaa_factor / 2
		* env->bpp / 8 + env->bpp / 8 * x;
	env->fsaa_img[pos] = b;
	env->fsaa_img[pos + 1] = g;
	env->fsaa_img[pos + 2] = r;
}
