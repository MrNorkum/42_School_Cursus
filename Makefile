NAME_BASIC = so_long
NAME_BONUS = so_long_bonus

RM = rm -rf

BASIC_PATH = ./basic
BONUS_PATH = ./bonus

all:
	@make -C $(BASIC_PATH) all

bonus:
	@make -C $(BONUS_PATH) all

clean:
	@make -C $(BASIC_PATH) clean
	@make -C $(BONUS_PATH) clean

fclean:
	@make -C $(BASIC_PATH) fclean
	@make -C $(BONUS_PATH) fclean
	@$(RM) $(NAME_BASIC) $(NAME_BONUS)

re: fclean all
bre: fclean bonus

norm:
	norminette $(BASIC_PATH)/source
	norminette $(BASIC_PATH)/checker
	norminette $(BASIC_PATH)/libft
normbonus:
	norminette $(BONUS_PATH)/source
	norminette $(BONUS_PATH)/checker
	norminette $(BONUS_PATH)/libft

.PHONY: all clean fclean re bonus bre norm normbonus
