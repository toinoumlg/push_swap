NAME= push_swap
C_FLAGS= -Werror -Wall -Wextra
SRCS= main.c stack.c swap.c push.c rotate.c check.c check_utils.c \
		utils.c index.c index_utils.c radx.c sort_small.c
OBJS= $(SRCS:%.c=$(OBJ_DIR)/%.o)
SRC_DIR= src/
OBJ_DIR= $(SRC_DIR)obj
HEADER= include/push_swap.h
LIBFTPRINTF_LIB = libftprintf/libftprintf.a

#Printf colors
NC= \033[0m
BLACK= \033[0;30m
RED= \033[0;31m
GREEN= \033[0;32m
YELLOW= \033[0;33m
BLUE= \033[0;34m
PURPLE= \033[0;35m
CYAN= \033[0;36m
WHITE= \033[0;37m

all: libftprintf $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFTPRINTF_LIB)
	@printf "$(PURPLE)"
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF_LIB)
	@printf "$(NC)"


$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HEADER)
	@printf "$(YELLOW)"
	$(CC) $(C_FLAGS) -c -o $@ $< $(INCLUDES)
	@printf "$(NC)"

$(OBJ_DIR):
	@printf "$(BLUE)"
	mkdir -p $(OBJ_DIR)
	@printf "$(NC)"

visualizer: all
	@./push_swap_visualizer/build/bin/visualizer

norminette: all
	norminette $(SRC_DIR) include

libftprintf:
	@printf "$(GREEN)Entering libftprintf$(NC)\n"
	@make --no-print-directory -C libftprintf
	@printf "$(GREEN)Leaving libftprintf$(NC)\n"

clean:
	@printf "$(GREEN)Entering libftprintf$(NC)\n"
	@make --no-print-directory -C libftprintf clean
	@printf "$(GREEN)Leaving libftprintf$(NC)\n"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(NC)"

fclean:
	@printf "$(GREEN)Entering libftprintf$(NC)\n"
	@make --no-print-directory -C libftprintf fclean
	@printf "$(GREEN)Leaving libftprintf$(NC)\n"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	@printf "$(NC)"

re: fclean all

.PHONY: all libftprintf norminette visualizer fclean re clean