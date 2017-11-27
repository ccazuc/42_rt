/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:56:06 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/27 15:37:19 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	find_light(t_env *env, t_collision *collision)
{
	t_rtllist		*list;
	t_ray			*ray;
	t_collision		find_collision;
	t_vector		*normal;
	double			norm_angle;

	list = env->light_list;
	ray = create_camera_ray(env);
	ray->pos->x = collision->pos.x;
	ray->pos->y = collision->pos.y;
	ray->pos->z = collision->pos.z;
	normal = get_normal_vector(collision->object, &collision->pos);
	while (list)
	{
		ray->dir->x = list->light->pos_x - collision->pos.x;
		ray->dir->y = list->light->pos_y - collision->pos.y;
		ray->dir->z = list->light->pos_z - collision->pos.z;
		vector_normalize(ray->dir);
		if (check_collision(env, ray, &find_collision) && find_collision.object)
		{
			printf("Obstacle found\n");
			list = list->next;
			continue ;
		}
		norm_angle = dmax(0, cos(vector_angle(ray->dir, normal)));
		//printf("r before: %u\n", collision->color.r);
		//printf("normal x: %f, y: %f, z: %f\n", get_normal_vector(collision->object, &collision->pos)->x, get_normal_vector(collision->object, &collision->pos)->y, get_normal_vector(collision->object, &collision->pos)->z);
		//printf("angle: %f\n", vector_angle(ray->dir, get_normal_vector(collision->object, collision->object->pos)));
	//	printf("light color | r: %u, g: %u, b: %u, power: %d\n", list->light->color_r, list->light->color_g, list->light->color_b, list->light->power);
		//if (dmax(cos(vector_angle(ray->dir, normal)), 0)) {
		//printf("r bad: %f\n", dmin(cos(vector_angle(ray->dir, normal)), 0) * list->light->power * list->light->color_r / 255 * collision->object->color_r);
		//printf("r good: %f\n", dmax(cos(vector_angle(ray->dir, normal)), 0) * list->light->power * list->light->color_r * collision->object->color_r / 755);}

		if (norm_angle) {
		//printf("norm_angle %f\n", norm_angle);
		//printf("color_r: %d, object_r: %f, mult: %f\n", list->light->color_r / 255, collision->object->color_r / 255.,
		//(list->light->color_r / 255.) * (collision->object->color_r / 255.));
		//printf("r: %d\n", list->light->power * list->light->color_r / 255 * collision->object->color_r / 255);
		//printf("r: %f, g: %f, b: %f\n",
		//norm_angle * dmin(1, list->light->power * list->light->color_r / 255 * collision->object->color_r / 255) * 255,
		//norm_angle * dmin(1, list->light->power * list->light->color_g / 255 * collision->object->color_g / 255) * 255,
		//norm_angle * dmin(1, list->light->power * list->light->color_b / 255 * collision->object->color_b / 255) * 255);
		collision->color.r = dmin(255, collision->color.r + norm_angle * list->light->power * list->light->color_r / 255 * collision->object->color_r / 255);
		collision->color.g = dmin(255, collision->color.g + norm_angle * list->light->power * list->light->color_g / 255 * collision->object->color_g / 255);
		collision->color.b = dmin(255, collision->color.b + norm_angle * list->light->power * list->light->color_b / 255 * collision->object->color_b / 255);}
		//collision->color.r += norm_angle * list->light->power * list->light->color_r / 255 * collision->object->color_r / 255.;
		//collision->color.g += norm_angle * list->light->power * list->light->color_g / 255 * collision->object->color_g / 255.;
		//collision->color.b += norm_angle * list->light->power * list->light->color_b / 255 * collision->object->color_b / 255.;}

		/*collision->color.r += norm_angle * list->light->power * list->light->color_r * collision->object->color_r / (755 * list->light->power / 2);
		//printf("r after: %u\n", collision->color.r);
		collision->color.g += norm_angle * list->light->power * list->light->color_g * collision->object->color_g / (755 * list->light->power / 2);
		collision->color.b += norm_angle * list->light->power * list->light->color_b * collision->object->color_b / (755 * list->light->power / 2);*/

		list = list->next;
	}
	//printf("r: %d, g: %d, b: %d\n", collision->color.r, collision->color.g, collision->color.g);
	free(normal);
	free(ray);
	return (conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b));
}

void			check_ambient(t_env *env, t_collision *collision)
{
	if (collision->color.r < env->light_ambient)
			collision->color.r = get_color_r(env->light_ambient);
	if (collision->color.g < env->light_ambient)
			collision->color.g = get_color_g(env->light_ambient);
	if (collision->color.b < env->light_ambient)
			collision->color.b = get_color_b(env->light_ambient);
}

unsigned int	get_light_color(t_env *env, t_collision *collision)
{
	unsigned int	color;
	collision->color.r = 0;
	collision->color.g = 0;
	collision->color.b = 0;
	color = find_light(env, collision);
	//if (color != 0)
	//printf("light final value: %u\n", find_light(env, collision));
	//check_ambient(env, collision);
	return (conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b));
}
