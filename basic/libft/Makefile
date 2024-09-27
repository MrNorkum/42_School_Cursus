NAME = libft.a
RM = rm -rf
CC = gcc
FLAG = -Wall -Wextra -Werror
MKDIR = mkdir -p
OBJDIR = OBJECTS
CMPL = $(CC) $(FLAG) -c
SRC =	./ft_split.c		\
		./ft_strchr.c		\
		./ft_strdup.c		\
		./ft_strjoin.c		\
		./ft_strlcpy.c		\
		./ft_strlen.c		\
		./ft_strncmp.c		\
		./ft_strrchr.c		\
		./ft_strtrim.c		\
		./ft_substr.c		\
		./ft_printf.c		\
		./get_next_line.c

OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)/%.o:	%.c
	@$(MKDIR) $(OBJDIR)
	@$(CMPL) $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
