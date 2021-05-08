
NAME = suso

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

FILES = src/grid_functions.c src/logic.c\
		src/num_validation.c src/utility.c src/main.c

OFILES = $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(FILES) src/header.h
	make $(OFILES)
	$(CC) -o $(NAME) $(OFILES)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OFILES)

fclean: clean
	rm -fr $(NAME)

re: fclean
	make
