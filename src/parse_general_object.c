/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 08:58:04 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"	

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
}

void	parse_general_object(t_env *env, char **datas)
{
	int			i;
	t_object	*object;
	int			len;

	len = ft_array_len(datas);
	(void)env;
	printf("parse_general_object start\n");
	if (!(object = malloc(sizeof(*object))))
		ft_exit("Error, of out memory.", -1);
	set_object_type(object, datas[0]);
	i = 0;
	while (++i < len)
	{
		printf("word: %s\n", datas[i]);
		if (!ft_strcmp_ignrcase(datas[i], "color"))
			parse_color(object, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "pos"))
			parse_position(object, datas, &i);
		else if (!ft_strcmp_ignrcase(datas[i], "rot"))
			parse_rotation(object, datas, &i);
		else
		{
			ft_exit("Error, invalid file.", -1);
		}
	}
	free_2d_array(datas);
	list_add_object(env, object);
}
