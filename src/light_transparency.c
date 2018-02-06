#include "rt.h"

void	light_transparency(t_env *env, t_collision *collision, int recursion)
{
	t_ray ray;
	int tmp_color;
	int color_res;

	//if (collision->object->type != CYLINDRE && collision->object->type != SPHERE)
	//	return ;
	if (collision->distance <= .000000001)
		return ;
//	printf("transp recur: %d\n", recursion);
	ray.dir.x = collision->dir.x;
	ray.dir.y = collision->dir.y;
	ray.dir.z = collision->dir.z;
	ray.pos.x = collision->pos.x;
	ray.pos.y = collision->pos.y;
	ray.pos.z = collision->pos.z;
	vector_normalize(&ray.dir);
	tmp_color = get_pixel_color(env, &ray, recursion, collision->object);
//printf("tmp_color: %d, dir.x: %f, dir.y: %f, dir.z: %f, pos.x: %f, pos.y: %f, pos.z: %f\n", tmp_color, ray.dir.x, ray.dir.y, ray.dir.z, ray.pos.x, ray.pos.y, ray.pos.z);
	color_res = color_add(color_factor(conv_rgb_to_int(collision->color.r, collision->color.g, collision->color.b), .5), color_factor(tmp_color, .5));
	//printf("color_res: %d\n", color_res);
	collision->color.r = get_color_r(color_res);
	collision->color.g = get_color_g(color_res);
	collision->color.b = get_color_b(color_res);
}
