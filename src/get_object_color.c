/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:27:15 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/21 01:36:52 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color_mask	get_object_color(t_collision *hit)
{
	static t_color_mask	(*get_texu_clr[6])(t_collision *) = {
		[PLANE] = NULL,
		[TRIANGLE] = NULL,
		[RECTANGLE] = NULL,
		[SPHERE] = &get_texu_pxl_sphere,
		[CYLINDRE] = &get_texu_pxl_cylinder,
		[CONE] = NULL,
	};
	t_color_mask	c;

	if (hit->object->has_texture)
		c = texture_checkboard(hit->pos, hit->object->rot,
				hit->object->texu_offs, hit->object->texu_size);
	else if (hit->object->texu.buf != NULL
			&& get_texu_clr[hit->object->type] != NULL)
		c = get_texu_clr[hit->object->type](hit);
	else
	{
		c.r = hit->object->color_r;
		c.g = hit->object->color_g;
		c.b = hit->object->color_b;
	}
	return (c);
}
