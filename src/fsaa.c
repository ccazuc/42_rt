#include "rt.h"

static int	color_add_fsaa(int c1, int c2, int factor)
{
	int	r;
	int	g;
	int	b;

	r = get_color_r(c1) + get_color_r(c2) / factor;
	if (r > 255)
		r = 255;
	g = get_color_g(c1) + get_color_g(c2) / factor;
	if (g > 255)
		g = 255;
	b = get_color_b(c1) + get_color_b(c2) / factor;
	if (b > 255)
		b = 255;
	return ((r << 16) + (g << 8) + b);
}

static unsigned int handle_overflow(unsigned int w, unsigned int n, unsigned int e, unsigned int s)
{
	unsigned int	res;

	res = 0;
	res = color_add_fsaa(res, w, 4);
	res = color_add_fsaa(res, n, 4);
	res = color_add_fsaa(res, e, 4);
	res = color_add_fsaa(res, s, 4);
	return (res);
}

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
	if (x < 2 * env->window_width - 1)
		e = get_pixel(env, env->fsaa_img, 2 * x + 1, 2 * y);
	else
		e = 0;
	if (y < 2 * env->window_height - 1)
		s = get_pixel(env, env->fsaa_img, 2 * x, 2 * y + 1);
	else
		s = 0;	
	return (handle_overflow(w, n, e, s));
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
