/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:38:45 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:52:12 by kehuang          ###   ########.fr       */
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

static void	fill_img_data(t_env *env, t_png_datas *img_datas)
{
	long	i;
	long	j;

	i = -1;
	while (++i < env->window_height)
	{
		j = -1;
		while (++j < env->window_width)
		{
			img_datas->row[j * 3] = env->mlx_img_data[(i * env->window_width
					+ j) * env->bpp / 8 + 2];
			img_datas->row[j * 3 + 1] = env->mlx_img_data[(i * env->window_width
					+ j) * env->bpp / 8 + 1];
			img_datas->row[j * 3 + 2] = env->mlx_img_data[(i * env->window_width
					+ j) * env->bpp / 8];
		}
		png_write_row(img_datas->png_ptr, img_datas->row);
	}
	png_write_end(img_datas->png_ptr, NULL);
}

static void	free_img_datas(t_png_datas *img_datas)
{
	free(img_datas->file_name);
	if (img_datas->fp)
		fclose(img_datas->fp);
	if (img_datas->info_ptr)
		png_free_data(img_datas->png_ptr, img_datas->info_ptr,
				PNG_FREE_ALL, -1);
	if (img_datas->png_ptr)
		png_destroy_write_struct(&img_datas->png_ptr, &img_datas->info_ptr);
	if (img_datas->row)
		free(img_datas->row);
}

static char	alloc_png_datas(t_png_datas *img_datas)
{
	if (!img_datas->fp)
	{
		ft_putstr("Could not open file.\n");
		return (0);
	}
	img_datas->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
			NULL, NULL, NULL);
	if (!img_datas->png_ptr)
	{
		ft_putstr("Failed to allocate write structure.\n");
		return (0);
	}
	img_datas->info_ptr = png_create_info_struct(img_datas->png_ptr);
	if (!img_datas->info_ptr)
	{
		ft_putstr("Failed to allocate info structure.\n");
		return (0);
	}
	if (setjmp(png_jmpbuf(img_datas->png_ptr)))
	{
		ft_putstr("Error during png creation.\n");
		return (0);
	}
	return (1);
}

void		save_image(t_env *env)
{
	t_png_datas	img_datas;

	img_datas.file_name = get_file_name();
	img_datas.fp = fopen(img_datas.file_name, "wb");
	alloc_png_datas(&img_datas);
	png_init_io(img_datas.png_ptr, img_datas.fp);
	png_set_IHDR(img_datas.png_ptr, img_datas.info_ptr, env->window_width,
			env->window_height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	img_datas.title_text.compression = PNG_TEXT_COMPRESSION_NONE;
	img_datas.title_text.key = "Raytracer";
	img_datas.title_text.text = img_datas.file_name;
	png_set_text(img_datas.png_ptr, img_datas.info_ptr,
			&img_datas.title_text, 1);
	png_write_info(img_datas.png_ptr, img_datas.info_ptr);
	if (!(img_datas.row = malloc(3 * env->window_width * sizeof(png_byte))))
	{
		ft_putstr("Out of memory, failed to allocate data buffer.\n");
		return ;
	}
	fill_img_data(env, &img_datas);
	free_img_datas(&img_datas);
}
