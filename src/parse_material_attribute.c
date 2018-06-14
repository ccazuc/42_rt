/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_attribute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:39:55 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 13:31:10 by ccazuc           ###   ########.fr       */
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
	//else if (check_piece_attribut_name(datas[*i], "scale"))
	//	parse_material_scale(material, datas, i);
	//else if (check_piece_attribut_name(datas[*i], "reflection"))
	//	parse_material_reflection(material, datas, i);
	//else if (check_piece_attribut_name(datas[*i], "transparency"))
	//	parse_material_transparency(material, datas, i);
	else
		ft_exit("Error, invalid file. Unknown material attribut.",
		EXIT_FAILURE);
}
