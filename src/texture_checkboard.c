/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checkboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:12:09 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/17 01:59:04 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		get_final_pos(t_vector hit_pos, t_vector rot, int *pos)
{
	static int const	size = 1;

	vector_rotate(&hit_pos, &rot);
	pos[0] = round(hit_pos.x / size);
	pos[1] = round(hit_pos.y / size);
	pos[2] = round(hit_pos.z / size);
}

t_color_mask	texture_checkboard(t_vector hit_pos, t_vector rot)
{
	static t_color_mask const	white = {255.0, 255.0, 255.0};
	static t_color_mask const	black = {0.0, 0.0, 0.0};
	int							pos[3];
	t_color_mask				c;

	get_final_pos(hit_pos, rot, pos);
	if (pos[0] % 2 == 0)
	{
		if ((pos[1] % 2 == 0 && pos[2] % 2 == 0)
				|| (pos[1] % 2 != 0 && pos[2] % 2 != 0))
			c = white;
		else
			c = black;
	}
	else
	{
		if ((pos[1] % 2 == 0 && pos[2] % 2 == 0)
				|| (pos[1] % 2 != 0 && pos[2] % 2 != 0))
			c = black;
		else
			c = white;
	}
	return (c);
}
