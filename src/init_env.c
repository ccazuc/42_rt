/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:57:17 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:04:31 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_env(t_env *env)
{
	env->material_list = NULL;
	env->object_list = NULL;
	env->define_list = NULL;
	env->camera = NULL;
	env->light_list = NULL;
	env->thread_list = NULL;
	env->draw_finished = 0;
	env->nb_thread = 8;
	env->light_ambient = conv_rgb_to_int(255, 255, 255);
	env->sepia_filter = 0;
}
