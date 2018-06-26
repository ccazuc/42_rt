/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_progress_bar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:57:19 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 12:15:38 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	draw_borders2(t_env *env)
{
	int		i;
	int		j;

	i = env->window_height - 215 * env->window_height / 1080;
	while (++i < env->window_height - 85 * env->window_height / 1080)
	{
		j = env->window_width / 4 - 14;
		while (++j < env->window_width / 4 - 10)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
	i = env->window_height - 215 * env->window_height / 1080;
	while (++i < env->window_height - 85 * env->window_height / 1080)
	{
		j = 3 * env->window_width / 4 + 9;
		while (++j < 3 * env->window_width / 4 + 13)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
}

static void	draw_borders(t_env *env)
{
	int		i;
	int		j;

	i = env->window_height - 215 * env->window_height / 1080;
	while (++i < env->window_height - 210 * env->window_height / 1080)
	{
		j = env->window_width / 4 - 14;
		while (++j < 3 * env->window_width / 4 + 13)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
	i = env->window_height - 89 * env->window_height / 1080;
	while (++i < env->window_height - 84 * env->window_height / 1080)
	{
		j = env->window_width / 4 - 14;
		while (++j < 3 * env->window_width / 4 + 13)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
	draw_borders2(env);
}

void		draw_progress_bar(t_env *env, int line_drawn)
{
	int		i;
	int		j;
	double	ratio;
	int		max_width;

	max_width = env->window_width / 4 + 300;
	if (env->fsaa)
		ratio = line_drawn / (env->window_height * 2.);
	else
		ratio = (double)line_drawn / (double)env->window_height;
	i = env->window_height - 200 * env->window_height / 1080;
	while (++i < env->window_height - 100 * env->window_height / 1080)
	{
		j = env->window_width / 4 - 1;
		while (++j < env->window_width / 4 + ratio * max_width)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i,
			color_factor(16777215, (double)(j - env->window_width / 4 + 150)
			/ (double)max_width));
	}
	draw_borders(env);
}
