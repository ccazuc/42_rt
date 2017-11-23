/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:15:05 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 08:38:29 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	*create_camera_ray(t_env *env)
{
	t_ray	*result;

	if (!(result = malloc(sizeof(*result))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	if (!(result->dir = malloc(sizeof(*result->dir))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	if (!(result->pos = malloc(sizeof(*result->pos))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	result->pos->x = env->camera->pos_x;
	result->pos->y = env->camera->pos_y;
	result->pos->z = env->camera->pos_z;
	result->dir->x = 0;
	result->dir->y = 0;
	result->dir->z = -1;
	return (result);
}
