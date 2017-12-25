#include "rt.h"

static void	fill_object_with_material2(t_object *object, t_material *material, int *i)
{
	if (material->has_parsed_scale)
		if (object->has_parsed_scale)
			ft_exit("Error, invalid file. Scale duplicate for an object.", EXIT_FAILURE);
		else
		{
			object->scale = material->scale;
			object->has_parsed_scale = 1;
		}
		*i += 1;
}

void	fill_object_with_material(t_object *object, t_material *material, int *i)
{
	if (material->has_parsed_color)
		if (object->has_parsed_color)
			ft_exit("Error, invalid file. Color duplicate for an object.", EXIT_FAILURE);
		else
		{
			object->color_r = material->color_r
			object->color_g = material->color_g
			object->color_b = material->color_b
			object->has_parsed_color = 1;
		}
	if (material->has_parsed_position)
		if (object->has_parsed_position)
			ft_exit("Error, invalid file. Position duplicate for an object.", EXIT_FAILURE);
		else
		{
			object->pos.x = material->pos.x;
			object->pos.y = material->pos.y;
			object->pos.z = material->pos.z;
			object->has_parsed_position = 1;
		}
	if (material->has_parsed_rotation)
		if (object->has_parsed_rotation)
			ft_exit("Error, invalid file. Rotation duplicate for an object.", EXIT_FAILURE);
		else
		{
			object->rot.x = material->rot.x;
			object->rot.y = material->rot.y;
			object->rot.w = material->rot.z;
			object->has_parsed_rotation = 1;
		}
		fill_object_with_material2(object, material, i);
}