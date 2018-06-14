NAME = rt

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = main.c \
			parse_general_object.c \
			parse_pieces_datas.c \
			parser.c \
			get_next_line.c \
			list_utils.c \
			init_env.c \
			str_utils.c \
			init_window.c \
			draw_window.c \
			pixel_put.c \
			vector_dot_product.c \
			vector_length.c \
			vector_rotate.c \
			vector_normalize.c \
			check_collision.c \
			shape_sphere.c \
			create_ray.c \
			solve_quadratic.c \
			math_utils.c \
			parse_camera.c \
			parse_light.c \
			get_pixel_color.c \
			shape_cylinder.c \
			collision.c \
			vector_angle.c \
			calculate_light.c \
			vector_normal.c \
			create_object.c \
			ft_strncmp_ignrcase.c \
			shape_cone.c \
			shape_plane.c \
			parse_material.c \
			parse_fill_object_material.c \
			material.c \
			vector_distance.c \
			light_specular.c \
			timer.c \
			define.c \
			parse_define.c \
			parse_fill_object_define.c \
			light_reflection.c \
			color_add.c \
			color_factor.c \
			light_transparency.c \
			thread.c \
			loop_handler.c \
			draw_progress_bar.c \
			color_filter.c \
			save_image.c \
			parse_pieces_datas2.c \
			parse_material_attribute.c \
			create_light.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft -lft -framework OpenGL -framework AppKit
#LIBRARY = -lGL -L libft -lft -lm -L ../../minilibx -lmlx -lX11 -lXext -pthread

all: odir $(NAME)

$(NAME): $(OBJS)
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
