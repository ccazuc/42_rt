/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:53:35 by ccazuc            #+#    #+#             */
/*   Updated: 2018/12/05 14:14:18 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_window(t_env *env)
{
	int		line_size;
	int		bpp;
	int		order;

	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, env->window_width,
		env->window_height, WINDOW_NAME)))
		ft_exit("Error, failed to create window.", EXIT_FAILURE);
	if (!(env->mlx_img_ptr = mlx_new_image(env->mlx_ptr, env->window_width,
		env->window_height)))
		ft_exit("Error, failed to create image.", EXIT_FAILURE);
	line_size = env->window_width * 3;
	bpp = 24;
	order = 1;
	if (!(env->mlx_img_data = mlx_get_data_addr(env->mlx_img_ptr, &bpp,
		&line_size, &order)))
		ft_exit("Error, failed to load image datas.", EXIT_FAILURE);
	env->bpp = bpp;
	env->was_loaded = 1;
}
