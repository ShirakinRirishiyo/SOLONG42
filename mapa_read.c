/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:36:48 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 18:17:16 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapa_dimention(t_mapa *data)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(data->text, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (len > data->width)
			data->width = len - 1;
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	if (fd >= 0)
		close(fd);
	if (fd == -1 || data->height == 0 || data->width == 0)
	{
		ft_putendl_fd("Error en el archivo", 2);
		exit_game(data, 2);
	}
}

void	upload_map_content(t_mapa *data)
{
	char	*line;
	int		fd;
	int		i;
	int		len;

	fd = open(data->text, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error al abrir el archivo", 2);
		exit_game(data, 2);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		data->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	data->map[i] = NULL;
	close(fd);
}

void	load_map(t_mapa *data)
{
	mapa_dimention(data);
	mapa_memory(data);
	upload_map_content(data);
}

void	ft_window_size(t_mapa *data, void *mlx)
{
	int		screen_width;
	int		screen_height;
	int		map_width_pixels;
	int		map_height_pixels;

	map_width_pixels = data->width * SPRITE_SIZE;
	map_height_pixels = data->height * SPRITE_SIZE;
	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	if (map_width_pixels > screen_width || map_height_pixels > screen_height)
	{
		ft_putendl_fd("Error: Map is longer than window.", 2);
		exit_game(data, 2);
	}
}

void	free_map(t_mapa *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
