##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

SRC	=	my_str_to_array.c 			\
		open_file.c 				\
		my_arr_len.c 				\
		free_arr.c					\
		my_arr_dup.c                \
        my_str_isnum.c

OBJ	=	$(SRC:.c=.o)

CC = gcc

CFLAGS = -pedantic -w -Wall -Wextra -Wpedantic -Wno-long-long -Werror -I .

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../include/

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	$(MAKE) clean
