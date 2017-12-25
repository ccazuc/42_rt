#include "rt.h"

static void	parse_material_name(t_material *material, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < 'a' && str [i] > 'z' && str[i] < 'A' && str[i] > 'Z')
			ft_exit("Error, invalid file. Invalid material name.", EXIT_FAILURE);
	material->name = ft_strdup(str);
}

static void	parse_material_color(t_material *material, char **datas, int *start)
{
	if (material->has_parsed_color)
		ft_exit("Error, invalid file. Color duplicate for a material."
		, EXIT_FAILURE);
	printf("Color: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for color.", -1);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Color's parameters are invalid."
		, EXIT_FAILURE);
	object->color_r = ft_atoi(datas[*start + 1]);
	object->color_g = ft_atoi(datas[*start + 2]);
	object->color_b = ft_atoi(datas[*start + 3]);
	if (object->color_r < 0 || object->color_g < 0 || object->color_b < 0)
		ft_exit("Error, invalid file. Color's value is invalid."
		, EXIT_FAILURE);
	*start += 3;
	material->has_parsed_color = 1;
}

static	void	parse_material_rotation(t_material *material, char **datas, int *start)
{
	if (material->has_parsed_rotation)
		ft_exit("Error, invalid file. Rotation duplicate for a material."
		, EXIT_FAILURE);
	printf("Rotation: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for rotation."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Rotation's parameters are invalid."
		, EXIT_FAILURE);
	material->rot.x = ft_atoi(datas[*start + 1]);
	material->rot.y = ft_atoi(datas[*start + 2]);
	material->rot.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	material->has_parsed_rotation = 1;
}

static void		parse_material_position(t_material *material, char **datas, int *start)
{
	if (material->has_parsed_position)
		ft_exit("Error, invalid file. Position duplicate for a material."
		, EXIT_FAILURE);
	printf("Position: 1: %s, 2: %s, 3: %s\n", datas[*start + 1], datas[*start + 2], datas[*start + 3]);
	if (!datas[*start + 1] || !datas[*start + 2] || !datas[*start + 3])
		ft_exit("Error, invalid file. Not enough parameters for position."
		, EXIT_FAILURE);
	if (!ft_str_isdigit(datas[*start + 1]) || !ft_str_isdigit(datas[*start + 2])
	|| !ft_str_isdigit(datas[*start + 3]))
		ft_exit("Error, invalid file. Position's parameters are invalid."
		, EXIT_FAILURE);
	material->pos.x = ft_atoi(datas[*start + 1]);
	material->pos.y = ft_atoi(datas[*start + 2]);
	material->pos.z = ft_atoi(datas[*start + 3]);
	*start += 3;
	material->has_parsed_position = 1;
}

void		parse_material(t_env *env, char **str)
{
	int			i;
	t_material	*material;
	int			len;

	len = ft_array_len(datas);
	if (len <= 1)
		ft_exit("Error, invalid file. Invalid material.", EXIT_FAILURE);
	material = create_material();
	check_material_name(str[1]);
	i = 1;
	while (++i < len)
		if (check_piece_attribut_name(datas[i], "color"))
			parse_material_color(material, datas, &i);
		else if (check_piece_attribut_name(datas[i], "position"))
			parse_material_position(material, datas, &i);
		else if (check_piece_attribut_name(datas[i], "rotation"))
			parse_material_rotation(material, datas, &i);
		else if (check_piece_attribut_name(datas[i], "scale"))
			parse_material_scale(material, datas, &i);
		else if (check_piece_attribut_name(datas[i], "reflection"))
			parse_material_reflection(material, datas, &i);
		else if (check_piece_attribut_name(datas[i], "refraction"))
			parse_material_refraction(material, datas, &i);
		else
			ft_exit("Error, invalid file. Unknown material attribut.", EXIT_FAILURE);
	list_add_material(env, material);
}