#include "rt.h"

static unsigned int	get_pixel_at(t_env *env, int x, int y)
{
	unsigned int	w;
	unsigned int	n;
	unsigned int	e;
	unsigned int	s;

	if (x > 0)
		w = get_pixel(env, env->fsaa_img, 2 * x - 1, 2 * y);
	else
		w = 0;
	if (y > 0)
		n = get_pixel(env, env->fsaa_img, 2 * x, 2 * y - 1);
	else 
		n = 0;
	if (x < env->window_width - 1)
		e = get_pixel(env, env->fsaa_img, 2 * x + 1, 2 * y);
	else
		e = 0;
	if (y < env->window_height - 1)
		s = get_pixel(env, env->fsaa_img, 2 * x, 2 * y + 1);
	return ((w + n + e + s) / 4);
}

void			process_fsaa(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	printf("process fsaa start\n");
	while (++i < env->window_height)
	{
		j = -1;
		while (++j < env->window_width)
			pixel_put(env, j, i, get_pixel_at(env, j, i));
	}
	printf("process fsaa ended\n");
}
