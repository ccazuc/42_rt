/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:53:29 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 13:13:18 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	reset_window(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->window_height)
	{
		j = -1;
		while (++j < env->window_width)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 0);
	}
}

int		loop_handler(void *data)
{
	t_env	*env;
	int		i;
	int		line_drawn;

	env = data;
	if (env->draw_finished == 1)
		return (0);
	i = -1;
	line_drawn = 0;
	while (++i < env->nb_thread)
		line_drawn += env->thread_list[i].line_drawn;
	draw_progress_bar(env, line_drawn);
	i = -1;
	while (++i < env->nb_thread)
		if (!env->thread_list[i].draw_finished)
			return (0);
	env->draw_finished = 1;
	reset_window(env);
	if (env->fsaa)
		process_fsaa(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img_ptr, 0, 0);
	put_timer(env->render_start, epoch_millis(), "Scene rendered");
	ft_putstr("With ");
	ft_putnbr(env->nb_thread);
	ft_putstr(" thread(s).\n");
	save_image(env);
	return (0);
}
