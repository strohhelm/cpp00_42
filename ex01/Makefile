NAME = phonebook

FILES =	src/Contact.cpp\
		src/PhoneBook.cpp\
		src/main.cpp

OBJ =	$(patsubst src/%.cpp, obj/%.o,$(FILES))
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re