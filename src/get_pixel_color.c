/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:48:47 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/31 17:11:59 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	get_pixel_color(t_env *env, t_ray *ray, int recursion)
{
	unsigned int	color;
	t_collision		collision;

	color = BG_COLOR;
	if (recursion > REFLECTION_DEPTH)
		return (color);
	collision.color.r = 0;
	collision.color.g = 0;
	collision.color.b = 0;
	if (check_collision(env, ray, &collision) && collision.object)
	{
	//	printf("collision found in pixel color\n");
		color = conv_rgb_to_int(collision.object->color_r, collision.object->color_g, collision.object->color_b);
		//printf("pre light color x: %f, y: %f, z: %f\n", collision.pos.x, collision.pos.y, collision.pos.z);
		color = get_light_color(env, &collision, recursion);
	}
	//printf("get pixel color end\n");
	return (color);
}
