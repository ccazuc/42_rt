/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:34:08 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/15 11:39:07 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			main(int argc, char **argv)
{
	t_env			*env;
	t_object_list	*list;
	long			start;

	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	init_env(env);
	start = epoch_millis();
	parse(env, argc, argv);
	put_timer(start, epoch_millis(), "File parsed");
	init_window(env);
	list = env->object_list;
	while (list)
	{
		printf("Type: %d\n", list->object->type);
		printf("Color | r: %f, g: %f, b: %f\n", list->object->color_r, list->object->color_g, list->object->color_b);
		printf("Position | x: %f, y: %f, z: %f\n", list->object->pos.x, list->object->pos.y, list->object->pos.z);
		printf("Orientation | x: %f, y: %f, z: %f\n", list->object->rot.x, list->object->rot.y, list->object->rot.z);
		printf("Transparency: %f\n", list->object->transparency);
		printf("Reflection: %f\n", list->object->reflection);
		printf("Scale: %d\n", list->object->scale);
		printf("\n\n\n");
		list = list->next;
	}
	printf("Camera:\n");
	printf("Position | x: %f, y: %f, z: %f\n", env->camera->pos.x, env->camera->pos.y, env->camera->pos.z);
	printf("Orientation | x: %f, y: %f, z: %f\n", env->camera->rot.x, env->camera->rot.y, env->camera->rot.z);
	render(env);
	return (0);
}
