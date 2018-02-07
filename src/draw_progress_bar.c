#include "rt.h"

static void draw_borders(t_env *env)
{
	int		i;
	int		j;

	i = WINDOW_HEIGHT - 215 * WINDOW_HEIGHT / 1080;
	while (++i < WINDOW_HEIGHT - 210 * WINDOW_HEIGHT / 1080)
	{
		j = WINDOW_WIDTH / 4 - 14;
		while (++j < 3 * WINDOW_WIDTH / 4 + 13)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j , i, 16777215);
	}
	i = WINDOW_HEIGHT - 89 * WINDOW_HEIGHT / 1080;
	while (++i < WINDOW_HEIGHT - 84 * WINDOW_HEIGHT / 1080)
	{
		j = WINDOW_WIDTH / 4 - 14;
		while (++j < 3 * WINDOW_WIDTH / 4 + 13)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
	i = WINDOW_HEIGHT - 215 * WINDOW_HEIGHT / 1080;
	while (++i < WINDOW_HEIGHT - 85 * WINDOW_HEIGHT /1080)
	{
		j = WINDOW_WIDTH / 4 - 14;
		while (++j < WINDOW_WIDTH / 4 - 10)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
	i = WINDOW_HEIGHT - 215 * WINDOW_HEIGHT / 1080;
	while (++i < WINDOW_HEIGHT - 85 * WINDOW_HEIGHT /1080)
	{
		j = 3 * WINDOW_WIDTH / 4 + 9;
		while (++j < 3 * WINDOW_WIDTH / 4 + 13)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, 16777215);
	}
	
}

void		draw_progress_bar(t_env *env, int line_drawn)
{
	int		i;
	int		j;
	int		max_width;

	max_width = WINDOW_WIDTH / 4 + (double)line_drawn / (double)WINDOW_HEIGHT * WINDOW_WIDTH / 2;

	i = WINDOW_HEIGHT - 200 * WINDOW_HEIGHT / 1080;
	while (++i < WINDOW_HEIGHT - 100 * WINDOW_HEIGHT / 1080)
	{
		j = WINDOW_WIDTH / 4 - 1;
		while (++j < max_width)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, j, i, color_factor(16777215, (double)(j - WINDOW_WIDTH / 4 + 150) / (double)max_width));
	}
	draw_borders(env);
}
