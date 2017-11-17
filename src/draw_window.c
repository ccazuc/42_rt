/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:52:30 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 13:59:07 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_ray(t_env *env, t_ray *ray, int x, int y)
{
	double	angle_x;
	double	angle_y;

	angle_y = (double)(x - WINDOW_WIDTH / 2.0) / (double)(WINDOW_WIDTH / 2.0) * ft_toradians(FOV_X) + ft_toradians(env->camera->rot_y);
	angle_x = (double)(y - WINDOW_HEIGHT / 2.0) / (double)(WINDOW_HEIGHT / 2.0) * ft_toradians(FOV_Y) + ft_toradians(env->camera->rot_x);
	//printf("x: %d, y: %d, angle_y: %f, angle_x: %f\n", x, y, angle_y, angle_x);
	ray->dir->x = sin(angle_y);
	ray->dir->y = sin(angle_x);
	ray->dir->z = cos(angle_x) * cos(angle_y);
	//vector_rotate_x(ray->dir, angle_y);
	//vector_rotate_y(ray->dir, angle_x);
	//printf("dir_x: %f, dir_y: %f, dir_z: %f\n", ray->dir->x, ray->dir->y, ray->dir->z);
}

void	render(t_env *env)
{
	int			i;
	int			j;
	t_ray		*ray;
	t_object	*collided;

	i = -1;
	ray = create_camera_ray(env);
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			ray->dir->x = 0;
			ray->dir->y = 0;
			ray->dir->z = -1;
			fill_ray(env, ray, j, i);
			//printf("Ray | x: %d, y: %d, dir_x: %f, dir_y: %f, dir_z: %f\n", j, i, ray->dir->x, ray->dir->y, ray->dir->z);
			if (check_collision(env, ray, &collided))
			{
				printf("Collision found x: %d, y: %d\n", j, i);
				pixel_put(env, j, i, conv_rgb_to_int(collided->color_r, collided->color_g, collided->color_b));
			}
			//pixel_put(env, j, i, conv_rgb_to_int((int)(ray->dir->x * 255), (int)(ray->dir->y * 255), (int)(ray->dir->z * 255)));
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img_ptr, 0, 0);
	mlx_loop(env->mlx_ptr);
}
