/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:52:30 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 11:05:20 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_ray(t_ray *ray,int x, int y)
{
	double	angle_x;
	double	angle_y;

	angle_y = (double)(x - WINDOW_WIDTH / 2.0) / (WINDOW_WIDTH / 2.0) * FOV_X + ft_toradians(env->camera->rot_y);
	angle_x = (double(y - WINDOW_HEIGHT / 2.0) / (WINDOW_HEIGHT / 2.0) * FOV_Y + ft_toradians(env->camera->rot_x);
	vector_rotate_y(ray->dir, angle_x);
	vector_rotate_x(ray->dir, angle_y);
}

void	render(t_env *env)
{
	int			i;
	int			j;
	float		px;
	float		py;
	t_ray		ray;

	i = -1;
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			fill_ray(vector, j, i);	
		}
	}
}
