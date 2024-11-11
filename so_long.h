/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/13 11:55:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 07:53:20 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
# include "./printf/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_MAP_WIDTH 100
# define MAX_MAP_HEIGHT 100

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define SPRITE_SIZE 64

# define WALL_IMAGE "./sprites/walls.xpm"
# define SPACE_IMAGE "./sprites/pared.xpm"
# define PLAYER_F1 "./sprites/player1.xpm"
# define COLLECT1_IMAGE "./sprites/oritoabajo.xpm"
# define EXIT_IMAGE "./sprites/castle.xpm"

# define EXIT_ERR "Error: Did not find an exit.\n"

# define VALIDOS "10CPE"

typedef struct s_check
{
	int			**maps;
	int			coins_left;
	int			exitparse;
	int			exit_x;
	int			exit_y;
} t_check;

typedef struct s_imagenes
{
	void		*wall;
	void		*space;
	void		*player_frame1;
	void		*player_frame2;
	void		*collect;
	void		*exit;
	void		*torre;
	void		*fuego1;
	void		*fuego2;
} t_imagenes;

typedef struct s_mapa
{
	char		*text;
	char		**map;
	int			height;
	int			width;
	int			i;
	int			element;
	int			start_i;
	int			start_j;
	int			j;
	int			x;
	int			y;
	int			size_x;
	int			size_y;
	int			exit;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			player;
	int			colectables;
	int			finish;
	long		steps;
	void		*mlx;
	void		*win;
	t_imagenes	*imagenes;
} t_mapa;

typedef struct s_indices
{
	int			i;
	int			j;
	int			end;
} t_indices;

typedef struct s_mapa_info
{
	int			fd;
	char		*line;
	int			line_length;
	int			current_line_length;
	int			first_line_length;
	int			is_rectangular;
	int			i;
} t_mapa_info;

void	load_map(t_mapa *data);
int		load_image(t_mapa *data, void **img, char *ruta);
void	find_position(t_check *check, t_mapa *data);
int		is_valid(int x, int y, t_check *check, t_mapa *data);
void	flood_fill(int x, int y, t_check *check, t_mapa *data);
void	init_map(t_mapa *data, t_mapa_info *info);
void	reset_data(t_mapa *data, char *name);
int		frame_s(t_mapa *data);
int		key_hook(int keycode, void *param);
void	ft_printing(long n);
int		exit_game(t_mapa *data, int win);
void	ft_check_borders(t_mapa *data);
void	ft_game_result(t_mapa *data);
void	update_window(t_mapa *data);
void	ext(t_mapa *data, int i, int j);
void	draw_map(t_mapa *data);
void	mapa_objects(t_mapa *data);
int		load_images(t_mapa *data);
t_check	*do_check(int height, int width);
void	free_check(t_check *check, int height);
int		accesibility(t_mapa *data);
void	comprobacion_open_ber(t_mapa *data);
void	ft_window_size(t_mapa *data);
int		is_valid(int x, int y, t_check *check, t_mapa *data);
void	flood_fill(int x, int y, t_check *check, t_mapa *data);
int		way_to_colectables(t_check *check);
int		way_to_exit(t_check *check);
int		call_function(t_mapa *data, char **argv);
void	check_general(t_mapa *data);
void	reset_data(t_mapa *data, char *name);
void	check_general(t_mapa *data);
void	free_game(t_mapa *data);
void	free_array(char **array);
void	exit_error(char *message);
void	mapa_memory(t_mapa *data);

#endif
