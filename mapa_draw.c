/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:42:47 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 18:11:19 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_element(t_mapa *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * SPRITE_SIZE, y
		* SPRITE_SIZE);
}

static void	draw_element_of_map(t_mapa *data, int i, int j)
{
	if (data->map[i][j] == '1')
		draw_element(data, data->imagenes->wall, j, i);
	else if (data->map[i][j] == '0')
		draw_element(data, data->imagenes->space, j, i);
	else if (data->map[i][j] == 'P')
		draw_element(data, data->imagenes->player_frame1, j, i);
	else if (data->map[i][j] == 'C')
	{
		draw_element(data, data->imagenes->collect, j, i);
		if (data->x == j && data->y == i)
		{
			data->map[i][j] = '0';
			data->colectables--;
		}
	}
	else if (data->map[i][j] == 'E')
		draw_element(data, data->imagenes->exit, j, i);
	else
		ft_putstr_fd("Error: Carácter no válido\n", 2);
}

void	draw_map(t_mapa *data)
{
	int	i;
	int	j;

	if (data == NULL || data->map == NULL || data->imagenes == NULL)
	{
		ft_putstr_fd("Error: Datos no inicializados.\n", 2);
		return ;
	}
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_element_of_map(data, i, j);
			j++;
		}
		i++;
	}
}
