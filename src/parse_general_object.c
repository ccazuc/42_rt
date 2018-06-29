/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:11 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/29 13:35:35 by ccazuc           ###   ########.fr       */
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
	else if (!ft_strcmp_ignrcase(datas, "rectangle"))
		object->type = RECTANGLE;
	else if (!ft_strcmp_ignrcase(datas, "cone"))
		object->type = CONE;
	else if (!ft_strcmp_ignrcase(datas, "triangle"))
		object->type = TRIANGLE;
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

static void	check_attribut(t_env *env, t_object *object, char **datas, int *i)
{
	t_material	*material;

	if (check_piece_attribut_name(datas[*i], "color"))
		parse_object_color(env, object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "position"))
		parse_object_position(env, object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "rotation"))
		parse_object_rotation(env, object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "scale"))
		parse_object_scale(env, object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "reflection"))
		parse_object_reflection(env, object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "transparency"))
		parse_object_transparency(env, object, datas, i);
	else if ((material = find_material(env, datas[*i])))
		fill_object_with_material(object, material);
	else
		ft_exit("Error, invalid file. Unknown object attribut.", EXIT_FAILURE);
}

void		parse_general_object(t_env *env, char **datas)
{
	int			i;
	t_object	*object;
	int			len;

	len = ft_array_len(datas);
	if (len == 0)
		return ;
	object = create_object();
	set_object_type(object, datas[0]);
	i = 0;
	while (++i < len)
		check_attribut(env, object, datas, &i);
	check_object_state(object);
	list_add_object(env, object);
}
