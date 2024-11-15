NAME = Account

FILES =	Account.cpp\
		Account.hpp\
		tests.cpp

OBJ =	$(patsubst %.cpp, obj/%.o,$(FILES))
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(FLAGS)$(OBJ) -o $(NAME)

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re