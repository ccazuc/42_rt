/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:30:58 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 09:15:33 by ccazuc           ###   ########.fr       */
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
	camera->pos.x = ft_atoi(datas[*start + 1]);
	camera->pos.y = ft_atoi(datas[*start + 2]);
	camera->pos.z = ft_atoi(datas[*start + 3]);
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
