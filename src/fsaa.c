/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsaa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:15:01 by ccazuc            #+#    #+#             */
/*   Updated: 2018/11/29 18:17:21 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			color_add_fsaa(int c1, int c2, int factor)
{
	int	r;
	int	g;
	int	b;

	r = get_color_r(c1) + get_color_r(c2) / factor;
	if (r > 255)
		r = 255;
	g = get_color_g(c1) + get_color_g(c2) / factor;
	if (g > 255)
		g = 255;
	b = get_color_b(c1) + get_color_b(c2) / factor;
	if (b > 255)
		b = 255;
	return ((r << 16) + (g << 8) + b);
}

static unsigned int	handle_overflow(unsigned int w,
unsigned int n, unsigned int e, unsigned int s)
{
	unsigned int	res;

	res = 0;
	res = color_add_fsaa(res, w, 4);
	res = color_add_fsaa(res, n, 4);
	res = color_add_fsaa(res, e, 4);
	res = color_add_fsaa(res, s, 4);
	return (res);
}

static unsigned int	get_pixel_at(t_env *env, int x, int y)
{
	unsigned int	w;
	unsigned int	n;
	unsigned int	e;
	unsigned int	s;

	w = get_pixel(env, env->fsaa_img, env->fsaa_factor
	/ 2 * x, env->fsaa_factor / 2 * y);
	n = get_pixel(env, env->fsaa_img, env->fsaa_factor
	/ 2 * x + 1, env->fsaa_factor / 2 * y);
	e = get_pixel(env, env->fsaa_img, env->fsaa_factor
	/ 2 * x, env->fsaa_factor / 2 * y + 1);
	s = get_pixel(env, env->fsaa_img, env->fsaa_factor
	/ 2 * x + 1, env->fsaa_factor / 2 * y + 1);
	return (handle_overflow(w, n, e, s));
}

void				process_fsaa(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->window_height - 1)
	{
		j = -1;
		while (++j < env->window_width - 1)
			pixel_put(env, j, i, get_pixel_at(env, j, i));
	}
}
