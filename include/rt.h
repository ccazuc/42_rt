/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:01 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 12:07:42 by ccazuc           ###   ########.fr       */
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
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}						t_color_mask;

typedef struct			s_ray
{
	t_vector			*pos;
	t_vector			*dir;
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

typedef struct			s_object
{
	int					type;
	int					color_r;
	int					color_g;
	int					color_b;
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

typedef struct			s_rtlist
{
	struct s_rtlist		*next;
	struct s_object		*object;
}						t_rtlist;

typedef struct			s_rtllist
{
	struct s_rtllist	*next;
	struct s_light		*light;
}						t_rtllist;

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*mlx_img_ptr;
	char				*mlx_img_data;
	int					bpp;
	t_rtlist			*object_list;
	t_rtllist			*light_list;
	t_camera			*camera;
	unsigned int		light_ambient;
}						t_env;

void					parse(t_env *env, int argc, char **argv);
void					parse_general_object(t_env *env, char **datas);
void					parse_color(t_object *object, char **datas, int *start);
void					parse_light(t_env *env, char **datas);
void					parse_position(t_object *object, char **datas,
						int *start);
void					parse_rotation(t_object *object, char **datas,
						int *start);
void					parse_scale(t_object *object, char **datas, int *start);
void					parse_args(t_env *env, int fd);
void					list_add_object(t_env *env, t_object *object);
void					list_add_light(t_env *env, t_light *light);
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
t_vector				*get_sphere_normal(t_object *object, t_vector *pos);
t_vector				*get_normal_vector(t_object *object, t_collision *collision);
t_object				*create_object(void);
t_vector				*get_cylinder_normal(t_object *object, t_vector *pos);
int						check_piece_attribut_name(char *s1, char *s2);
int						ft_strncmp_ignrcase(char *s1, char *s2, int n);
void					collide_cone(t_ray *ray, t_object *object,
						t_collision *collision);
t_vector				*get_cone_normal(t_object *object, t_vector *pos);
void					collide_plane(t_ray *ray, t_object *object,
						t_collision *collision);
t_vector				*get_plane_normal(t_object *object, t_collision *collision);
void					vector_rotate(t_vector *vector, t_vector *angle);

#endif
