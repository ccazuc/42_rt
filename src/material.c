/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:09:38 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:53:21 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material	*create_material(void)
{
	t_material	*material;

	if (!(material = malloc(sizeof(*material))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	material->pos.x = 0;
	material->pos.y = 0;
	material->pos.z = 0;
	material->rot.x = 0;
	material->rot.y = 0;
	material->rot.z = 0;
	material->has_parsed_position = 0;
	material->has_parsed_color = 0;
	material->has_parsed_rotation = 0;
	material->has_parsed_scale = 0;
	return (material);
}

t_material	*find_material(t_env *env, char *str)
{
	t_material_list	*list;

	list = env->material_list;
	while (list)
	{
		if (!ft_strcmp_ignrcase(list->material->name, str))
			return (list->material);
		list = list->next;
	}
	return (NULL);
}
