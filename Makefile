# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 23:07:52 by hkeles            #+#    #+#              #
#    Updated: 2024/06/05 17:06:33 by hkeles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* [v] NAME [v] ******************************* #
# The name of the final library file to be created.                            #
#                                                                              #
NAME            =   push_swap
BONUS_NAME      =   checker
# ******************************* [^] NAME [^] ******************************* #
#                                                                              #
# *************************** [v] MAIN SOURCE [v] **************************** #
# List of mandatory source files.                                              #
#                                                                              #
MAIN_SRC        =   main_lst.c \
                    main_sort.c \
                    utils.c \
                    quicksort.c \
                    main.c

BONUS_SRC       =   main_lst.c \
                    main_sort.c \
                    utils.c \
                    checker.c
# *************************** [^] MAIN SOURCE [^] **************************** #
# ************************** [v] SET DIRECTORY [v] *************************** #
# Directory paths for source and object files.                                 #
#                                                                              #
SRCDIR      =	./
OBJDIR      =   ./obj
LIBFT_PATH  =   ./libft
LIBFT       =   $(LIBFT_PATH)/libft.a
# ************************** [^] SET DIRECTORY [^] *************************** #
#                                                                              #
# ************************* [v] OBJECT GENERATE [v] ************************** #
# Object files list generation.                                                #
#                                                                              #
MAIN_OBJ         =   $(addprefix $(OBJDIR)/, $(addsuffix .o, $(MAIN_BASE)))
MAIN_BASE        =   $(basename $(notdir $(MAIN_SRC)))
BONUS_OBJ        =   $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BONUS_BASE)))
BONUS_BASE       =   $(basename $(notdir $(BONUS_SRC)))
# ************************* [^] OBJECT GENERATE [^] ************************** #
#                                                                              #
# ************************ [v] SET SHELL COMMANDS [v] ************************ #
# Command definitions for compiler, archiver, etc.                             #
#                                                                              #
CC          =   cc # is the C compiler.
CFLAGS      =   -Wall -Wextra -Werror -g # are the flags for the compiler.
RM          =   rm -rf # is the command to remove files or directories.
ECHO        =   echo # is used to print messages.
MKDIR       =   mkdir -p # creates directories.
# ************************ [^] SET SHELL COMMANDS [^] ************************ #
#                                                                              #
# ************************** [v] MAKEFILE RULES [v] ************************** #

all: $(NAME)

bonus:  $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(OBJDIR):
	@test -d $(OBJDIR) || $(MKDIR) $(OBJDIR)

$(NAME): $(OBJDIR) $(LIBFT) $(MAIN_OBJ)
	@$(ECHO) "\033[0;32m> push_swap Compiled\033[0m"
	@$(CC) $(CFLAGS) $(LIBFT) $(MAIN_OBJ) -o $(NAME)
	@$(ECHO) "\033[0;31m> push_swap created\033[0m"

$(BONUS_NAME): $(OBJDIR) $(LIBFT) $(BONUS_OBJ)
	@$(ECHO) "\033[0;32m> checker Compiled\033[0m"
	@$(CC) $(CFLAGS) $(LIBFT) $(BONUS_OBJ) -o $(BONUS_NAME)
	@$(ECHO) "\033[0;31m> checker created\033[0m"


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $< \
	&& $(ECHO) "\033[1;30m[CC] : Compiled $(notdir $<) \
	[\033[0;32mOk\033[1;30m]\033[0m" \
	|| $(ECHO) "\033[1;30m[CC] : Compiled $(notdir $<) \
	[\033[0;7;31mError\033[0;1;30m]\033[0m"

clean:
	@$(RM) $(OBJDIR)
	@$(RM) $(NAME).dSYM
	@$(ECHO) "\033[0;34m> push_swap Directory cleaned\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean 
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(ECHO) "\033[0;35m> push_swap execute removed\033[0m"

re: libre fclean all
libre:
	@make -C $(LIBFT_PATH) re

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
