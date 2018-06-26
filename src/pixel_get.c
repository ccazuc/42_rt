#include "rt.h"

unsigned int	get_pixel(t_env *env, char *img, int x, int y)
{
	unsigned char	r;	
	unsigned char	g;	
	unsigned char	b;

	r = img[(y * env->window_width * 2 + x) * env->bpp / 8 + 2];
	g = img[(y * env->window_width * 2 + x) * env->bpp / 8 + 1];
	b = img[(y * env->window_width * 2 + x) * env->bpp / 8];
	return (conv_rgb_to_int(r, g, b));
}

void			pixel_put_fsaa(t_env *env, int x, int y, unsigned int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	//printf("pixel_put_fsaa start\n");
	if (x < 0 || x >= env->window_width * 2 || y < 0 ||
	y >= env->window_height * 2)
		return ;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	env->fsaa_img[y * env->window_width * 2 * env->bpp / 8 + env->bpp
		/ 8 * x] = b;
	env->fsaa_img[y * env->window_width * 2 * env->bpp / 8 + env->bpp
		/ 8 * x + 1] = g;
	env->fsaa_img[y * env->window_width * 2 * env->bpp / 8 + env->bpp
		/ 8 * x + 2] = r;
	//printf("pixel_put_fsaa end\n");
}
