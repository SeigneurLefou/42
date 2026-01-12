NAME = push_swap
CC = cc
BUILD = build/
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes/
LIB_DR = src/
LIB_FL = $(LIB_DR)push_swap.a

$(LIB_FL) :
	@make -C $(LIB_DR)

$(NAME) : $(LIB_FL)
	@$(CC) $(CFLAGS) $(INCLUDES) main.c $(LIB_FL) -o $(NAME)
	@echo "BINARY : $(NAME)"

all : $(NAME)

clean : 
	@make -C $(LIB_DR) clean
	@rm -Rf $(BUILD)
	@echo "DELETE : $(BUILD)"

fclean : clean
	@make -C $(LIB_DR) fclean
	@rm -f $(NAME)
	@echo "DELETE : $(NAME)"

re : fclean all

.PHONY: all clean fclean makelib re build
