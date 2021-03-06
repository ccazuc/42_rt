/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:16:26 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:33:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_forward(t_env *env)
{
	if (!env->draw_finished)
		return ;
	free(env->thread_list);
	env->camera->pos.x += sin(ft_toradians(env->camera->rot.x)) * 2;
	env->camera->pos.z += cos(ft_toradians(env->camera->rot.z)) * 2;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	move_backward(t_env *env)
{
	if (!env->draw_finished)
		return ;
	free(env->thread_list);
	env->camera->pos.x -= sin(ft_toradians(env->camera->rot.x)) * 2;
	env->camera->pos.z -= cos(ft_toradians(env->camera->rot.z)) * 2;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}
