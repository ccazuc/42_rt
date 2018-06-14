/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:51:36 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:51:53 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				add_obj_vertex(t_env *env, double x, double y, double z)
{
	t_obj_vertex_list	*result;
	t_obj_vertex_list	*list;

	if (!(result = malloc(sizeof(*result))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	result->next = NULL;
	result->vertex.x = x;
	result->vertex.y = y;
	result->vertex.z = z;
	if (!env->obj_vertex_list)
	{
		env->obj_vertex_list = result;
		return ;
	}
	list = env->obj_vertex_list;
	while (list->next)
		list = list->next;
	list->next = result;
}

void				add_obj_normal(t_env *env, double x, double y, double z)
{
	t_obj_normal_list	*result;
	t_obj_normal_list	*list;

	if (!(result = malloc(sizeof(*result))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	result->next = NULL;
	result->normal.x = x;
	result->normal.y = y;
	result->normal.z = z;
	if (!env->obj_normal_list)
	{
		env->obj_normal_list = result;
		return ;
	}
	list = env->obj_normal_list;
	while (list->next)
		list = list->next;
	list->next = result;
}

t_obj_vertex_list	get_obj_vertex(t_env *env, int index)
{
	t_obj_vertex_list	*list;
	int					i;

	list = env->obj_vertex_list;
	i = 0;
	while (list && ++i < index)
		list = list->next;
	return (list);
}

t_obj_normal_list	get_obj_normal(t_env *env, int index)
{
	t_obj_normal_list	*list;
	int					i;

	list = env->obj_normal_list;
	i = 0;
	while (list && ++i < index)
		list = list->next;
	return (list);
}
