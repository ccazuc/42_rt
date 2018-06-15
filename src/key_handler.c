/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:13:26 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 14:58:23 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		key_up_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	if (keycode == 53)
		ft_exit("Exit requested.", 0);
	return (0);
}
