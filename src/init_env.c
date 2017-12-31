/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:57:17 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/31 19:14:31 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_env(t_env *env)
{
	env->object_list = NULL;
	env->camera = NULL;
	env->light_list = NULL;
	env->light_ambient = conv_rgb_to_int(255, 255, 255);
}
