LIBFTPRINTF = libftprintf.a
CFLAGS = -Werror -Wall -Wextra
CC = cc 
HEADER = include/ft_printf.h

SRCS = ft_printf.c ft_printf_putstr_int.c \
		ft_printf_specifier.c ft_printf_nbr.c\
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_memcmp.c ft_atoi.c \
		ft_strncmp.c ft_toupper.c ft_tolower.c ft_isprint.c ft_isdigit.c \
		ft_isascii.c ft_isalpha.c ft_isalnum.c ft_substr.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_strdup.c ft_itoa.c ft_strmapi.c ft_memset.c ft_memchr.c ft_memcpy.c \
		ft_bzero.c ft_memmove.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c

SRC_DIR = src
LIBFT_OBJ_DIR = libft/src/obj/
OBJ_DIR = $(SRC_DIR)/obj
OBJECTS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

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

all: $(LIBFTPRINTF)

$(LIBFTPRINTF): $(OBJ_DIR) $(OBJECTS) $(HEADER)
	@printf "$(PURPLE)"
	ar rcs $(LIBFTPRINTF) $(OBJECTS)
	@printf "$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(YELLOW)"
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
	@printf "$(NC)"

$(OBJ_DIR):
	@printf "$(BLUE)"
	mkdir -p $(OBJ_DIR)
	@printf "$(NC)"

clean:
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(NC)"

fclean:
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	rm -f $(LIBFTPRINTF)
	@printf "$(NC)"

re: fclean all

.PHONY: all clean fclean re