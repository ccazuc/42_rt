/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:53:29 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/22 10:53:29 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		reset_window(t_env *env)
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

static void	draw_finished(t_env *env)
{
	env->draw_finished = 1;
	reset_window(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img_ptr, 0, 0);
	put_timer(env->render_start, epoch_millis(), "Scene rendered");
	ft_putstr("With ");
	ft_putnbr(env->nb_thread);
	ft_putstr(" thread(s).\n");
	save_image(env);
}

static void	check_draw(t_env *env)
{
	int		i;

	i = -1;
	env->draw_finished = 1;
	while (++i < env->nb_thread)
		if (!env->thread_list[i].draw_finished)
		{
			env->draw_finished = 0;
			break ;
		}
	if (env->draw_finished == 1)
		draw_finished(env);
}

int			loop_handler(void *data)
{
	t_env	**env;
	int		i;
	int		line_drawn;
	int		j;

	j = -1;
	env = data;
	while (env[++j])
	{
		if (env[j]->draw_finished == 1)
			continue ;
		i = -1;
		line_drawn = 0;
		while (++i < env[j]->nb_thread)
			line_drawn += env[j]->thread_list[i].line_drawn;
		draw_progress_bar(env[j], line_drawn);
		check_draw(env[j]);
	}
	return (0);
}
