/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 15:12:14 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"	

void	set_has_parsed(t_object *object)
{
	object->has_parsed_color = 0;
	object->has_parsed_position = 0;
	object->has_parsed_rotation = 0;
	object->has_parsed_scale = 0;
}

void	set_object_type(t_object *object, char *datas)
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
	set_has_parsed(object);
}

void	check_object_state(t_object *object)
{
	if (!object->has_parsed_color)
		ft_exit("Error, invalid file. Color not found for an object.", -1);
	if (!object->has_parsed_position)
		ft_exit("Error, invalid file. Position not found for an object.", -1);
	if (!object->has_parsed_rotation)
		ft_exit("Error, invalid file. Rotation not found for an object.", -1);
	if (!object->has_parsed_scale)
		ft_exit("Error, invalid file. Scale not found for an object.", -1);
}

void	parse_general_object(t_env *env, char **datas)
{
	int			i;
	t_object	*object;
	int			len;

	len = ft_array_len(datas);
	if (!(object = malloc(sizeof(*object))))
		ft_exit("Error, of out memory.", -1);
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
			ft_exit("Error, invalid file.", -1);
	check_object_state(object);
	list_add_object(env, object);
}
