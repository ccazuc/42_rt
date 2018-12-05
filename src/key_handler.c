/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:13:26 by ccazuc            #+#    #+#             */
/*   Updated: 2018/12/05 14:44:38 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		key_up_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	if (keycode == 53)
		ft_exit("Exit requested.", 0);
	else if (keycode == 13)
		move_forward(env);
	else if (keycode == 1)
		move_backward(env);
	else if (keycode == 124)
		rotate_right(env);
	else if (keycode == 123)
		rotate_left(env);
	else if (keycode == 126)
		rotate_up(env);
	else if (keycode == 125)
		rotate_down(env);
	else if (keycode == 96)
		reload_file(env);
	return (0);
}
