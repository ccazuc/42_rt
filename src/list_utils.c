/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:49:11 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 15:51:30 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	list_add_object(t_env *env, t_object *object)
{
	t_object_list	*list;
	t_object_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	new->next = NULL;
	new->object = object;
	if (!env->object_list)
	{
		env->object_list = new;
		return ;
	}
	list = env->object_list;
	while (list->next)
		list = list->next;
	list->next = new;
}

void	list_add_light(t_env *env, t_light *light)
{
	t_light_list	*list;
	t_light_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	new->next = NULL;
	new->light = light;
	if (!env->light_list)
	{
		env->light_list = new;
		return ;
	}
	list = env->light_list;
	while (list->next)
		list = list->next;
	list->next = new;
}

void	list_add_material(t_env *env, t_material *material)
{
	t_material_list	*list;
	t_material_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	new->next = NULL;
	new->material = material;
	if (!env->material_list)
	{
		env->material_list = new;
		return ;
	}
	list = env->material_list;
	while (list->next)
		list = list->next;
	list->next = new;
}

void	list_add_define(t_env *env, t_define *define)
{
	t_define_list	*list;
	t_define_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	new->next = NULL;
	new->define = define;
	if (!env->define_list)
	{
		env->define_list = new;
		return ;
	}
	list = env->define_list;
	while (list->next)
		list = list->next;
	list->next = new;
}
