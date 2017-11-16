/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:01 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 11:14:27 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define CUBE 0
# define TRIANGLE 1
# define RECTANGLE 2
# define SPHERE 3
# define CYLINDRE 4
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define FOV_X 60
# define FOV_Y 60

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

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
	char				*mlx_img_datas;
	int					bpp;
	t_rtlist			*object_list;
}						t_env;

void					parse(t_env *env, int argc, char **argv);
void					parse_general_object(t_env *env, char **datas);
void					parse_color(t_object *object, char **datas, int *start);
void					parse_position(t_object *object, char **datas, int *start);
void					parse_rotation(t_object *object, char **datas, int *start);
void					parse_args(t_env *env, int fd);
void					list_add_object(t_env *env, t_object *object);
void					init_env(t_env *env);
char					*replace_tab_by_space(char *str);
void					free_2d_array(char **str);

#endif
