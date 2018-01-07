/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:01 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 17:00:49 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>

# define PLANE 0
# define TRIANGLE 1
# define RECTANGLE 2
# define SPHERE 3
# define CYLINDRE 4
# define CONE 5
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1000
# define WINDOW_NAME "cc"
# define FOV_X 60
# define FOV_Y 60
# define BG_COLOR 0
# define DEFAULT_COLOR_R 0xFF
# define DEFAULT_COLOR_G 0
# define DEFAULT_COLOR_B 0xFF

typedef struct			s_object t_object;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_light_mask
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}						t_light_mask;

typedef struct			s_color_mask
{
	float				r;
	float				g;
	float				b;
}						t_color_mask;

typedef struct			s_ray
{
	t_vector			pos;
	t_vector			dir;
}						t_ray;

typedef struct			s_collision
{
	t_color_mask		color;
	t_vector			pos;
	t_vector			dir;
	double				distance;
	t_object			*object;
}						t_collision;

typedef struct			s_camera
{
	t_vector			pos;
	t_vector			rot;
}						t_camera;

typedef struct			s_light
{
	int					power;
	int					color_r;
	int					color_g;
	int					color_b;
	t_vector			pos;
	t_vector			rot;
	char				has_parsed_position;
	char				has_parsed_color;
	char				has_parsed_rotation;
	char				has_parsed_power;
}						t_light;

typedef struct			s_material
{
	char				*name;
	int					color_r;
	int					color_g;
	int					color_b;
	t_vector			pos;
	t_vector			rot;
	int					scale;
	char				has_parsed_position;
	char				has_parsed_color;
	char				has_parsed_scale;
	char				has_parsed_rotation;	
}						t_material;

typedef struct			s_define
{
	char				nb_value;
	int					x;
	int					y;
	int					z;
	char				*name;
}						t_define;

typedef struct			s_object
{
	int					type;
	float				color_r;
	float				color_g;
	float				color_b;
	t_vector			rot;
	int					scale;
	char				has_parsed_position;
	char				has_parsed_color;
	char				has_parsed_scale;
	char				has_parsed_rotation;
	t_vector			pos;
}						t_object;

typedef struct			s_quadratic
{
	double				a;
	double				b;
	double				c;
}						t_quadratic;

typedef struct				s_object_list
{
	struct s_object_list	*next;
	struct s_object			*object;
}							t_object_list;

typedef struct				s_material_list
{
	struct s_material_list	*next;
	struct s_material		*material;
}							t_material_list;

typedef struct			s_light_list
{
	struct s_light_list	*next;
	struct s_light		*light;
}						t_light_list;

typedef struct				s_define_list
{
	struct s_define_list	*next;
	struct s_define			*define;
}							t_define_list;

typedef struct					s_obj_vertex_list
{
	struct s_obj_vertex_list	*next;
	t_vector					vertex;
}								t_object_vertex_list;

typedef struct					s_obj_normal_list
{
	struct s_obj_normal_list	*next;
	t_vector					normal;
}								t_obj_normal_list;

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*mlx_img_ptr;
	char				*mlx_img_data;
	int					bpp;
	t_object_list		*object_list;
	t_light_list		*light_list;
	t_material_list		*material_list;
	t_define_list		*define_list;
	t_camera			*camera;
	unsigned int		light_ambient;
	int					specular;
	t_obj_vertex_list	obj_vertex_list;
	t_obj_normal_list	obj_normal_list;
}						t_env;

void					parse(t_env *env, int argc, char **argv);
void					parse_general_object(t_env *env, char **datas);
void					parse_object_color(t_env *env, t_object *object, char **datas, int *start);
void					parse_object_light(t_env *env, char **datas);
void					parse_object_position(t_env *env, t_object *object, char **datas,
						int *start);
void					parse_object_rotation(t_env *env, t_object *object, char **datas,
						int *start);
void					parse_object_scale(t_env *env, t_object *object, char **datas, int *start);
void					parse_args(t_env *env, int fd);
void					list_add_object(t_env *env, t_object *object);
void					list_add_light(t_env *env, t_light *light);
void					list_add_define(t_env *env, t_define *define);
void					init_env(t_env *env);
char					*replace_tab_by_space(char *str);
void					free_2d_array(char **str);
void					init_window(t_env *env);
void					vector_rotate_x(t_vector *vector, float angle);
void					vector_rotate_y(t_vector *vector, float angle);
void					vector_rotate_z(t_vector *vector, float angle);
double					vector_length(t_vector *vector);
void					vector_normalize(t_vector *vector);
void					render(t_env *env);
void					pixel_put(t_env *env, int x, int y, unsigned int color);
int						check_collision(t_env *env, t_ray *ray, t_collision *collision);
t_ray					*create_camera_ray(t_env *env);
void					collide_sphere(t_ray *ray, t_object *object,
						t_collision *collision);
void					collide_cylinder(t_ray *ray, t_object *object,
						t_collision *collision);
double					dot_product(t_vector *v1, t_vector *v2);
int						solve_quadratic(t_quadratic *quadratic,
						double *distance);
double					dmax(double a, double b);
double					dmin(double a, double b);
void					parse_camera(t_env *env, char **datas);
unsigned int			conv_rgb_to_int(int r, int g, int b);
unsigned int			get_pixel_color(t_env *env, t_ray *ray);
int						get_color_r(unsigned int color);
int						get_color_g(unsigned int color);
int						get_color_b(unsigned int color);
t_collision				*create_collision(void);
void					free_collision(t_collision *collision);
unsigned int			get_light_color(t_env *env, t_collision *collision);
double					vector_angle(t_vector *v1, t_vector *v2);
void					get_sphere_normal(t_vector *vector, t_object *object, t_vector *pos);
void					get_normal_vector(t_vector *result, t_object *object, t_collision *collision);
t_object				*create_object(void);
void					get_cylinder_normal(t_vector *vector, t_object *object, t_vector *pos);
int						check_piece_attribut_name(char *s1, char *s2);
int						ft_strncmp_ignrcase(char *s1, char *s2, int n);
void					collide_cone(t_ray *ray, t_object *object,
						t_collision *collision);
void					get_cone_normal(t_vector *vector, t_object *object, t_vector *pos);
void					collide_plane(t_ray *ray, t_object *object,
						t_collision *collision);
void					get_plane_normal(t_vector *vector, t_object *object, t_collision *collision);
void					vector_rotate(t_vector *vector, t_vector *angle);
void					vector_unrotate(t_vector *vector, t_vector *angle);
void					list_add_material(t_env *env, t_material *material);
t_material				*find_material(t_env *env, char *str);
void					fill_object_with_material(t_object *object,
						t_material *material);
void					parse_light(t_env *env, char **datas);
void					parse_material(t_env *env, char **str);
t_material				*create_material(void);
double					vector_distance(t_vector *pos1, t_vector *pos2);
void					add_specular(t_collision *collision, t_vector *normal,
						t_vector *light_dir);
long					epoch_millis(void);
void					put_timer(long start, long end, char *str);
t_define				*find_define(t_env *env, char *str);
void					parse_define(t_env *env, char **datas);
void					fill_object_color_define(t_object *object, t_define *define, int *i);
void					fill_object_position_define(t_object *object, t_define *define, int *i);
void					fill_object_rotation_define(t_object *object, t_define *define, int *i);

#endif
