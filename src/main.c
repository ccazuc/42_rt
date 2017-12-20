/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:34:08 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 12:47:51 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_env		*env;
	t_rtlist	*list;

	/*printf("%d\n", check_piece_attribut_name("PoS", "posITIon"));
	printf("%d\n", check_piece_attribut_name("pop", "posITIon"));
	printf("%d\n", check_piece_attribut_name("Po", "posITIon"));
	printf("%d\n", check_piece_attribut_name("P", "posITIon"));
	printf("%d\n", check_piece_attribut_name("PoSiTiON", "posITIon"));
	printf("%d\n", check_piece_attribut_name("PoSiTi", "posITIon"));
	printf("%d\n", check_piece_attribut_name("PoSiTions", "posITIon"));
	printf("%d\n", check_piece_attribut_name("PoSiiTion", "posITIon"));*/
	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	init_env(env);
	parse(env, argc, argv);
	init_window(env);
	list = env->object_list;
	while (list)
	{
		printf("Type: %d\n", list->object->type);
		printf("Color | r: %d, g: %d, b: %d\n", list->object->color_r, list->object->color_g, list->object->color_b);
		printf("Position | x: %f, y: %f, z: %f\n", list->object->pos.x, list->object->pos.y, list->object->pos.z);
		printf("Orientation | x: %f, y: %f, z: %f\n", list->object->rot.x, list->object->rot.y, list->object->rot.z);
		printf("\n\n\n");
		list = list->next;
	}
	printf("Camera:\n");
	printf("Position | x: %f, y: %f, z: %f\n", env->camera->pos.x, env->camera->pos.y, env->camera->pos.z);
	printf("Orientation | x: %f, y: %f, z: %f\n", env->camera->rot.x, env->camera->rot.y, env->camera->rot.z);
	render(env);
	return (0);
}
