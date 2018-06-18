/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:08 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 10:52:50 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_left(t_env *env)
{
	free_threads(env);
	env->camera->rot.y -= 15;
	env->draw_finished = 0;
	render(env);
}

void	rotate_right(t_env *env)
{
	free_threads(env);
	env->camera->rot.y += 15;
	env->draw_finished = 0;
	render(env);
}

void	rotate_up(t_env *env)
{
	free_threads(env);
	env->camera->rot.x += 15;
	env->draw_finished = 0;
	render(env);
}

void	rotate_down(t_env *env)
{
	free_threads(env);
	env->camera->rot.x -= 15;
	env->draw_finished = 0;
	render(env);
}
