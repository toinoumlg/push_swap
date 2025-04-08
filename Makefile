NAME= push_swap
C_FLAGS= -Werror -Wall -Wextra
SRCS= main.c stack.c swap.c push.c rotate.c check.c check_utils.c \
		utils.c index.c index_utils.c radx.c sort_small.c
OBJS= $(SRCS:%.c=$(OBJ_DIR)/%.o)
SRC_DIR= src/
OBJ_DIR= $(SRC_DIR)obj
HEADER= include/push_swap.h
LIBFTPRINTF_LIB = libftprintf/libftprintf.a

all: libftprintf $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFTPRINTF_LIB)
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(C_FLAGS) -g -c -o $@ $< $(INCLUDES)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

visualizer: all
	@./push_swap_visualizer/build/bin/visualizer

norminette: all
	norminette $(SRC_DIR) include

libftprintf:
	@make --no-print-directory -C  libftprintf

clean:
	@make -C libftprintf clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libftprintf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all libftprintf norminette visualizer fclean re clean