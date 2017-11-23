/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:08 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 08:41:10 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_position(t_light *light, char **datas, int *start)
{
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
}

void	parse_light_rotation(t_light *light, char **datas, int *start)
{
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
}

void	parse_light(t_env *env, char **datas)
{
	int			i;
	t_light		*light;
	int			len;

	len = ft_array_len(datas);
	printf("parse_light start\n");
	if (!(light = malloc(sizeof(*light))))
		ft_exit("Error, of out memory.", EXIT_FAILURE);
	i = 0;
	while (++i < len)
	{
		printf("word: %s\n", datas[i]);
		if (!ft_strcmp_ignrcase(datas[i], "pos"))
			parse_light_position(light, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "rot"))
			parse_light_rotation(light, datas, &i);
		else
			ft_exit("Error, invalid file.", EXIT_FAILURE);
	}
	list_add_light(env, light);
}
