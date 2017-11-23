/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 08:11:02 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	find_light(t_env *env, r_ray *ray)
{
	t_rttlist	*list;
	t_ray		*ray;

	list = env->light_list;
	ray = create_camera_ray(env);
	while (list)
	{
		ray->dir->x = list->pos_x - ray->pos_x;
		ray->dir->y = list->pos_y - ray->pos_y;
		ray->dir->z = list->pos_z - ray->pos_z;
		if (get_pixel_color(env, ray) != BG_COLOR)
		{
			list = list->next;
			continue ;
		}
	}
}

unsigned int	get_light_color(t_env *env, t_ray *ray)
{
	unsigned int	result;

	result = 0;
	result = find_light(env, ray);
}
