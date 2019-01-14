/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:08 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:33:33 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_left(t_env *env)
{
	if (!env->draw_finished)
		return ;
	free(env->thread_list);
	env->camera->rot.y -= 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	rotate_right(t_env *env)
{
	if (!env->draw_finished)
		return ;
	free(env->thread_list);
	env->camera->rot.y += 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	rotate_up(t_env *env)
{
	if (!env->draw_finished)
		return ;
	free(env->thread_list);
	env->camera->rot.x += 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	rotate_down(t_env *env)
{
	if (!env->draw_finished)
		return ;
	free(env->thread_list);
	env->camera->rot.x -= 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}
