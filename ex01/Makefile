NAME = phonebook

SRC =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp

OBJ =	Contact.o \
		PhoneBook.o \
		main.o

CC = c++
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re