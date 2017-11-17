/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:49:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 15:20:45 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	list_add_object(t_env *env, t_object *object)
{
	t_rtlist	*list;
	t_rtlist	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_exit("Error, out of memory.", -1);
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
	t_rtllist	*list;
	t_rtllist	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_exit("Error, out of memory.", -1);
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
