NAME = rt

CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -O2

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
			parse_fill_object_define2.c \
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
			light_transparency_shadow.c \
			find_light.c \
			key_handler.c \
			movement_handler.c \
			movement_handler2.c \
			parse_config.c \
			parse_config_attribute.c \
			parse_config_attribute2.c \
			fsaa.c \
			pixel_get.c \
			shape_triangle.c \
			parse_triangle.c \
			parse_triangle_attribute.c \
			reload_file.c \
			vector_utils.c \
			refraction.c \
			global_illumination.c \
			texture_checkboard.c \
			texture.c \
			vector_axis.c \
			get_object_color.c \
			parse_pieces_datas3.c \
			load_bmp.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

INC_SDL = -I/Users/$(USER)/.brew/include/SDL2 -D_THREAD_SAFE
LIB_SDL = -L/Users/$(USER)/.brew/lib -lSDL2

LIBRARY = -lmlx -L libft -lft -framework OpenGL -framework AppKit -L libpng -lpng16 -L zlib -lz

all: $(OBJS_PATH) $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH) $(LIB_SDL)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INCLUDES_PATH)/libft.h $(INCLUDES_PATH)/rt.h $(INCLUDES_PATH)/get_next_line.h
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH) $(INC_SDL)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

clean:
	@make clean -C libft
	@echo " - Clearing objects files"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_PATH)

fclean: clean
	@make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re $(OBJS_PATH)
