/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pieces_datas2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:56:41 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 16:04:30 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_reflection(t_env *env,
		t_object *object, char **datas, int *start)
{
	t_define	*define;

	if (object->has_parsed_reflection)
		ft_exit("Error, invalid file. Reflection duplicate for an object."
				, EXIT_FAILURE);
	if (datas[*start + 1] && !ft_str_isdigit(datas[*start + 1])
			&& (define = find_define(env, datas[*start + 1])))
	{
		fill_object_reflection_define(object, define, start);
		return ;
	}
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for refl."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Reflection's parameters are invalid."
				, EXIT_FAILURE);
	object->reflection = ft_atoi(datas[*start + 1]) / 100.;
	if (object->reflection < 0 || object->reflection > 1.)
		ft_exit("Error, invalid file. Reflection's param's value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	object->has_parsed_reflection = 1;
}

void	parse_object_transparency(t_env *env,
		t_object *object, char **datas, int *start)
{
	t_define	*define;

	if (object->has_parsed_transparency)
		ft_exit("Error, invalid file. Transparency duplicate for an object."
				, EXIT_FAILURE);
	if (datas[*start + 1] && !ft_str_isdigit(datas[*start + 1])
			&& (define = find_define(env, datas[*start + 1])))
	{
		fill_object_transparency_define(object, define, start);
		return ;
	}
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for trans."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Transp's parameters are invalid."
				, EXIT_FAILURE);
	object->transparency = ft_atoi(datas[*start + 1]) / 100.;
	if (object->transparency < 0 || object->transparency > 1.)
		ft_exit("Error, invalid file. Transp's param's value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	object->has_parsed_transparency = 1;
}

void	parse_object_refraction(t_env *env, t_object *object,
		char **datas, int *start)
{
	t_define	*define;

	if (object->has_parsed_refraction)
		ft_exit("Error, invalid file. Refraction duplicate for an object."
				, EXIT_FAILURE);
	if (datas[*start + 1] && !ft_str_isdigit(datas[*start + 1])
			&& (define = find_define(env, datas[*start + 1])))
	{
		fill_object_refraction_define(object, define, start);
		return ;
	}
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for refra."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Refra's parameters are invalid."
				, EXIT_FAILURE);
	object->refraction = ft_atoi(datas[*start + 1]) / 100.;
	if (object->refraction < 1. || object->refraction > 2.)
		ft_exit("Error, invalid file. Refraction's param's value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	object->has_parsed_refraction = 1;
}

void	parse_object_gi(t_env *env, t_object *object,
		char **datas, int *start)
{
	(void)env;
	if (object->has_parsed_gi)
		ft_exit("Error, invalid file. GI duplicate for an object."
				, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for GI."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. GI's parameters are invalid."
				, EXIT_FAILURE);
	object->has_gi = ft_atoi(datas[*start + 1]);
	if (object->has_gi != 0 && object->has_gi != 1)
		ft_exit("Error, invalid file. GI's param's value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	object->has_parsed_gi = 1;
}
