# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 23:07:52 by hkeles            #+#    #+#              #
#    Updated: 2024/06/04 00:23:00 by hkeles           ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

# ******************************* [v] NAME [v] ******************************* #
# The name of the final library file to be created.                            #
#                                                                              #
C_NAME      =   client
S_NAME      =   server
# ******************************* [^] NAME [^] ******************************* #
#                                                                              #
# *************************** [v] MAIN SOURCE [v] **************************** #
# List of mandatory source files.                                              #
#                                                                              #
C_SRC       =   client.c
S_SRC       =   server.c
# *************************** [^] MAIN SOURCE [^] **************************** #
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
C_OBJ       =   $(addprefix $(OBJDIR)/, $(addsuffix .o, $(C_BASE)))
C_BASE      =   $(basename $(notdir $(C_SRC)))

S_OBJ       =   $(addprefix $(OBJDIR)/, $(addsuffix .o, $(S_BASE)))
S_BASE      =   $(basename $(notdir $(S_SRC)))
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
# Main targets and their dependencies.                                         #
#                                                                              #
# 'all' target to build the library from mandatory sources.
all:  $(C_NAME) $(S_NAME)

# 'bonus' target to build the library from bonus sources.
bonus: all

# Ensure the object directory exists.
$(OBJDIR):
	@test -d $(OBJDIR) || $(MKDIR) $(OBJDIR)

$(C_NAME): $(OBJDIR) $(C_OBJ)
	@$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME)
	@$(ECHO) "\033[0;32m> Client Compiled\033[0m"

$(S_NAME): $(OBJDIR) $(S_OBJ)
	@$(CC) $(CFLAGS) $(S_OBJ) -o $(S_NAME)
	@$(ECHO) "\033[0;32m> Server Compiled\033[0m"

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
	@$(ECHO) "\033[0;34m> Object Directory cleaned\033[0m"

# 'fclean' target to remove object files and the library.
fclean:	clean
	@$(RM) $(C_NAME) $(S_NAME)
	@$(ECHO) "\033[0;35m> $(C_NAME)/$(S_NAME) removed\033[0m"

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
