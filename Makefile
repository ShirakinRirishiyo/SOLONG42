NAME = so_long
NAME_BONUS = so_long_bonus

# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I./include -I./printf/libft -I./printf
LIBS = -L./printf -lftprintf -L./printf/libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm

# Archivos fuente
SRCS = load_image.c \
       ft_utils.c \
       ft_para_path.c \
       mapa_draw.c \
       mapa_movement.c \
       mapa_read.c \
       maps_error.c \
       ft_utils_maps.c \
       maps_practical.c \
       free_game.c \
       so_long.c

# Crear la lista de objetos a partir de los archivos fuente
OBJS = $(SRCS:%.c=%.o)

MINILIBX = ./minilibx-linux/libmlx_Linux.a
LIBFTPRINTF = ./printf/libftprintf.a

# Reglas
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(LIBFTPRINTF) $(MINILIBX) $(OBJS) so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBS)

# Regla para compilar cada archivo fuente en un archivo objeto
%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
	make -C ./printf

$(MINILIBX):
	make -C ./minilibx-linux

# Regla de limpieza
clean:
	make -C ./minilibx-linux clean
	make -C ./printf clean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

# Regla para limpiar completamente
fclean: clean
	make -C ./printf fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

# Regla de reconstrucción completa
re: fclean all

norm:
	norminette $(SRCS)