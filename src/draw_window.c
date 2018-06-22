/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:52:30 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/22 10:46:51 by ccazuc           ###   ########.fr       */
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

void	render(t_env **env, int i, char should_hook)
{
	env[i]->render_start = epoch_millis();
	create_thread(env[i]);
	if (!should_hook)
		return ;
	if (i == 0)
		mlx_loop_hook(env[i]->mlx_ptr, loop_handler, env);
	mlx_hook(env[i]->mlx_win, 3, 2, key_up_handler, env[i]);
}
