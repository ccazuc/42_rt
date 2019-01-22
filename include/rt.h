/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:01 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/22 22:34:54 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "../libpng/png.h"
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>

# define PLANE 0
# define TRIANGLE 1
# define RECTANGLE 2
# define SPHERE 3
# define CYLINDRE 4
# define CONE 5
# define WINDOW_NAME "cc c le air the"
# define FOV_X 60
# define FOV_Y 60
# define BG_COLOR 0
# define DEFAULT_COLOR_R 0xFF
# define DEFAULT_COLOR_G 0
# define DEFAULT_COLOR_B 0xFF
# define REFLECTION_DEPTH 10

typedef struct s_object			t_object;
typedef struct s_worker			t_worker;

typedef struct					s_png_datas
{
	FILE						*fp;
	char						*file_name;
	png_structp					png_ptr;
	png_infop					info_ptr;
	png_text					title_text;
	png_bytep					row;
}								t_png_datas;

typedef struct					s_vector
{
	double						x;
	double						y;
	double						z;
}								t_vector;

typedef struct					s_color_mask
{
	double						r;
	double						g;
	double						b;
}								t_color_mask;

typedef struct					s_texu
{
	t_color_mask				*buf;
	size_t						size_x;
	size_t						size_y;
	size_t						offs_x;
	size_t						offs_y;
	double						scale;
}								t_texu;

typedef struct					s_ray
{
	t_vector					pos;
	t_vector					dir;
}								t_ray;

typedef struct					s_collision
{
	t_color_mask				color;
	t_vector					pos;
	t_vector					dir;
	double						distance;
	t_object					*object;
}								t_collision;

typedef struct					s_camera
{
	t_vector					pos;
	t_vector					rot;
}								t_camera;

typedef struct					s_light
{
	int							power;
	int							color_r;
	int							color_g;
	int							color_b;
	t_vector					pos;
	t_vector					rot;
	char						is_direc;
	char						has_parsed_position;
	char						has_parsed_color;
	char						has_parsed_rotation;
	char						has_parsed_power;
}								t_light;

typedef struct					s_triangle_collision
{
	t_vector					e1;
	t_vector					e2;
	t_vector					p;
	t_vector					q;
	t_vector					t;
	double						det;
	double						u;
	double						v;
}								t_triangle_collision;

typedef struct					s_material
{
	char						*name;
	int							color_r;
	int							color_g;
	int							color_b;
	t_vector					pos;
	t_vector					rot;
	int							scale;
	float						reflection;
	float						transparency;
	float						refraction;
	char						has_parsed_position;
	char						has_parsed_color;
	char						has_parsed_scale;
	char						has_parsed_rotation;
	char						has_parsed_reflection;
	char						has_parsed_transparency;
	char						has_parsed_refraction;
}								t_material;

typedef struct					s_define
{
	char						nb_value;
	int							x;
	int							y;
	int							z;
	char						*name;
}								t_define;

struct							s_object
{
	int							type;
	float						color_r;
	float						color_g;
	float						color_b;
	t_vector					rot;
	t_texu						*texu;
	t_vector					texu_size;
	t_vector					texu_offs;
	int							scale;
	char						has_parsed_position;
	char						has_parsed_color;
	char						has_parsed_scale;
	char						has_parsed_rotation;
	char						has_parsed_reflection;
	char						has_parsed_transparency;
	char						has_parsed_refraction;
	char						has_parsed_gi;
	char						has_parsed_texture;
	float						transparency;
	float						reflection;
	float						refraction;
	t_vector					pos;
	t_vector					p3;
	char						has_parsed_p3;
	char						has_gi;
	char						has_texture;
	char						texture_id;
};

typedef struct					s_quadratic
{
	double						a;
	double						b;
	double						c;
}								t_quadratic;

typedef struct					s_object_list
{
	struct s_object_list		*next;
	struct s_object				*object;
}								t_object_list;

typedef struct					s_material_list
{
	struct s_material_list		*next;
	struct s_material			*material;
}								t_material_list;

typedef struct					s_light_list
{
	struct s_light_list			*next;
	struct s_light				*light;
}								t_light_list;

typedef struct					s_define_list
{
	struct s_define_list		*next;
	struct s_define				*define;
}								t_define_list;

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

typedef struct					s_env
{
	void						*mlx_ptr;
	void						*mlx_win;
	void						*mlx_img_ptr;
	char						*mlx_img_data;
	int							bpp;
	int							id;
	struct s_env				**env_list;
	t_object_list				*object_list;
	t_light_list				*light_list;
	t_material_list				*material_list;
	t_define_list				*define_list;
	t_camera					*camera;
	unsigned int				light_ambient;
	float						ambient_power;
	int							specular;
	t_obj_normal_list			obj_normal_list;
	t_worker					*thread_list;
	int							nb_thread;
	int							draw_finished;
	long						render_start;
	char						sepia_filter;
	char						grayscale_filter;
	char						fsaa;
	char						*fsaa_img;
	int							window_width;
	int							window_height;
	int							fsaa_factor;
	char						*file_name;
	int							was_loaded;
	int							n_sample_ray;
}								t_env;

struct							s_worker
{
	int							current_index;
	long						start;
	long						end;
	char						draw_finished;
	t_env						*env;
	pthread_t					thread;
	int							id;
	int							line_drawn;
};

void							parse(t_env *env, char *file_name);
void							parse_general_object(t_env *env, char **datas);
void							parse_object_color(t_env *env, t_object *object,
								char **datas, int *start);
void							parse_object_light(t_env *env, char **datas);
void							parse_object_position(t_env *env,
								t_object *object, char **datas,
								int *start);
void							parse_object_rotation(t_env *env,
								t_object *object, char **datas, int *start);
void							parse_object_scale(t_env *env, t_object *object,
								char **datas, int *start);
void							parse_object_gi(t_env *env, t_object *object,
								char **datas, int *start);
void							parse_args(t_env *env, int fd);
void							list_add_object(t_env *env, t_object *object);
void							list_add_light(t_env *env, t_light *light);
void							list_add_define(t_env *env, t_define *define);
void							init_env(t_env *env);
char							*replace_tab_by_space(char *str);
void							free_2d_array(char **str);
void							init_window(t_env *env);
void							vector_rotate_x(t_vector *vector, float angle);
void							vector_rotate_y(t_vector *vector, float angle);
void							vector_rotate_z(t_vector *vector, float angle);
double							vector_length(t_vector *vector);
void							vector_normalize(t_vector *vector);
void							render(t_env **env, int i, char should_hook);
void							pixel_put(t_env *env, int x,
								int y, unsigned int color);
int								check_collision(t_env *env, t_ray *ray,
								t_collision *collision,
								t_object *previous_object);
t_ray							*create_camera_ray(t_env *env);
void							collide_sphere(t_ray *ray, t_object *object,
								t_collision *collision,
								t_object *previous_object);
void							collide_cylinder(t_ray *ray, t_object *object,
								t_collision *collision,
								t_object *previous_object);
double							dot_product(t_vector *v1, t_vector *v2);
int								solve_quadratic(t_quadratic *quadratic,
								double *distance);
double							dmax(double a, double b);
double							dmin(double a, double b);
void							parse_camera(t_env *env, char **datas);
unsigned int					conv_rgb_to_int(int r, int g, int b);
unsigned int					get_pixel_color(t_env *env, t_ray *ray,
								int recursion, t_object *previous_object);
int								get_color_r(unsigned int color);
int								get_color_g(unsigned int color);
int								get_color_b(unsigned int color);
t_collision						*create_collision(void);
void							free_collision(t_collision *collision);
unsigned int					get_light_color(t_env *env,
								t_collision *collision, int recursion);
double							vector_angle(t_vector *v1, t_vector *v2);
void							get_sphere_normal(t_vector *vector,
								t_object *object, t_vector *pos);
void							get_normal_vector(t_vector *result,
								t_object *object, t_collision *collision);
t_object						*create_object(void);
void							get_cylinder_normal(t_vector *vector,
								t_object *object, t_vector *pos);
int								check_piece_attribut_name(char *s1, char *s2);
int								ft_strncmp_ignrcase(char *s1, char *s2, int n);
void							collide_cone(t_ray *ray, t_object *object,
								t_collision *collision,
								t_object *previous_object);
void							get_cone_normal(t_vector *vector,
								t_object *object, t_vector *pos);
void							collide_plane(t_ray *ray, t_object *object,
								t_collision *collision,
								t_object *previous_object);
int								color_add(int c1, int c2);
int								check_reflection(t_env *env,
								t_collision *collision,
								t_vector *normal, int recursion);
void							get_plane_normal(t_vector *vector,
								t_object *object, t_collision *collision);
void							vector_rotate(t_vector *vector,
								t_vector *angle);
void							vector_unrotate(t_vector *vector,
								t_vector *angle);
void							list_add_material(t_env *env,
								t_material *material);
t_material						*find_material(t_env *env, char *str);
void							fill_object_with_material(t_object *object,
								t_material *material);
void							parse_light(t_env *env, char **datas);
void							parse_material(t_env *env, char **str);
t_material						*create_material(void);
double							vector_distance(t_vector *pos1, t_vector *pos2);
void							add_specular(t_collision *collision,
								t_vector *normal, t_vector *light_dir);
long							epoch_millis(void);
void							put_timer(long start, long end, char *str);
t_define						*find_define(t_env *env, char *str);
void							parse_define(t_env *env, char **datas);
void							fill_object_color_define(t_object *object,
								t_define *define, int *i);
void							fill_object_position_define(t_object *object,
								t_define *define, int *i);
void							fill_object_rotation_define(t_object *object,
								t_define *define, int *i);
void							fill_object_reflection_define(t_object *object,
								t_define *define, int *i);
void							fill_object_transparency_define(
								t_object *object, t_define *define, int *i);
int								color_factor(int color, double factor);
void							light_transparency(t_env *env,
								t_collision *collision, int recursion);
void							create_thread(t_env *env);
int								loop_handler(void *data);
void							fill_ray(t_env *env, t_ray *ray, int x, int y);
void							draw_progress_bar(t_env *env, int line_drawn);
int								get_sepia_color(int rgb);
int								get_grayscale_color(int rgb);
void							save_image(t_env *env);
t_light							*create_light(void);
void							parse_material_attribute(t_material *material,
								char **datas, int *i);
void							parse_object_reflection(t_env *env,
								t_object *object, char **datas, int *start);
void							parse_object_transparency(t_env *env,
								t_object *object, char **datas, int *start);
void							parse_material_color(t_material *material,
								char **datas, int *start);
void							parse_material_rotation(t_material *material,
								char **datas, int *start);
void							parse_material_position(t_material *material,
								char **datas, int *start);
int								get_shadow_color(t_env *env,
								t_collision *collision,
								t_ray *ray, t_light *light);
void							find_light(t_env *env,
								t_collision *collision, t_vector *normal);
int								key_up_handler(int keycode, void *params);
void							move_forward(t_env *env);
void							move_backward(t_env *env);
void							rotate_left(t_env *env);
void							rotate_right(t_env *env);
void							rotate_up(t_env *env);
void							rotate_down(t_env *env);
void							reset_window(t_env *env);
void							free_threads(t_env *env);
void							parse_config(t_env *env, char **datas);
void							parse_config_thread(t_env *env,
								char **datas, int *start);
void							parse_config_ambient(t_env *env,
								char **datas, int *start);
void							parse_config_window_width(t_env *env,
								char **datas, int *start);
void							parse_config_sample_ray(t_env *env,
								char **datas, int *start);

void							parse_config_window_height(t_env *env,
								char **datas, int *start);
void							parse_config_filter_sepia(t_env *env,
								char **datas, int *start);
void							parse_config_filter_grayscale(t_env *env,
								char **datas, int *start);
void							parse_material_scale(t_material *material,
								char **datas, int *start);
void							parse_material_reflection(t_material *material,
								char **datas, int *start);
void							parse_material_transparency(t_material
								*material, char **datas, int *start);
void							pixel_put_fsaa(t_env *env, int x, int y,
								unsigned int color);
void							parse_config_fsaa(t_env *env, char **datas
								, int *start);
unsigned int					get_pixel(t_env *env, char *img, int x
								, int y);
void							process_fsaa(t_env *env);
void							get_triangle_normal(t_vector *vector
								, t_object *object,	t_collision *collision);
void							collide_triangle(t_ray *ray, t_object *object,
								t_collision *collision, t_object *previous_object);
void							parse_triangle_p1(t_object *object, char **datas, int *start);
void							parse_triangle_p2(t_object *object, char **datas, int *start);
void							parse_triangle_p3(t_object *object, char **datas, int *start);
void							parse_triangle(t_env *env, char **datas);
void							reload_file(t_env *env);
void							fill_object_refraction_define(t_object *object,
								t_define *define, int *i);
void							parse_object_refraction(t_env *env, t_object *object,
								char **datas, int *start);
void							parse_material_refraction(t_material *material,
								char **datas, int *start);
void							fill_object_refraction_define(t_object *object,
								t_define *define, int *i);
t_vector						add_vector(t_vector const a, t_vector const b);
t_vector						sub_vector(t_vector const a, t_vector const b);
t_vector						mul_vector(t_vector const a, float const b);
int								check_refraction(t_env *env, t_collision *collision,
								t_vector *normal, int recursion);
void							fill_light_data(t_collision *collision,
								t_light *light, double norm_angle);
void							init_find_light_loop_datas(t_ray *ray,
								t_light *light, t_collision *collision);
t_color_mask					glob_illum(t_env *env,
								t_vector const obj_hit,
								t_vector const obj_normal);
t_color_mask					texture_checkboard(t_vector hit_pos,
								t_vector rot,
								t_vector const offs,
								t_vector const size);
void							parse_object_texture(t_env *env, t_object *object
								, char **datas, int *start);
t_vector						get_x_normal(t_vector rot);
t_vector						get_y_normal(t_vector rot);
t_vector						get_z_normal(t_vector rot);
t_color_mask					get_texu_pxl_sphere(t_collision *hit);
t_color_mask					get_texu_pxl_cylinder(t_collision *hit);
t_color_mask					get_object_color(t_collision *hit);
t_texu							*load_bmp(char const *file);

#endif
