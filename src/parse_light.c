/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:08 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 10:10:00 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_position(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_position)
		ft_exit("Error, invalid file. Pos dupli for a light.", EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for light's pos."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Light's Position parameters are invalid.",
		EXIT_FAILURE);
	light->pos.x = ft_atoi(datas[*start + 1]);
	light->pos.y = ft_atoi(datas[*start + 2]);
	light->pos.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	light->has_parsed_position = 1;
}

void	parse_light_rotation(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_rotation)
		ft_exit("Error, invalid file. Rot dupli for a light.", EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough param for light's rotation."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start
	+ 2]) || !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Light's Rotation parameters are invalid."
		, EXIT_FAILURE);
	light->rot.x = ft_atoi(datas[*start + 1]);
	light->rot.y = ft_atoi(datas[*start + 2]);
	light->rot.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	light->has_parsed_rotation = 1;
}

void	parse_light_color(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_color)
		ft_exit("Error, invalid file. Color duplicate for a light."
		, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough params for color."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Color's parameters are invalid."
		, EXIT_FAILURE);
	light->color_r = ft_atoi(datas[*start + 1]);
	light->color_g = ft_atoi(datas[*start + 2]);
	light->color_b = ft_atoi(datas[*start + 3]);
	if (light->color_r < 0 || light->color_g < 0 || light->color_b < 0)
		ft_exit("Error, invalid file. Color's value is invalid."
		, EXIT_FAILURE);
	*start += 3;
	light->has_parsed_color = 1;
}

void	parse_light_power(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_power)
		ft_exit("Error, invalid file. Power duplicate for a light."
		, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for power."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Power's parameters are invalid."
		, EXIT_FAILURE);
	light->power = ft_atoi(datas[*start + 1]);
	if (light->power < 0)
		ft_exit("Error, invalid file. Power's value is invalid."
		, EXIT_FAILURE);
	*start += 1;
	light->has_parsed_power = 1;
}

void	parse_light(t_env *env, char **datas)
{
	int			i;
	t_light		*light;
	int			len;

	len = ft_array_len(datas);
	light = create_light();
	i = 0;
	while (++i < len)
		if (check_piece_attribut_name(datas[i], "position"))
			parse_light_position(light, datas, &i);
		else if (check_piece_attribut_name(datas[i], "rotation"))
			parse_light_rotation(light, datas, &i);
		else if (check_piece_attribut_name(datas[i], "color"))
			parse_light_color(light, datas, &i);
		else if (check_piece_attribut_name(datas[i], "power"))
			parse_light_power(light, datas, &i);
		else
			ft_exit("Error, invalid file. Unknown light attribut."
			, EXIT_FAILURE);
	list_add_light(env, light);
}
