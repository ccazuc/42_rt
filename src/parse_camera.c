/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:30:58 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 11:19:33 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera_position(t_camera *camera, char **datas, int *start)
{
	printf("Camera Position: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for camera's position.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2]) ||
	!ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Camera's Position parameters are invalid.", -1);
	camera->pos_x = ft_atoi(datas[*start + 1]);
	camera->pos_y = ft_atoi(datas[*start + 2]);
	camera->pos_z = ft_atoi(datas[*start + 3]);
	*start += 3;
}

void	parse_camera_rotation(t_camera *camera, char **datas, int *start)
{
	printf("Camera Rotation: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for camera's rotation.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2]) ||
	!ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Camera's Rotation parameters are invalid.", -1);
	camera->rot_x = ft_atoi(datas[*start + 1]);
	camera->rot_y = ft_atoi(datas[*start + 2]);
	camera->rot_z = ft_atoi(datas[*start + 3]);
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
	printf("parse_camera start\n");
	if (!(camera = malloc(sizeof(*camera))))
		ft_exit("Error, of out memory.", -1);
	i = 0;
	while (++i < len)
	{
		printf("word: %s\n", datas[i]);
		if (!ft_strcmp_ignrcase(datas[i], "pos"))
			parse_camera_position(camera, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "rot"))
			parse_camera_rotation(camera, datas, &i);
		else
			ft_exit("Error, invalid file.", -1);
	}
	free_2d_array(datas);
	env->camera = camera;
}
