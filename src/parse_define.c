/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:56:27 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 16:24:11 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_define(t_env *env, char **datas)
{
	t_define	*define;

	if (!(define = malloc(sizeof(*define))))
		ft_exit("Error, of out memory.", EXIT_FAILURE);
	if (!datas[1])
		ft_exit("Error, invalid file. Define without name.", EXIT_FAILURE);
	define->name = ft_strdup(datas[1]);
	if (!datas[2] || !ft_str_isdigit(datas[2]))
		ft_exit("Error, invalid file. Define has an incorrect value.", EXIT_FAILURE);
	if (find_define(env, define->name))
		ft_exit("Error, invalid file. Two define have the same name.", EXIT_FAILURE);
	list_add_define(env, define);
	define->x = ft_atoi(datas[2]);
	define->nb_value = 1;
	if (!datas[3] || !ft_str_isdigit(datas[3]))
		return ;
	define->y = ft_atoi(datas[3]);
	define->nb_value = 2;
	if (!datas[4] || !ft_str_isdigit(datas[4]))
		return ;
	define->z = ft_atoi(datas[4]);
	define->nb_value = 3;
} 
