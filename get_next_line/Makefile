
NAME = libgnl.a
HEADER = get_next_line.h
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I ${HEADER}
CC = gcc
SRCS =	get_next_line.c\
		get_next_line_utils.c\

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
