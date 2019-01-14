/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_attribute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:39:55 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:52:18 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_material_attribute(t_material *material, char **datas, int *i)
{
	if (check_piece_attribut_name(datas[*i], "color"))
		parse_material_color(material, datas, i);
	else if (check_piece_attribut_name(datas[*i], "position"))
		parse_material_position(material, datas, i);
	else if (check_piece_attribut_name(datas[*i], "rotation"))
		parse_material_rotation(material, datas, i);
	else if (check_piece_attribut_name(datas[*i], "scale"))
		parse_material_scale(material, datas, i);
	else if (check_piece_attribut_name(datas[*i], "reflection"))
		parse_material_reflection(material, datas, i);
	else if (check_piece_attribut_name(datas[*i], "transparency"))
		parse_material_transparency(material, datas, i);
	else if (check_piece_attribut_name(datas[*i], "refraction"))
		parse_material_refraction(material, datas, i);
	else
		ft_exit("Error, invalid file. Unknown material attribut.",
				EXIT_FAILURE);
}

void	parse_material_scale(t_material *material, char **datas, int *start)
{
	if (material->has_parsed_scale)
		ft_exit("Error, invalid file. Scale duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough param for material's scale."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Material scale parameter is invalid."
				, EXIT_FAILURE);
	material->scale = ft_atoi(datas[*start + 1]);
	if (material->scale <= 0 || material->scale >= 1000)
		ft_exit("Error, invalid file. Material scale value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	material->has_parsed_scale = 1;
}

void	parse_material_reflection(t_material *material,
		char **datas, int *start)
{
	if (material->has_parsed_reflection)
		ft_exit("Error, invalid file. Reflection duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough param for material's refl."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Material refl parameter is invalid."
				, EXIT_FAILURE);
	material->reflection = ft_atoi(datas[*start + 1]) / 100.;
	if (material->reflection < 0 || material->reflection > 1.)
		ft_exit("Error, invalid file. Material reflection value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	material->has_parsed_reflection = 1;
}

void	parse_material_refraction(t_material *material,
		char **datas, int *start)
{
	if (material->has_parsed_refraction)
		ft_exit("Error, invalid file. Refraction duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough param for material's refr."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Material refr parameter is invalid."
				, EXIT_FAILURE);
	material->refraction = ft_atoi(datas[*start + 1]) / 100.;
	if (material->refraction < 1. || material->refraction > 2.)
		ft_exit("Error, invalid file. Material refraction value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	material->has_parsed_refraction = 1;
}

void	parse_material_transparency(t_material *material,
		char **datas, int *start)
{
	if (material->has_parsed_transparency)
		ft_exit("Error, invalid file. Transparency duplicate for a material."
				, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough param for material's transp."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Material transp parameter is invalid."
				, EXIT_FAILURE);
	material->transparency = ft_atoi(datas[*start + 1]) / 100.;
	if (material->transparency < 0 || material->transparency > 1.)
		ft_exit("Error, invalid file. Material transparency value is invalid."
				, EXIT_FAILURE);
	*start += 1;
	material->has_parsed_transparency = 1;
}
