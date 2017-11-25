/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:48:47 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/25 15:40:19 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	get_pixel_color(t_env *env, t_ray *ray)
{
	unsigned int	color;
	t_object		*collided;

	color = BG_COLOR;
	//printf("Ray | x: %d, y: %d, dir_x: %f, dir_y: %f, dir_z: %f\n", j, i, ray->dir->x, ray->dir->y, ray->dir->z);
	if (check_collision(env, ray, &collided))
	{
	//	printf("Collision found x: %d, y: %d\n", j, i);
		color = conv_rgb_to_int(collided->color_r, collided->color_g, collided->color_b);
		//color = get_light_color( 
	}
	//pixel_put(env, j, i, conv_rgb_to_int((int)(ray->dir->x * 255), (int)(ray->dir->y * 255), (int)(ray->dir->z * 255)));
	return (color);
}
