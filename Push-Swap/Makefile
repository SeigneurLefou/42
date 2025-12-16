NAME = push_swap
CC = cc
BUILD = build/
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I push_swap.h
LIB_DR = libft/
LIB_FL = push_swap.a

makelib :
	@make -C $(LIB_DR)

all : makelib

build: makelib
	$(CC) $(CFLAGS) $(INLCUDE) main.c $(LIB_DR)$(LIB_FL) -o $(NAME)
clean : 
	@make -C $(LIB_DR) clean
	rm -Rf $(BUILD)

fclean : clean
	@make -C $(LIB_DR) fclean
	rm -f $(NAME)

re : fclean all build

.PHONY: all clean fclean re
