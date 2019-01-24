/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_attribute2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:27:11 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/24 10:18:01 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_config_filter_sepia(t_env *env, char **datas, int *start)
{
	int		value;

	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for cepia."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Cepia's parameter is invalid."
				, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	if (value != 1 && value != 0)
	{
		ft_putstr("Warning, incorrect value for cepia's param, must be");
		ft_putstr(" 0 or 1. Default value will be used.\n");
	}
	else
		env->sepia_filter = value;
	*start += 1;
}

void	parse_config_filter_grayscale(t_env *env, char **datas, int *start)
{
	int		value;

	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for grayscale."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Grayscale's parameter is invalid."
				, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	if (value != 1 && value != 0)
	{
		ft_putstr("Warning, incorrect value for grayscale's param, must be");
		ft_putstr(" 0 or 1. Default value will be used.\n");
	}
	else
		env->grayscale_filter = value;
	*start += 1;
}

void	parse_config_fsaa(t_env *env, char **datas, int *start)
{
	int		value;
	int		factor;

	if (!datas[*start + 1] || !datas[*start + 2])
		ft_exit("Error, invalid file. Not enough parameters for fsaa."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1])
			|| !ft_str_isdigit(datas[*start + 2]))
		ft_exit("Error, invalid file. Fsaa's parameter is invalid."
				, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	factor = ft_atoi(datas[*start + 2]);
	if ((value != 1 && value != 0) || (factor == 0
				|| factor % 2 != 0 || factor >= 16))
	{
		ft_putstr("Warning, incorrect value for fsaa's param, must be");
		ft_putstr(" 0 or 1. Default value will be used.\n");
	}
	else
	{
		env->fsaa = value;
		env->fsaa_factor = factor;
	}
	*start += 2;
}

void	parse_config_sample_ray(t_env *env, char **datas, int *start)
{
	int		value;

	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for sample ray."
				, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]))
		ft_exit("Error, invalid file. Sample ray's parameter is invalid."
				, EXIT_FAILURE);
	value = ft_atoi(datas[*start + 1]);
	if (value < 0 || value > 10000)
	{
		ft_putstr("Warning, incorrect value for Sample_ray's param, must be");
		ft_putstr(" between 0 and 10000.  Default value will be used.\n");
	}
	else
		env->n_sample_ray = value;
	*start += 1;
}
