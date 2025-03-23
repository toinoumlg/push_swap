NAME= push_swap
C_FLAGS= -Werror -Wall -Wextra
SRCS= main.c stack.c swap.c push.c rotate.c check.c check_utils.c utils.c index.c index_utils.c radx.c sort_small.c
OBJS= $(SRCS:%.c=$(OBJ_DIR)/%.o)
SRC_DIR= src/
OBJ_DIR= $(SRC_DIR)obj
HEADER= include/push_swap.h

all: libftprintf $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFTPRINTF_LIB) $(HEADER) $(MLX_LIB) 
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJS) libftprintf/libftprintf.a

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(C_FLAGS) -g -c -o $@ $< $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

visualizer: all
	@./push_swap_visualizer/build/bin/visualizer


norminette:
	clear
	norminette $(SRC_DIR) include

libftprintf:
	make -C libftprintf

clean:
	make -C libftprintf clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libftprintf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all libftprintf norminette visualizer