/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:32:50 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/29 15:20:46 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light	*create_light(void)
{
	t_light	*light;

	if (!(light = malloc(sizeof(*light))))
		ft_exit("Error, of out memory.", EXIT_FAILURE);
	light->has_parsed_rotation = 0;
	light->has_parsed_position = 0;
	light->has_parsed_color = 0;
	light->has_parsed_power = 0;
	light->rot.x = 0;
	light->rot.y = 0;
	light->rot.z = 0;
	light->power = 1;
	light->is_direc = 0;
	return (light);
}
