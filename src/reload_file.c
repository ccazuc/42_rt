/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:46:26 by ccazuc            #+#    #+#             */
/*   Updated: 2018/12/05 15:40:33 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	free_objects(t_env *env)
{
	t_object_list	*object;
	t_object_list	*tmp;

	object = env->object_list;
	while (object)
	{
		tmp = object;
		object = object->next;
		free(tmp->object);
		free(tmp);
	}
	env->object_list = NULL;
}

static void	free_lights(t_env *env)
{
	t_light_list	*light;
	t_light_list	*tmp;

	light = env->light_list;
	while (light)
	{
		tmp = light;
		light = light->next;
		free(tmp->light);
		free(tmp);
	}
	env->light_list = NULL;
}

static void	free_materials(t_env *env)
{
	t_material_list	*material;
	t_material_list	*tmp;

	material = env->material_list;
	while (material)
	{
		tmp = material;
		material = material->next;
		free(tmp->material->name);
		free(tmp->material);
		free(tmp);
	}
	env->material_list = NULL;
}

static void	free_defines(t_env *env)
{
	t_define_list	*define;
	t_define_list	*tmp;

	define = env->define_list;
	while (define)
	{
		tmp = define;
		define = define->next;
		free(tmp->define->name);
		free(tmp->define);
		free(tmp);
	}
	env->define_list = NULL;
}

void		reload_file(t_env *env)
{
	if (!env->draw_finished)
		return ;
	env->draw_finished = 0;
	free_objects(env);
	free_lights(env);
	free_materials(env);
	free_defines(env);
	free(env->camera);
	env->camera = NULL;
	parse(env, env->file_name);
	render(env->env_list, env->id, 0);
}
