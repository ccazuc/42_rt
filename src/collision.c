/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 07:27:40 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 12:12:56 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_collision	*create_collision(void)
{
	t_collision	*collision;

	if (!(collision = malloc(sizeof(*collision))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	collision->distance = 10000000;
	collision->object = NULL;
	collision->color.r = 0;
	collision->color.g = 0;
	collision->color.b = 0;
	return (collision);	
}

void	free_collision(t_collision *collision)
{
	free(collision);
}
