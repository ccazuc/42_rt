/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 11:46:28 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_object_type(t_object *object, char *datas)
{
	if (!ft_strcmp_ignrcase(datas, "plane"))
		object->type = PLANE;
	else if (!ft_strcmp_ignrcase(datas, "sphere"))
		object->type = SPHERE;
	else if (!ft_strcmp_ignrcase(datas, "cylindre"))
		object->type = CYLINDRE;
	else if (!ft_strcmp_ignrcase(datas, "triangle"))
		object->type = TRIANGLE;
	else if (!ft_strcmp_ignrcase(datas, "rectangle"))
		object->type = RECTANGLE;
	else if (!ft_strcmp_ignrcase(datas, "cone"))
		object->type = CONE;
	else
		ft_exit("Error, invalid file. Unknown object type.", EXIT_FAILURE);
}

static void	check_object_state(t_object *object)
{
	if (!object->has_parsed_color)
		ft_putstr("Warning, found object without color.\n");
	if (!object->has_parsed_position)
		ft_exit("Error, invalid file. Position not found for an object.",
		EXIT_FAILURE);
	if (!object->has_parsed_rotation)
		ft_putstr("Warning, found an object without rotation.\n");
	if (!object->has_parsed_scale)
		ft_putstr("Warning, found an object without scale.\n");
}

static void	check_attribut(t_object *object, char **datas, int *i)
{
	t_material	*tmp;

	if (check_piece_attribut_name(datas[*i], "color"))
		parse_object_color(object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "position"))
		parse_object_position(object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "rotation"))
		parse_object_rotation(object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "scale"))
		parse_object_scale(object, datas, &);
	else if ((tmp = find_material(datas[*i]))
		fill_object_with_material(object, material, i);
	else
		ft_exit("Error, invalid file. Unknown object attribut.", EXIT_FAILURE);
}

void		parse_general_object(t_env *env, char **datas)
{
	int			i;
	t_object	*object;
	int			len;

	len = ft_array_len(datas);
	object = create_object();
	set_object_type(object, datas[0]);
	i = 0;
	while (++i < len)
		check_attribut(object, datas, &i);
	check_object_state(object);
	list_add_object(env, object);
}
