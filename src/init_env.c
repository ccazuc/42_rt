/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:57:17 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/16 20:37:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_env(t_env *env)
{
	env->material_list = NULL;
	env->object_list = NULL;
	env->define_list = NULL;
	env->camera = NULL;
	env->file_name = NULL;
	env->light_list = NULL;
	env->thread_list = NULL;
	env->draw_finished = 0;
	env->nb_thread = 8;
	env->light_ambient = conv_rgb_to_int(30, 30, 30);
	env->ambient_power = 0.1;
	env->sepia_filter = 0;
	env->fsaa = 0;
	env->fsaa_img = NULL;
	env->window_width = 1200;
	env->window_height = 900;
	env->grayscale_filter = 0;
	env->fsaa_factor = 4;
	env->was_loaded = 0;
	env->n_sample_ray = 0;
}
