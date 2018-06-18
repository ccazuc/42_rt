/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_attribute.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:05:32 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/18 12:35:23 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_config_thread(t_env *env, char **datas, int *start)
{
	int		value;

	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for thread."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Thread's parameter is invalid."
		, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	if (value < 1 || value > 8)
	{
		ft_putstr("Warning, incorrect value for thread's param, must be");
		ft_putstr(" between 1 and 8. Default value will be used.\n");
	}
	else
		env->nb_thread = value;
	*start += 1;
}

void	parse_config_ambient(t_env *env, char **datas, int *start)
{
	t_color_mask	mask;
	int				value;

	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3]
	|| !datas[*start + 4])
		ft_exit("Error, invalid file. Not enough parameters for ambient."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]) || !ft_str_isdigit(datas[*start + 4]))
		ft_exit("Error, invalid file. Ambient's parameters are invalid."
		, EXIT_FAILURE);
	mask.r = ft_atoi(datas[*start + 1]);
	mask.g = ft_atoi(datas[*start + 2]);
	mask.b = ft_atoi(datas[*start + 3]);
	value = ft_atoi(datas[*start + 4]);
	if (mask.r < 0 || mask.r > 255 || mask.g < 0 || mask.g > 255 ||
	mask.b < 0 || mask.b > 255 || value < 0)
		ft_exit("Ambient's value is invalid.", EXIT_FAILURE);
	else
	{
		env->light_ambient = conv_rgb_to_int(mask.r, mask.g, mask.b);
		env->ambient_power = 1. / value;
	}
	*start += 4;
}

void	parse_config_window_width(t_env *env, char **datas, int *start)
{
	int		value;

	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for window."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Window's parameter is invalid."
		, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	if (value < 100 || value > 2400)
	{
		ft_putstr("Warning, incorrect value for window_width's param, must be");
		ft_putstr(" between 100 and 2400. Default value will be used.\n");
	}
	else
		env->window_width = value;
	*start += 1;
}

void	parse_config_window_height(t_env *env, char **datas, int *start)
{
	int		value;

	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for window."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Window's parameter is invalid."
		, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	if (value < 100 || value > 1300)
	{
		ft_putstr("Warning, incorrect value for window_height's param, must");
		ft_putstr(" be between 100 and 1300. Default value will be used.\n");
	}
	else
		env->window_height = value;
	*start += 1;
}
