NAME = libftprintf.a
CC = gcc
SRCS = conversion_tools.c \
		secundarias.c \
		ft_printf.c \
		ft_puthexa.c \

LIBFT_DIR = libft
LIBFT_LIBRARY = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs

all: $(LIBFT_LIBRARY) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT_LIBRARY) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT_LIBRARY):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
