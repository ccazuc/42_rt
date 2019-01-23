/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:09:38 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/23 21:12:59 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material	*create_material(void)
{
	t_material	*material;

	if (!(material = malloc(sizeof(*material))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	ft_bzero((void *)material, sizeof(*material));
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
