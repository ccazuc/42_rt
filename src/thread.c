/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:24 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/22 10:03:31 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	thread_loop(t_worker *worker)
{
	int				j;
	t_ray			*ray;
	unsigned int	color;

	ray = create_camera_ray(worker->env);
	worker->current_index = worker->start - 1;
	while (++worker->current_index < worker->end)
	{
		j = -1;
		while (++j < worker->env->window_width)
		{
			fill_ray(worker->env, ray, j, worker->current_index);
			color = get_pixel_color(worker->env, ray, 0, NULL);
			if (worker->env->sepia_filter)
				color = get_sepia_color(color);
			if (worker->env->grayscale_filter)
				color = get_grayscale_color(color);
			pixel_put(worker->env, j, worker->current_index, color);
		}
		++worker->line_drawn;
	}
	free(ray);
	worker->draw_finished = 1;
}

void	*thread_run(void *data)
{
	t_worker	*worker;

	worker = data;
	thread_loop(worker);
	return (NULL);
}

void	create_thread(t_env *env)
{
	int	i;

	if (!(env->thread_list = malloc(env->nb_thread
	* sizeof(*env->thread_list))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	i = -1;
	while (++i < env->nb_thread)
	{
		env->thread_list[i].env = env;
		env->thread_list[i].start = i * env->window_height / env->nb_thread;
		env->thread_list[i].end = (i + 1) * env->window_height / env->nb_thread;
		env->thread_list[i].draw_finished = 0;
		env->thread_list[i].id = i;
		env->thread_list[i].line_drawn = 0;
		pthread_create(&env->thread_list[i].thread,
		NULL, thread_run, &env->thread_list[i]);
	}
}

void	free_threads(t_env *env)
{
	free(env->thread_list);
}
