NAME=coldrace

CC=gcc
FLAGS=-Wall -Wextra -Ofast -march=native -mtune=native -lm
DEBUG_FLAGS=-g -fsanitize=address
SRC=src/*.c
LIBS=-I inc/
OBJ=
RM =rm -rf

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(LIBS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

debug: fclean
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(LIBS) $(SRC) -o $(NAME)
