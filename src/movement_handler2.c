/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:08 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/22 10:50:43 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_left(t_env *env)
{
	free_threads(env);
	env->camera->rot.y -= 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	rotate_right(t_env *env)
{
	free_threads(env);
	env->camera->rot.y += 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	rotate_up(t_env *env)
{
	free_threads(env);
	env->camera->rot.x += 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}

void	rotate_down(t_env *env)
{
	free_threads(env);
	env->camera->rot.x -= 15;
	env->draw_finished = 0;
	render(env->env_list, env->id, 0);
}
