/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:09:17 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:52:19 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_material_name(t_material *material, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < 'a' && str[i] > 'z' && str[i] < 'A' && str[i] > 'Z')
			ft_exit("Error, invalid file. Invalid material name."
					, EXIT_FAILURE);
	material->name = ft_strdup(str);
}

void			parse_material_color(t_material *material,
		char **datas, int *start)
{
	if (material->has_parsed_color)
		ft_exit("Error, invalid file. Color duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough params for material's color."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
			|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Material color parameters are invalid."
				, EXIT_FAILURE);
	material->color_r = ft_atoi(datas[*start + 1]);
	material->color_g = ft_atoi(datas[*start + 2]);
	material->color_b = ft_atoi(datas[*start + 3]);
	if (material->color_r < 0 || material->color_g < 0 || material->color_b < 0)
		ft_exit("Error, invalid file. Material color value is invalid."
				, EXIT_FAILURE);
	*start += 3;
	material->has_parsed_color = 1;
}

void			parse_material_rotation(t_material *material,
		char **datas, int *start)
{
	if (material->has_parsed_rotation)
		ft_exit("Error, invalid file. Rotation duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for mat's rot."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
			|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Material rotation parameters are invalid."
				, EXIT_FAILURE);
	material->rot.x = ft_atoi(datas[*start + 1]);
	material->rot.y = ft_atoi(datas[*start + 2]);
	material->rot.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	material->has_parsed_rotation = 1;
}

void			parse_material_position(t_material *material,
		char **datas, int *start)
{
	if (material->has_parsed_position)
		ft_exit("Error, invalid file. Position duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for mat's pos."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
			|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Material position parameters are invalid."
				, EXIT_FAILURE);
	material->pos.x = ft_atoi(datas[*start + 1]);
	material->pos.y = ft_atoi(datas[*start + 2]);
	material->pos.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	material->has_parsed_position = 1;
}

void			parse_material(t_env *env, char **datas)
{
	int			i;
	t_material	*material;
	int			len;

	len = ft_array_len(datas);
	if (len <= 1)
		ft_exit("Error, invalid file. Invalid material.", EXIT_FAILURE);
	material = create_material();
	parse_material_name(material, datas[1]);
	if (find_material(env, material->name))
		ft_exit("Error, invalid file. Two materials have the same name.",
				EXIT_FAILURE);
	i = 1;
	while (++i < len)
		parse_material_attribute(material, datas, &i);
	list_add_material(env, material);
}
