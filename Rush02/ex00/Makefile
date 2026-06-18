NAME	= rush-02

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC	= main.c \
		  str_len.c \
		  str_dup.c \
		  str_join.c \
		  put_str.c \
		  is_digit.c \
		  is_scale.c \
		  str_cmp.c \
		  str_zeros.c \
		  str_divide.c \
		  str_remainder.c \
		  str_subtract.c \
		  dict_create.c \
		  dict_trim.c \
		  dict_parse.c \
		  dict_load.c \
		  dict_sort.c \
		  convert.c \
		  convert_util.c \
		  convert_steps.c \
		  convert_rec.c \
		  bonus.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
