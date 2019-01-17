/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checkboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:12:09 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/17 14:34:35 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color_mask	texture_checkboard(t_vector hit_pos,
		t_vector rot,
		t_vector const offs,
		t_vector const size)
{
	static t_color_mask const	c[2] = {{255.0, 255.0, 255.0}, {0.0, 0.0, 0.0}};

	vector_rotate(&hit_pos, &rot);
	return (c[((long)(round((hit_pos.x + offs.x) / size.x)) & 0b1)
			^ ((long)(round((hit_pos.y + offs.y) / size.y)) & 0b1)
			^ ((long)(round((hit_pos.z + offs.z) / size.z)) & 0b1)]);
}
