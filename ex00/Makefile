NAME = megaphone
SRC = megaphone.cpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -o $@

fclean:
		rm -rf $(NAME)

re: fclean all

.phony: fclean all re