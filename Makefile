##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

T_SRC	= 	main.c              \
            error_handling.c

SRC = $(addprefix src/, $(T_SRC))

NAME = gameoflife

CC = gcc

INCLUDE = -I include/

LIB = -L lib/ -lmy

CFLAGS = -g3 -pedantic -w -Wall -Wextra -Wpedantic -Wno-long-long -Werror \
		$(INCLUDE) $(LIB)

OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME): dolib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

dolib:
	$(MAKE) -C lib/

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	$(MAKE) clean -C lib/

fclean:	clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	$(MAKE) fclean -C lib/

re:	fclean all
	$(MAKE) clean
