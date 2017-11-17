/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:01 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/17 13:57:25 by ccazuc           ###   ########.fr       */
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

# define CUBE 0
# define TRIANGLE 1
# define RECTANGLE 2
# define SPHERE 3
# define CYLINDRE 4
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define WINDOW_NAME "cc"
# define FOV_X 60
# define FOV_Y 60

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_ray
{
	t_vector			*pos;
	t_vector			*dir;
}						t_ray;

typedef struct			s_camera
{
	int					pos_x;
	int					pos_y;
	int					pos_z;
	int					rot_x;
	int					rot_y;
	int					rot_z;
}						t_camera;

typedef struct			s_object
{
	int					type;
	int					color_r;
	int					color_g;
	int					color_b;
	int					pos_x;
	int					pos_y;
	int					pos_z;
	int					rot_x;
	int					rot_y;
	int					rot_z;
	int					scale;
	char				has_parsed_position;
	char				has_parsed_color;
	char				has_parsed_scale;
	char				has_parsed_rotation;
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

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*mlx_img_ptr;
	char				*mlx_img_data;
	int					bpp;
	t_rtlist			*object_list;
	t_camera			*camera;
}						t_env;

void					parse(t_env *env, int argc, char **argv);
void					parse_general_object(t_env *env, char **datas);
void					parse_color(t_object *object, char **datas, int *start);
void					parse_position(t_object *object, char **datas,
						int *start);
void					parse_rotation(t_object *object, char **datas,
						int *start);
void					parse_scale(t_object *object, char **datas, int *start);
void					parse_args(t_env *env, int fd);
void					list_add_object(t_env *env, t_object *object);
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
int						check_collision(t_env *env, t_ray *ray, t_object **object);
t_ray					*create_camera_ray(t_env *env);
int						collide_sphere(t_ray *ray, t_object *object,
						double *distance);
double					dot_product(t_vector *v1, t_vector *v2);
void					solve_quadratic(t_quadratic quadratic,
						double *distance);
double					dmin(double a, double b);
void					parse_camera(t_env *env, char **datas);
unsigned int			conv_rgb_to_int(int r, int g, int b);
#endif
