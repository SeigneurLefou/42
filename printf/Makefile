NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c\
	ft_putchar_fd.c\
	ft_putnbrbase_fd.c\
	ft_put_unsigned_nbr_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_putvoids_fd.c\
	ft_strlen.c\

OBJ = $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
