/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:34:08 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/15 13:15:40 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	t_rtlist	*list;

	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.", -1);
	init_env(env);
	parse(env, argc, argv);
	list = env->object_list;
	while (list)
	{
		printf("Type: %d\n", list->object->type);
		printf("Color | r: %d, g: %d, b: %d\n", list->object->color_r, list->object->color_g, list->object->color_b);
		printf("Position | x: %d, y: %d, z: %d\n", list->object->pos_x, list->object->pos_y, list->object->pos_z);
		printf("Orientation | x: %d, y: %d, z: %d\n", list->object->rot_x, list->object->rot_y, list->object->rot_z);
		printf("\n\n\n");
		list = list->next;
	}
	return (0);
}
