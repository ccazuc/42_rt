/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:08 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 15:30:09 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_position(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_position)
		ft_exit("Error, invalid file. Position duplicate for a light.", EXIT_FAILURE); 
	printf("Light Position: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for light's position."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Light's Position parameters are invalid.",
		EXIT_FAILURE);
	light->pos_x = ft_atoi(datas[*start + 1]);
	light->pos_y = ft_atoi(datas[*start + 2]);
	light->pos_z = ft_atoi(datas[*start + 3]);
	*start += 3;
	light->has_parsed_position = 1;
}

void	parse_light_rotation(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_rotation)
		ft_exit("Error, invalid file. Rotation duplicate for a light.", EXIT_FAILURE); 
	printf("Light Rotation: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for light's rotation."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2]) ||
	!ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Light's Rotation parameters are invalid."
		, EXIT_FAILURE);
	light->rot_x = ft_atoi(datas[*start + 1]);
	light->rot_y = ft_atoi(datas[*start + 2]);
	light->rot_z = ft_atoi(datas[*start + 3]);
	*start += 3;
	light->has_parsed_rotation = 1;
}

void	parse_light_color(t_light *light, char **datas, int *start)
{
	if (light->has_parsed_color)
		ft_exit("Error, invalid file. Color duplicate for a light."
		, EXIT_FAILURE);
	printf("Color: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for color.", EXIT_FAILURE);
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
	printf("Color: %s\n", datas[*start + 1]);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for power.", EXIT_FAILURE);
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
	if (!(light = malloc(sizeof(*light))))
		ft_exit("Error, of out memory.", EXIT_FAILURE);
	i = 0;
	light->has_parsed_rotation = 0;
	light->has_parsed_position  = 0;
	light->has_parsed_color = 0;
	light->has_parsed_power = 0;
	light->power = 1;
	while (++i < len)
	{
		if (!ft_strcmp_ignrcase(datas[i], "pos"))
			parse_light_position(light, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "rot"))
			parse_light_rotation(light, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "color"))
			parse_light_color(light, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "power"))
			parse_light_power(light, datas, &i);
		else
			ft_exit("Error, invalid file.", EXIT_FAILURE);
	}
	list_add_light(env, light);
}
