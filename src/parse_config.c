/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:58:22 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 12:32:28 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_attribut(t_env *env, char **datas, int *i)
{
	if (!ft_strcmp_ignrcase(datas[*i], "thread"))
		parse_config_thread(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "ambient"))
		parse_config_ambient(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "window_width"))
		parse_config_window_width(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "window_height"))
		parse_config_window_height(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "filter_sepia"))
		parse_config_filter_sepia(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "filter_grayscale"))
		parse_config_filter_grayscale(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "fsaa"))
		parse_config_fsaa(env, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "n_sample_ray"))
		parse_config_sample_ray(env, datas, i);
	else
		ft_exit("Error, invalid file. Unknown config param.", EXIT_FAILURE);
}

void		parse_config(t_env *env, char **datas)
{
	int			i;
	int			len;

	len = ft_array_len(datas);
	i = 0;
	while (++i < len)
		check_attribut(env, datas, &i);
}
