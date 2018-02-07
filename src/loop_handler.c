#include "rt.h"

static void	draw_progress_bar(t_env *env, float percentage)
{
	int		i;
	int		j;

	i = 199;
	while (++i < 400)
	{
		j = WINDOW_WIDTH / 4 - 1;
		while (++j < percentage * 3 * WINDOW_WIDTH / 4)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
}

void	reset_window(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
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
		line_drawn += env->thread_list[i].current_index;
	//printf("line_drawn: %d\n", line_drawn);
	reset_window(env);
	draw_progress_bar(env, line_drawn / WINDOW_HEIGHT);
	i = -1;
	while (++i < env->nb_thread)
		if (!env->thread_list[i].draw_finished)
			return (0);
	env->draw_finished = 1;
	reset_window(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img_ptr, 0, 0);
	put_timer(env->render_start, epoch_millis(), "Scene rendered");
	return (0);
}