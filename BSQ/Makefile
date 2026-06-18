NAME = bsq

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC =	main.c\
		validate.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putendl.c\
		dp.c\
		header.c\
		map_read.c\
		solve.c\
		line_utils.c\
		utils.c\
		str_utils.c\
		output.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) bsq.h
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
