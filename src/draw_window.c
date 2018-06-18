/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:52:30 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 12:34:45 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_ray(t_env *env, t_ray *ray, int x, int y)
{
	ray->dir.x = (2 * (x + 0.5) /
	env->window_width - 1) * tan(FOV_X / 2 * M_PI /
	180) * (env->window_width / env->window_height) +
	ft_toradians(env->camera->rot.y);
	ray->dir.y = (1 - 2 * (y + 0.5) /
	env->window_height) * tan(FOV_Y / 2 * M_PI /
	180) + ft_toradians(env->camera->rot.x);
	ray->dir.z = 1;
	vector_normalize(&ray->dir);
}

void	render(t_env *env)
{
	env->render_start = epoch_millis();
	create_thread(env);
	mlx_loop_hook(env->mlx_ptr, loop_handler, env);
	mlx_hook(env->mlx_win, 3, 2, key_up_handler, env);
	mlx_loop(env->mlx_ptr);
}
