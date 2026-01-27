NAME = push_swap
CHECKER = checker
CC = cc
BUILD = build/
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes

# DIRECTORY
STR = libft/str_utils/
CONV = libft/conv_utils/
MEM = libft/mem_utils/
COMP = libft/comp_utils/
PUT = libft/put_utils/
LST = libft/lst_utils/
PS = libps/
GNL = gnl/
BUILD = build/

SRC = $(COMP)ft_isascii.c\
	$(COMP)ft_isdigit.c\
	$(COMP)ft_isalpha.c\
	$(COMP)ft_isprint.c\
	$(COMP)ft_isalnum.c\
	$(COMP)ft_isvalid.c\
	$(COMP)ft_issorted.c\
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
	$(MEM)ft_free.c\
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
	$(STR)ft_strnjoin.c\
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
	$(LST)ft_lstshow.c\
	$(LST)ft_lstfind.c\
	$(LST)ft_lstisdouble.c\
	$(PS)ft_intslen.c\
	$(PS)ft_longslen.c\
	$(PS)parsing.c\
	$(PS)parsing_utils.c\
	$(PS)ft_swap.c\
	$(PS)ft_push.c\
	$(PS)ft_rotate.c\
	$(PS)ft_reverse_rotate.c\
	$(PS)ft_stairs_sort.c\
	$(PS)ft_insert_sort.c\
	$(PS)ft_give_index.c\
	$(PS)ft_optimal_move.c\
	$(PS)ft_sqrt.c\
	$(PS)is_command.c\
	$(GNL)get_next_line.c

OBJ = $(SRC:%.c=$(BUILD)%.o)

$(NAME) : $(OBJ) main.c
	@$(CC) $(CFLAGS) $(INCLUDES) main.c $(OBJ) -o $(NAME)
	@echo "BINARY : $(NAME)"

$(CHECKER) : $(OBJ) checker.c
	@$(CC) $(CFLAGS) $(INCLUDES) checker.c $(OBJ) -o $(CHECKER)
	@echo "BINARY : $(CHECKER)"

$(BUILD)%.o : %.c
	@mkdir -p $(BUILD)
	@mkdir -p $(BUILD)$(STR)
	@mkdir -p $(BUILD)$(MEM)
	@mkdir -p $(BUILD)$(PUT)
	@mkdir -p $(BUILD)$(COMP)
	@mkdir -p $(BUILD)$(CONV)
	@mkdir -p $(BUILD)$(PS)
	@mkdir -p $(BUILD)$(LST)
	@mkdir -p $(BUILD)$(GNL)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "CC $<\n\t> $@"

clean : 
	@rm -Rf $(BUILD)
	@rm -Rf libft/$(BUILD)
	@echo "DELETE : $(BUILD)"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@echo "DELETE : $(NAME)"

re : fclean all bonus

all : $(NAME) 

bonus : $(CHECKER)

.PHONY: all clean fclean re bonus
