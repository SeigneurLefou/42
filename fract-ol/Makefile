NAME = pipex
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
BUILD = build/
PF = printf/
GNL = gnl/
CMD = libpp/cmd_utils/
PIP = libpp/

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
	$(MEM)ft_double_free.c\
	$(MEM)ft_bzero.c\
	$(MEM)ft_memcmp.c\
	$(MEM)ft_memset.c\
	$(MEM)ft_calloc.c\
	$(PUT)ft_putchar_fd.c\
	$(PUT)ft_putstr_fd.c\
	$(PUT)ft_putstrstr_fd.c\
	$(PUT)ft_putendl_fd.c\
	$(PUT)ft_putnbr_fd.c\
	$(PUT)ft_putnbr_endl.c\
	$(PUT)ft_putvoids_fd.c\
	$(PUT)ft_putunsigned_nbr_fd.c\
	$(PUT)ft_putnbrbase_fd.c\
	$(STR)ft_strnstr.c\
	$(STR)ft_strlen.c\
	$(STR)ft_strdup.c\
	$(STR)ft_strncmp.c\
	$(STR)ft_strcmp.c\
	$(STR)ft_strrchr.c\
	$(STR)ft_substr.c\
	$(STR)ft_strjoin.c\
	$(STR)ft_strnjoin.c\
	$(STR)ft_sstrjoin.c\
	$(STR)ft_strmapi.c\
	$(STR)ft_striteri.c\
	$(STR)ft_strtrim.c\
	$(STR)ft_strlcpy.c\
	$(STR)ft_strcpy.c\
	$(STR)ft_strchr.c\
	$(STR)ft_strichr.c\
	$(STR)ft_strlcat.c\
	$(STR)ft_strcat.c\
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
	$(LST)ft_lstfind.c\
	$(LST)ft_lstisdouble.c\
	$(PF)ft_printf.c\
	$(GNL)get_next_line.c\

OBJ = $(SRC:%.c=$(BUILD)%.o)

$(NAME) : $(OBJ) main.c
	@$(CC) $(CFLAGS) $(INCLUDES) main.c $(OBJ) -o $(NAME)
	@echo "BINARY : $(NAME)"

$(BUILD)%.o : %.c
	@mkdir -p $(BUILD)
	@mkdir -p $(BUILD)$(STR)
	@mkdir -p $(BUILD)$(MEM)
	@mkdir -p $(BUILD)$(PUT)
	@mkdir -p $(BUILD)$(COMP)
	@mkdir -p $(BUILD)$(CONV)
	@mkdir -p $(BUILD)$(LST)
	@mkdir -p $(BUILD)$(PF)
	@mkdir -p $(BUILD)$(CMD)
	@mkdir -p $(BUILD)$(PIP)
	@mkdir -p $(BUILD)$(GNL)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "CC $<\n\t> $@"

re : fclean all bonus

bonus : $(BONUS)

all : $(NAME) 

clean :
	@rm -Rf $(BUILD)
	@rm -Rf libft/$(BUILD)
	@echo "DELETE : $(BUILD)"

fclean : clean
	@rm -f $(NAME)
	@echo "DELETE : $(NAME)"
	@rm -f $(BONUS)
	@echo "DELETE : $(BONUS)"

.PHONY: all bonus clean fclean re
