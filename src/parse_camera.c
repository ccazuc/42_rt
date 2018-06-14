/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:30:58 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:49:34 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera_position(t_camera *camera, char **datas, int *start)
{
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough params for camera's position."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start
	+ 2]) || !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Camera's Position params are invalid."
		, EXIT_FAILURE);
	camera->pos.x = ft_atoi(datas[*start + 1]);
	camera->pos.y = ft_atoi(datas[*start + 2]);
	camera->pos.z = ft_atoi(datas[*start + 3]);
	*start += 3;
}

void	parse_camera_rotation(t_camera *camera, char **datas, int *start)
{
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough params for camera's rotation."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start
	+ 2]) || !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Camera's Rotation params are invalid."
		, EXIT_FAILURE);
	camera->rot.x = ft_atoi(datas[*start + 1]);
	camera->rot.y = ft_atoi(datas[*start + 2]);
	camera->rot.z = ft_atoi(datas[*start + 3]);
	*start += 3;
}

void	parse_camera(t_env *env, char **datas)
{
	int			i;
	t_camera	*camera;
	int			len;

	if (env->camera)
		ft_exit("Error, you specified 2 cameras.", -1);
	len = ft_array_len(datas);
	if (!(camera = malloc(sizeof(*camera))))
		ft_exit("Error, of out memory.", -1);
	i = 0;
	while (++i < len)
		if (check_piece_attribut_name(datas[i], "position"))
			parse_camera_position(camera, datas, &i);
		else if (check_piece_attribut_name(datas[i], "rotation"))
			parse_camera_rotation(camera, datas, &i);
		else
			ft_exit("Error, invalid file. Unknown camera attribute.", -1);
	env->camera = camera;
}
