# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 23:07:52 by hkeles            #+#    #+#              #
#    Updated: 2024/05/24 06:36:11 by hkeles           ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

# ******************************* [v] NAME [v] ******************************* #
# The name of the final library file to be created.                            #
#                                                                              #
NAME            =   libft.a
# ******************************* [^] NAME [^] ******************************* #
#                                                                              #
# *************************** [v] MAIN SOURCE [v] **************************** #
# List of mandatory source files.                                              #
#                                                                              #
MANDATORY_SRC   =   ft_atoi.c \
                    ft_bzero.c \
                    ft_calloc.c \
                    ft_isalnum.c \
                    ft_isalpha.c \
                    ft_isascii.c \
                    ft_isdigit.c \
                    ft_isprint.c \
                    ft_itoa.c \
                    ft_memchr.c \
                    ft_memcmp.c \
                    ft_memcpy.c \
                    ft_memmove.c \
                    ft_memset.c \
                    ft_putchar_fd.c \
                    ft_putendl_fd.c \
                    ft_putnbr_fd.c \
                    ft_putstr_fd.c \
                    ft_split.c \
                    ft_strchr.c \
                    ft_strdup.c \
                    ft_striteri.c \
                    ft_strjoin.c \
                    ft_strlcat.c \
                    ft_strlcpy.c \
                    ft_strlen.c \
                    ft_strmapi.c \
                    ft_strncmp.c \
                    ft_strnstr.c \
                    ft_strrchr.c \
                    ft_strtrim.c \
                    ft_substr.c \
                    ft_tolower.c \
                    ft_toupper.c
# *************************** [^] MAIN SOURCE [^] **************************** #
#                                                                              #
# *************************** [v] BONUS SOURCE [v] *************************** #
# List of bonus source files.                                                  #
#                                                                              #
BONUS_SRC       =   ft_lstadd_back.c \
                    ft_lstadd_front.c \
                    ft_lstclear.c \
                    ft_lstdelone.c \
                    ft_lstiter.c \
                    ft_lstlast.c \
                    ft_lstmap.c \
                    ft_lstnew.c \
                    ft_lstsize.c
# *************************** [^] BONUS SOURCE [^] *************************** #
#                                                                              #
# **************************** [v] SET SOURCE [v] **************************** #
# Determine which source files to use based on the target.                     #
# If the target is 'bonus' or 'b', use BONUS_SRC. Otherwise, use MANDATORY_SRC.#
#                                                                              #
ifeq ($(filter bonus b,$(MAKECMDGOALS)),)
SRC         =   $(MANDATORY_SRC)
else
SRC         =   $(BONUS_SRC)
endif
# **************************** [^] SET SOURCE [^] **************************** #
#                                                                              #
# ************************** [v] SET DIRECTORY [v] *************************** #
# Directory paths for source and object files.                                 #
#                                                                              #
SRCDIR      =	./
OBJDIR      =   ./obj
# ************************** [^] SET DIRECTORY [^] *************************** #
#                                                                              #
# ************************* [v] OBJECT GENERATE [v] ************************** #
# Object files list generation.                                                #
#                                                                              #
OBJ         =   $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASE)))
BASE        =   $(basename $(notdir $(SRC))) 
# ************************* [^] OBJECT GENERATE [^] ************************** #
#                                                                              #
# ************************ [v] SET SHELL COMMANDS [v] ************************ #
# Command definitions for compiler, archiver, etc.                             #
#                                                                              #
CC          =   cc # is the C compiler.
CFLAGS      =   -Wall -Wextra -Werror -g # are the flags for the compiler.
AR          =   ar rc # is the archiver to create the static library.
RM          =   rm -rf # is the command to remove files or directories.
ECHO        =   echo # is used to print messages.
MKDIR       =   mkdir -p # creates directories.
# ************************ [^] SET SHELL COMMANDS [^] ************************ #
#                                                                              #
# ************************** [v] MAKEFILE RULES [v] ************************** #
# Main targets and their dependencies.                                         #
#                                                                              #
# 'all' target to build the library from mandatory sources.
all: $(NAME)

# 'bonus' target to build the library from bonus sources.
bonus: $(NAME)

# Ensure the object directory exists.
$(OBJDIR):
	@test -d $(OBJDIR) || $(MKDIR) $(OBJDIR)

# Rule to create the library archive.
$(NAME): $(OBJDIR) $(OBJ)
	@$(ECHO) "\033[0;32m> Libft Compiled\033[0m"
	@$(AR) $(NAME) $(OBJ)
	@$(ECHO) "\033[0;31m> Libft created\033[0m"
	@ranlib $(NAME)
	@$(ECHO) "\033[0;33m> Libft index added\033[0m"

# Rule to compile source files into object files.
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $< \
	&& $(ECHO) "\033[1;30m[CC] : Compiled $(notdir $<) \
	[\033[0;32mOk\033[1;30m]\033[0m" \
	|| $(ECHO) "\033[1;30m[CC] : Compiled $(notdir $<) \
	[\033[0;7;31mError\033[0;1;30m]\033[0m"

# 'clean' target to remove object files.
clean:
	@$(RM) $(OBJDIR)
	@$(ECHO) "\033[0;34m> Libft Directory cleaned\033[0m"

# 'fclean' target to remove object files and the library.
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) "\033[0;35m> Libft Library removed\033[0m"

# 're' target to clean and rebuild everything.
re: fclean all

# Short aliases for targets.
a: all
b: bonus
c: clean
f: fclean
fc: fclean
r: re
# ************************** [^] MAKEFILE RULES [^] ************************** #
#                                                                              #
# ****************************** [v] .PHONY [v] ****************************** #
# Fake targets so that Make does not confuse them with files with the same name.
#                                                                              #
.PHONY: all clean fclean re a b c f fc r #                                     #
# ****************************** [^] .PHONY [^] ****************************** #
