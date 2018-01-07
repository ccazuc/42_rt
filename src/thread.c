#include "rt.h"

void	thread_loop(t_worker *worker)
{
	int		i;
	int		j;
	t_ray	ray;

	ray = create_camera_ray(env);
	i = worker->start - 1;
	while (++i < worker->end)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			fill_ray(worker->env, ray, j, i);
			pixel_put(env, j, i, get_pixel_color(env, ray));
		}
		worker->current_line = i;
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
