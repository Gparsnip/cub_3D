
NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = make -C libft
GNL = make -C get_next_line
LIB = -L mlx_mac -L get_next_line -L libft
OPTION_LIB = -lmlx -framework OpenGL -framework AppKit -lgnl -lft
OPTION = -c -g
MLX = make -C mlx_mac
SRCS =	cub3d.c \
		null.c \
		error.c \
		check_argv.c \
		sprite.c \
		sort.c \
		save.c \
		reycast.c \
		parser.c \
		move.c \
		move_utils.c \
		free.c \
		draw.c \
		comsist_map.c \
		check_map.c \
		mlx_utils.c \

OBJS_SRCS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS_SRCS)
		@$(CC) $(FLAGS) $(OPTION) $(SRCS)
		@$(MLX)
		@$(LIBFT)
		@$(GNL)
		@$(CC) $(LIB) $(OPTION_LIB) $(OBJS_SRCS) -o $(NAME)
clean:
		rm -f $(OBJS_SRCS)
		@$(LIBFT) clean
		@$(GNL) clean
fclean: clean
		rm -f $(NAME)
		@$(MLX) clean
		@$(GNL) fclean
		@$(LIBFT) fclean
		rm -f *.bmp
re: fclean all
.PHONY: all clean fclean re
