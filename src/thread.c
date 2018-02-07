#include "rt.h"

void	thread_loop(t_worker *worker)
{
	int		j;
	t_ray	*ray;

	ray = create_camera_ray(worker->env);
	worker->current_index = worker->start - 1;
	while (++worker->current_index < worker->end)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			fill_ray(worker->env, ray, j, worker->current_index);
			pixel_put(worker->env, j, worker->current_index, get_pixel_color(worker->env, ray, 0, NULL));
		}
		++worker->line_drawn;
	}
	free(ray);
	worker->draw_finished = 1;
	//printf("Thread %d draw finished\n", worker->id);
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

	if (!(env->thread_list = malloc(env->nb_thread * sizeof(*env->thread_list))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	i = -1;
	while (++i < env->nb_thread)
	{
		env->thread_list[i].env = env;
		env->thread_list[i].start = i * WINDOW_HEIGHT / env->nb_thread;
		env->thread_list[i].end = (i + 1) * WINDOW_HEIGHT / env->nb_thread;
		//printf("start: %d, end: %d, height: %d\n", env->thread_list[i].start, env->thread_list[i].end, WINDOW_HEIGHT);
		env->thread_list[i].draw_finished = 0;
		env->thread_list[i].id = i;
		env->thread_list[i].line_drawn = 0;
		pthread_create(&env->thread_list[i].thread, NULL, thread_run, &env->thread_list[i]);
	}
	i = -1;
	/*while (++i < env->nb_thread)
		pthread_join(env->thread_list[i].thread, NULL);*/
}
