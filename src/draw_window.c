/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:52:30 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 10:55:25 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_ray(t_env *env, t_ray *ray, int x, int y)
{
	//double	angle_x;
	//double	angle_y;

	env = NULL;
	//angle_y = (double)(x - WINDOW_WIDTH / 2.0) / (double)(WINDOW_WIDTH / 2.0) * ft_toradians(FOV_X / 2.) + ft_toradians(env->camera->rot.y);
	//angle_x = (double)(y - WINDOW_HEIGHT / 2.0) / (double)(WINDOW_HEIGHT / 2.0) * -ft_toradians(FOV_Y / 2.) + ft_toradians(env->camera->rot.x);
	//printf("x: %d, y: %d, angle_y: %f, angle_x: %f\n", x, y, angle_y, angle_x);
	//ray->dir->x = sin(angle_y);
	//ray->dir->y = sin(angle_x);
	//ray->dir->z = cos(angle_x) * cos(angle_y);
	ray->dir->x = (2 * (x + 0.5) / WINDOW_WIDTH - 1) * tan(FOV_X / 2 * M_PI / 180) * (WINDOW_WIDTH / WINDOW_HEIGHT);
	ray->dir->y = (1 - 2 * (y + 0.5) / WINDOW_HEIGHT) * tan(FOV_Y / 2 * M_PI / 180);
	ray->dir->z = 1;
	//vector_rotate(ray->dir, env->camera->rot);
	vector_normalize(ray->dir);
	//printf("dir_x: %f, dir_y: %f, dir_z: %f\n", ray->dir->x, ray->dir->y, ray->dir->z);
}

void	render(t_env *env)
{
	int			i;
	int			j;
	t_ray		*ray;

	i = -1;
	ray = create_camera_ray(env);
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			fill_ray(env, ray, j, i);
			pixel_put(env, j, i, get_pixel_color(env, ray));
			//pixel_put(env, j, i, conv_rgb_to_int((int)(255 * ft_math_dabs(ray->dir->x)), (int)(255 * ft_math_dabs(ray->dir->y)), (int)(255 * ft_math_dabs(ray->dir->z))));
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img_ptr, 0, 0);
	mlx_loop(env->mlx_ptr);
}
