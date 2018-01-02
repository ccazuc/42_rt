/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:59:31 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 16:54:01 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_define	*find_define(t_env *env, char *str)
{
	t_define_list	*list;

	list = env->define_list;
	while (list)
	{
		printf("define_name: %s, current_name: %s, match: %d\n", str, list->define->name, ft_strcmp_ignrcase(list->define->name, str));
		if (!ft_strcmp_ignrcase(list->define->name, str))
			return (list->define);
		list = list->next;
	}
	return (NULL);
}
