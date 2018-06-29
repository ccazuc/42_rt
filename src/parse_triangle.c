/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:29:11 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/29 13:50:35 by ccazuc           ###   ########.fr       */
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
	if (!object->has_parsed_position || !object->has_parsed_rotation ||
	!object->has_parsed_p3)
		ft_exit("Error, invalid file. Found a triangle without 3 points.",
		EXIT_FAILURE);
}

static void	check_attribut(t_env *env, t_object *object, char **datas, int *i)
{
	if (check_piece_attribut_name(datas[*i], "color"))
		parse_object_color(env, object, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "p1"))
		parse_triangle_p1(object, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "p2"))
		parse_triangle_p2(object, datas, i);
	else if (!ft_strcmp_ignrcase(datas[*i], "p3"))
		parse_triangle_p3(object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "reflection"))
		parse_object_reflection(env, object, datas, i);
	else if (check_piece_attribut_name(datas[*i], "transparency"))
		parse_object_transparency(env, object, datas, i);
	else
		ft_exit("Error, invalid file. Unknown object attribut.", EXIT_FAILURE);
}

void		parse_triangle(t_env *env, char **datas)
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
