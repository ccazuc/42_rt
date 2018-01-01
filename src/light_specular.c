include "rt.h"

void	add_specular(t_env *env, t_collision *collision, t_vector *normal, t_vector *light_dir)
{
	int		value;

	value = cos(dabs(vector_angle(&collision->ray.dir, normal) - vector_angle(light_dir, normal)))
	collision->color.r = dmin(255, collision->color.r + value);
	collision->color.g = dmin(255, collision->color.g + value);
	collision->color.b = dmin(255, collision->color.b + value);
}