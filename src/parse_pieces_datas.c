/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pieces_datas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:26:27 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:28:23 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_position(t_env *env,
t_object *object, char **datas, int *start)
{
	t_define	*define;

	if (object->has_parsed_position)
		ft_exit("Error, invalid file. Position duplicate for an object."
		, EXIT_FAILURE);
	if (datas[*start + 1] && !ft_str_isdigit(datas[*start + 1]) &&
	(define = find_define(env, datas[*start + 1])))
	{
		fill_object_position_define(object, define, start);
		return ;
	}
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for position."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Position's parameters are invalid."
		, EXIT_FAILURE);
	object->pos.x = ft_atoi(datas[*start + 1]);
	object->pos.y = ft_atoi(datas[*start + 2]);
	object->pos.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_position = 1;
}

void	parse_object_rotation(t_env *env,
t_object *object, char **datas, int *start)
{
	t_define *define;

	if (object->has_parsed_rotation)
		ft_exit("Error, invalid file. Rotation duplicate for an object."
		, EXIT_FAILURE);
	if (datas[*start + 1] && !ft_str_isdigit(datas[*start + 1]) &&
	(define = find_define(env, datas[*start + 1])))
	{
		fill_object_rotation_define(object, define, start);
		return ;
	}
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for rotation."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Rotation's parameters are invalid."
		, EXIT_FAILURE);
	object->rot.x = ft_atoi(datas[*start + 1]);
	object->rot.y = ft_atoi(datas[*start + 2]);
	object->rot.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	object->has_parsed_rotation = 1;
}

void	parse_object_color(t_env *env,
t_object *object, char **datas, int *start)
{
	t_define *define;

	if (object->has_parsed_color)
		ft_exit("Error, invalid file. Color duplicate for an object."
		, EXIT_FAILURE);
	if (datas[*start + 1] && !ft_str_isdigit(datas[*start + 1]) &&
	(define = find_define(env, datas[*start + 1])))
	{
		fill_object_color_define(object, define, start);
		return ;
	}
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for color.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Color's parameters are invalid."
		, EXIT_FAILURE);
	object->color_r = ft_atoi(datas[*start + 1]);
	object->color_g = ft_atoi(datas[*start + 2]);
	object->color_b = ft_atoi(datas[*start + 3]);
	if (object->color_r < 0 || object->color_r > 255 || object->color_g < 0
	|| object->color_g > 255 || object->color_b < 0 || object->color_b > 255)
		ft_exit("Color's value invalid.", EXIT_FAILURE);
	*start += 3;
	object->has_parsed_color = 1;
}

void	parse_object_scale(t_env *env,
t_object *object, char **datas, int *start)
{
	if (object->has_parsed_scale)
		ft_exit("Error, invalid file. Scale duplicate for an object."
		, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for scale."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Scale's parameters are invalid."
		, EXIT_FAILURE);
	object->scale = ft_atoi(datas[*start + 1]);
	if (object->scale <= 0)
		ft_exit("Error, invalid file. Scale's value is invalid."
		, EXIT_FAILURE);
	*start += 1;
	object->has_parsed_scale = env->bpp;
	object->has_parsed_scale = 1;
}
