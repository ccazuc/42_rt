/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/25 14:45:07 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			init_mask(t_light_mask *mask, unsigned int color)
{
	mask->r = (color & 0xFF0000) >> 16;
	mask->g = (color & 0x00FF00) >> 8;
	mask->b = (color & 0x0000FF);
}

unsigned int	find_light(t_env *env, unsigned int color)
{
	t_rttlist		*list;
	t_ray			*ray;
	t_light_mask	mask;
	int				light_found;

	list = env->light_list;
	ray = create_camera_ray(env);
	init_mask(&masl, color);
	light_found = 0;
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
		//mask.r += (color & 0xFF0000) * light->color_r;
		//mask.g += (color & 0x00FF00) * light->color_g;
		//mask.b += (color & 0x0000FF) * light->color_b;
		light_found = 1;
	}
	free(ray);
	return (light_found ? conv_rgb_to_int(mask.r, mask.g, mask.b) : 0);
}

unsigned int	get_light_color(t_env *env, t_ray *ray, t_object *object)
{
	unsigned int	result;

	result = 0;
	result = find_light(env, conv_rgb_to_int(object->color_r, object->color_g, object->color_b);
	return (result);
}
