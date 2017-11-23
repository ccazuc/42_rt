/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 08:37:57 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"	

static void	init_object(t_object *object)
{
	object->has_parsed_color = 0;
	object->has_parsed_position = 0;
	object->has_parsed_rotation = 0;
	object->has_parsed_scale = 0;
	object->rot_x = 0;
	object->rot_y = 0;
	object->rot_z = 0;
	object->color_r = DEFAULT_COLOR_R;
	object->color_g = DEFAULT_COLOR_G;
	object->color_b = DEFAULT_COLOR_B;
	object->scale = 1;
}

static void	set_object_type(t_object *object, char *datas)
{
	if (!ft_strcmp_ignrcase(datas, "cube"))
		object->type = CUBE;
	else if (!ft_strcmp_ignrcase(datas, "sphere"))
		object->type = SPHERE;
	else if (!ft_strcmp_ignrcase(datas, "cylindre"))
		object->type = CYLINDRE;
	else if (!ft_strcmp_ignrcase(datas, "triangle"))
		object->type = TRIANGLE;
	else if (!ft_strcmp_ignrcase(datas, "rectangle"))
		object->type = RECTANGLE;
	init_object(object);
}

static void	check_object_state(t_object *object)
{
	if (!object->has_parsed_color)
		ft_putstr("Warning, found object without color.\n");
	if (!object->has_parsed_position)
		ft_exit("Error, invalid file. Position not found for an object.",
		EXIT_FAILURE);
	if (!object->has_parsed_rotation)
		ft_putrstr("Warning, found an object without rotation.\n");
	if (!object->has_parsed_scale)
		ft_putstr("Warning, found an object without scale.\n");
}

void	parse_general_object(t_env *env, char **datas)
{
	int			i;
	t_object	*object;
	int			len;

	len = ft_array_len(datas);
	if (!(object = malloc(sizeof(*object))))
		ft_exit("Error, of out memory.", EXIT_FAILURE);
	set_object_type(object, datas[0]);
	i = 0;
	while (++i < len)
		if (!ft_strcmp_ignrcase(datas[i], "color"))
			parse_color(object, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "pos"))
			parse_position(object, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "rot"))
			parse_rotation(object, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "scale"))
			parse_scale(object, datas, &i);
		else
			ft_exit("Error, invalid file.", EXIT_FAILURE);
	check_object_state(object);
	list_add_object(env, object);
}
