/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:53:35 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 10:39:36 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_window(t_env *env)
{
	int		line_size;
	int		bpp;
	int		order;

	if (!(env->mlx_ptr = mlx_init()))
		ft_exit("Error, failed to inti connection.", EXIT_FAILURE);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_NAME)))
		ft_exit("Error, failed to create window.", EXIT_FAILURE);
	if (!(env->mlx_img_ptr = mlx_new_image(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT)))
		ft_exit("Error, failed to create image.", EXIT_FAILURE);
	line_size = WINDOW_WIDTH * 3;
	bpp = 24;
	order = 1;
	if (!(env->mlx_img_data = mlx_get_data_addr(env->mlx_img_ptr, &bpp,
		&line_size, &order)))
		ft_exit("Error, failed to load image datas.", EXIT_FAILURE);
	env->bpp = bpp;
}
