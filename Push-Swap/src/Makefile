NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I ../includes/

# DIRECTORY
STR = libft/str_utils/
CONV = libft/conv_utils/
MEM = libft/mem_utils/
COMP = libft/comp_utils/
PUT = libft/put_utils/
LST = libft/lst_utils/
PS = push_swap/
BUILD = build/

SRC = $(COMP)ft_isascii.c\
	$(COMP)ft_isdigit.c\
	$(COMP)ft_isalpha.c\
	$(COMP)ft_isprint.c\
	$(COMP)ft_isalnum.c\
	$(COMP)ft_isvalid.c\
	$(COMP)ft_isdouble.c\
	$(CONV)ft_toupper.c\
	$(CONV)ft_tolower.c\
	$(CONV)ft_atoi.c\
	$(CONV)ft_antoi.c\
	$(CONV)ft_itoa.c\
	$(CONV)ft_atol.c\
	$(CONV)ft_antol.c\
	$(MEM)ft_memcpy.c\
	$(MEM)ft_memmove.c\
	$(MEM)ft_memchr.c\
	$(MEM)ft_bzero.c\
	$(MEM)ft_memcmp.c\
	$(MEM)ft_memset.c\
	$(MEM)ft_calloc.c\
	$(PUT)ft_putchar_fd.c\
	$(PUT)ft_putstr_fd.c\
	$(PUT)ft_putendl_fd.c\
	$(PUT)ft_putnbr_fd.c\
	$(PUT)ft_putnbr_endl.c\
	$(STR)ft_strnstr.c\
	$(STR)ft_strlen.c\
	$(STR)ft_strdup.c\
	$(STR)ft_strncmp.c\
	$(STR)ft_strrchr.c\
	$(STR)ft_substr.c\
	$(STR)ft_strjoin.c\
	$(STR)ft_sstrjoin.c\
	$(STR)ft_strmapi.c\
	$(STR)ft_striteri.c\
	$(STR)ft_strtrim.c\
	$(STR)ft_strlcpy.c\
	$(STR)ft_strchr.c\
	$(STR)ft_strichr.c\
	$(STR)ft_strlcat.c\
	$(STR)ft_split.c\
	$(LST)ft_lstadd_back.c\
	$(LST)ft_lstadd_front.c\
	$(LST)ft_lstlast.c\
	$(LST)ft_lstsize.c\
	$(LST)ft_lstnew.c\
	$(LST)ft_lstdelone.c\
	$(LST)ft_lstiter.c\
	$(LST)ft_lstclear.c\
	$(LST)ft_lstmap.c\
	$(LST)ft_lstshow.c\
	$(LST)ft_lstisdouble.c\
	$(PS)ft_intslen.c\
	$(PS)ft_longslen.c\
	$(PS)push_swap.c\
	$(PS)ft_swap.c\
	$(PS)ft_push.c\
	$(PS)ft_rotate.c\
	$(PS)ft_reverse_rotate.c\
	$(PS)ft_sort.c

OBJ = $(SRC:%.c=$(BUILD)%.o)

$(NAME) : $(OBJ)
	@ar crs $(NAME) $(OBJ)
	@echo "LIBRAIRY : $(NAME)"

$(BUILD)%.o : %.c
	@mkdir -p $(BUILD)
	@mkdir -p $(BUILD)$(STR)
	@mkdir -p $(BUILD)$(MEM)
	@mkdir -p $(BUILD)$(PUT)
	@mkdir -p $(BUILD)$(COMP)
	@mkdir -p $(BUILD)$(CONV)
	@mkdir -p $(BUILD)$(PS)
	@mkdir -p $(BUILD)$(LST)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "CC $<\n\t> $@"

clean : 
	@rm -Rf $(BUILD)
	@echo "DELETE : $(BUILD)"

fclean : clean
	@rm -f $(NAME)
	@echo "DELETE : $(NAME)"

re : fclean all

all : $(NAME) 

.PHONY: all clean fclean re
