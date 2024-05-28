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
NAME            =       libftprintf.a
# ******************************* [^] NAME [^] ******************************* #
#                                                                              #
# *************************** [v] MAIN SOURCE [v] **************************** #
# List of mandatory source files.                                              #
#                                                                              #
MANDATORY_SRC   =       ft_printf.c
# *************************** [^] MAIN SOURCE [^] **************************** #
#                                                                              #
# **************************** [v] SET SOURCE [v] **************************** #
SRC             =       $(MANDATORY_SRC)
# **************************** [^] SET SOURCE [^] **************************** #
#                                                                              #
# ************************** [v] SET DIRECTORY [v] *************************** #
# Directory paths for source and object files.                                 #
#                                                                              #
SRCDIR          =       ./
OBJDIR          =       ./obj
# ************************** [^] SET DIRECTORY [^] *************************** #
#                                                                              #
# ************************* [v] OBJECT GENERATE [v] ************************** #
# Object files list generation.                                                #
#                                                                              #
OBJ             =       $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASE)))
BASE            =       $(basename $(notdir $(SRC)))
# ************************* [^] OBJECT GENERATE [^] ************************** #
#                                                                              #
# ************************ [v] SET SHELL COMMANDS [v] ************************ #
# Command definitions for compiler, archiver, etc.                             #
#                                                                              #
CC              = cc # is the C compiler.
CFLAGS          = -Wall -Wextra -Werror -g # are the flags for the compiler.
AR              = ar rc # is the archiver to create the static library. 
RM              = rm -rf # is the command to remove files or directories.
ECHO            = echo # is used to print messages.
MKDIR           = mkdir -p # creates directories.
# ************************ [^] SET SHELL COMMANDS [^] ************************ #
#                                                                              #
# ************************** [v] MAKEFILE RULES [v] ************************** #
# Main targets and their dependencies.                                         #
#                                                                              #
# 'all' target to build the library from mandatory sources.
all: $(NAME)

# Ensure the object directory exists.
$(OBJDIR):
	@test -d $(OBJDIR) || $(MKDIR) $(OBJDIR)

# Rule to create the library archive.
$(NAME): $(OBJDIR) $(OBJ)
	@$(ECHO) "\033[0;32m> ft_printf Compiled\033[0m"
	@$(AR) $(NAME) $(OBJ)
	@$(ECHO) "\033[0;31m> ft_printf created\033[0m"
	@ranlib $(NAME)
	@$(ECHO) "\033[0;33m> ft_printf index added\033[0m"

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
	@$(ECHO) "\033[0;34m> ft_printf Directory cleaned\033[0m"

# 'fclean' target to remove object files and the library.
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) "\033[0;35m> ft_printf Library removed\033[0m"

# 're' target to clean and rebuild everything.
re: fclean all

# Short aliases for targets.
a: all
c: clean
f: fclean
fc: fclean
r: re
# ************************** [^] MAKEFILE RULES [^] ************************** #
#                                                                              #
# ****************************** [v] .PHONY [v] ****************************** #
# Fake targets so that Make does not confuse them with files with the same name.
#                                                                              #
.PHONY: all clean fclean re a c f fc r
# ****************************** [^] .PHONY [^] ****************************** #
