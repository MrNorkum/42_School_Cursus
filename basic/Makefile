NAME			=	so_long

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf
MV				=	mv

SRC				=	./source/main.c				\
					./source/so_long.c			\
					./source/put_image.c		\
					./checker/checker.c			\
					./checker/is_ber.c			\
					./checker/is_c_e_p.c		\
					./checker/is_game.c			\
					./checker/is_rectangle.c	\
					./checker/map_split.c

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	./minilibx

all:	$(NAME)

$(NAME):	$(LIBFT) mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx
	@$(MV) $(NAME) ..

$(LIBFT):
	@make -C $(LIBFT_PATH) all

mlx:
	@make -C $(MINILIBX_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MINILIBX_PATH) clean

fclean:
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
