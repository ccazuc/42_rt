/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:50:28 by ccazuc            #+#    #+#             */
/*   Updated: 2018/09/15 14:54:58 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	create_light_sphere(t_env *env, t_light *light)
{
	t_object	*object;

	object->type = SPHERE;
	object->color_r = 0;
	object->color_g = 0;
	object->color_b = 0;
	object->scale = 1;
	object->transparency = 0;
	object->reflection = 0;
	object->pos = light->pos;
	object->is_light = 1;
}
