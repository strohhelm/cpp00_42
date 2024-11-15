NAME = Account

CC = c++


SRC_DIR := .
OBJ_DIR = ./obj
INC_DIR := .
DEP_DIR := $(OBJ_DIR)/.deps


vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INC_DIR)
vpath %.d $(DEP_DIR)


SRC =	Account.cpp\
		tests.cpp

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

DEP:= $(OBJ:.o=.d)
DEPFLAGS = -MMD -MP
FLAGS = -Wall -Wextra -Werror  -std=c++98
INCLUDES = -I$(INC_DIR)
all: $(NAME)

-include $(DEP)

$(NAME):$(OBJ)
	@$(CC) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(DEPFLAGS) -I$(INCLUDES) -c $< -o $@ 

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re