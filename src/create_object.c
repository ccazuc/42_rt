/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:01:33 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/23 21:11:55 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object	*create_object(void)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(*object))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	ft_bzero((void *)object, sizeof(*object));
	object->color_r = DEFAULT_COLOR_R;
	object->color_g = DEFAULT_COLOR_G;
	object->color_b = DEFAULT_COLOR_B;
	object->scale = 1;
	object->texu_size.x = 1.;
	object->texu_size.y = 1.;
	object->texu_size.z = 1.;
	object->texu = NULL;
	return (object);
}
