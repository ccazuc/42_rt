/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:38:45 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 16:05:39 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char	*get_file_name(void)
{
	time_t		now;
	struct tm	tm_now;
	char		file_name[128];

	now = time(NULL);
	localtime_r(&now, &tm_now);
	strftime(file_name, sizeof(file_name),
	"screenshots/render_%Y_%m_%d_%H_%M_%S.png", &tm_now);
	return (ft_strdup(file_name));
}

void setRGB(png_byte *ptr, float val)
{
	int v = (int)(val * 767);
	if (v < 0) v = 0;
	if (v > 767) v = 767;
	int offset = v % 256;

	if (v<256) {
		ptr[0] = 0; ptr[1] = 0; ptr[2] = offset;
	}
	else if (v<512) {
		ptr[0] = 0; ptr[1] = offset; ptr[2] = 255-offset;
	}
	else {
		ptr[0] = offset; ptr[1] = 255-offset; ptr[2] = 0;
	}
}

void		save_image(t_env *env)
{
	//int			fd;
	FILE		*fp;
	char		*file_name;
	png_structp	png_ptr;
	png_infop	info_ptr;

	file_name = get_file_name();
	printf("%s\n", file_name);
	fp = fopen(file_name, "wb");
	if (!fp)
	{
		ft_putstr("Could not open file.\n");
		return ;
	}
	/*fd = open(file_name, O_WRONLY | O_CREAT, S_IRUSR| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		ft_putstr("Failed to open file.\n");
		return ;
	}*/
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		ft_putstr("Failed to allocate write structure.\n");
		return ;
	}
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		ft_putstr("Failed to allocate info structure.\n");
		return ;
	}
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		ft_putstr("Error during png creation.\n");
		return ;
	}
	png_init_io(png_ptr, fp);
	png_set_IHDR(png_ptr, info_ptr, env->window_width, env->window_height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	png_text title_text;
	title_text.compression = PNG_TEXT_COMPRESSION_NONE;
	title_text.key = "Raytracer";
	title_text.text = file_name;
	png_set_text(png_ptr, info_ptr, &title_text, 1);
	png_write_info(png_ptr, info_ptr);
	//png_bytep row[env->window_height];
	png_bytep row;
	if (!(row = malloc(3 * env->window_width * sizeof(png_byte))))
	{
		ft_putstr("Out of memory, failed to allocate data buffer.\n");
		return ;
	}
	//row = malloc(env->window_height * sizeof(png_byte));
	long		i;
	long		j;

	i = -1;
	/*while (++i < env->window_width * env->window_height * env->bpp / 8)
	{
		row[i % (env->window_width * env->bpp / 8)] = env->mlx_img_data[i];
		if (i % (env->window_width * env->bpp / 8) == 0)
			png_write_row(png_ptr, row);
	}*/
	while (++i < env->window_height)
	{
		j = 0;
		while (j < env->window_width)
		{
			/*row[j * 3] = env->mlx_img_data[i * env->window_width + j];
			row[j * 3 + 1] = env->mlx_img_data[i * env->window_width + j] << 8;
			row[j * 3 + 2] = env->mlx_img_data[i * env->window_width + j] << 16;*/
			row[j * 3] = env->mlx_img_data[(i * env->window_width + j) * env->bpp / 8 + 2];
			row[j * 3 + 1] = env->mlx_img_data[(i * env->window_width + j ) * env->bpp / 8 + 1];
			row[j * 3 + 2] = env->mlx_img_data[(i * env->window_width + j) * env->bpp / 8 ];

			j++;
		}
		png_write_row(png_ptr, row);
	}
	/*while (++i < env->window_height)
	{
		row[i] = (png_bytep)env->mlx_img_data + i * env->window_width * 4;
	}*/
	//png_write_image(png_ptr, row);
	//png_write_png (png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
	png_write_end(png_ptr, NULL);
	printf("Png created.\n");
	//printf("fd: %d\n", fp);
	free(file_name);
	(void)env;
}
