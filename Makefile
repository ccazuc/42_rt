NAME = rt

CFLAGS = -Wall -Wextra -Werror -O2

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
			sphere.c \
			create_ray.c \
			solve_quadratic.c \
			math_utils.c \
			parse_camera.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft -lft -framework OpenGL -framework AppKit

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
