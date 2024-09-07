NAME := pipex
CC := @cc
CFLAGS ?= -Wall -Wextra -Werror

CFILES := 	pipex.c\
			pipex_utils.c\
			pipex_cmd_argument_handling.c

LIBS :=	libft/libft.a\
		ftprintf/libftprintf.a

OBJFILES := $(CFILES:.c=.o)

$(NAME): $(OBJFILES) $(LIBS)
	@echo MAKING PIPEX ...
	@$(CC) $(CFLAGS) -o $@ $^ -g


$(LIBS) : 
	@make -C libft
	@make -C ftprintf

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $^ -o $@ -g

all: $(NAME)
	
t:
	

clean:
	rm -f $(OBJFILES)

fclean:
	@echo DELETING PIPEX ...
	@rm -rf $(NAME) $(OBJFILES)
	@make fclean -C libft 
	@make fclean -C ftprintf


re: fclean all

.PHONY: all clean fclean re t 
