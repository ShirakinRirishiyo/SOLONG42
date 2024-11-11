/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_practical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/17 20:51:07 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/17 20:51:07 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_check	*do_check(int height, int width)
{
	int i;
	t_check *check = malloc(sizeof(t_check));
	check->maps = malloc(height * sizeof(int *));
	i = 0;
	while (i < height)
	{
		check->maps[i] = ft_calloc(width, sizeof(int));
		i++;
	}
	check->coins_left = 0;
	check->exitparse = 0;
	return (check);
}

void	free_check(t_check *check, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(check->maps[i]);
		i++;
	}
	free(check->maps);
	free(check);
}

void	ext(t_mapa *data, int i, int j)
{
	data->start_i = i;
	data->start_j = j;
}
void	find_position(t_check *check, t_mapa *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
				ext(data, i, j);
			else if (data->map[i][j] == 'C')
				check->coins_left++;
			else if (data->map[i][j] == 'E')
			{
				check->exit_x = i;
				check->exit_y = j;
				check->exitparse = 1;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(int x, int y, t_check *check, t_mapa *data)
{
	check->maps[x][y] = 1;
	if (data->map[x][y] == 'C')
	{
		check->coins_left--;
	}
	if (is_valid(x, y - 1, check, data))
		flood_fill(x, y - 1, check, data);
	if (is_valid(x, y + 1, check, data))
		flood_fill(x, y + 1, check, data);
	if (is_valid(x - 1, y, check, data))
		flood_fill(x - 1, y, check, data);
	if (is_valid(x + 1, y, check, data))
		flood_fill(x + 1, y, check, data);
}

int	accesibility(t_mapa *data)
{
	int acceso_coleccionables;
	int acceso_salida;

	t_check *check = do_check(data->height, data->width);
	find_position(check, data);
	if (check->exitparse == 0)
		return (ft_putstr_fd(EXIT_ERR, 2), free_check(check, data->height), 0);
	flood_fill(data->start_i, data->start_j, check, data);
	acceso_coleccionables = way_to_colectables(check);
	acceso_salida = way_to_exit(check);
	if (acceso_coleccionables == 1 && acceso_salida == 1)
	{
		ft_putstr_fd("Player has access to all collectables and exit.\n", 2);
		free_check(check, data->height);
		return (1);
	}
	else
	{
		if (acceso_coleccionables == 0)
			ft_putstr_fd("Error: No access to all collectables.\n", 2);
		if (acceso_salida == 0)
			ft_putstr_fd("Error: No access to exit.\n", 2);
		free_check(check, data->height);
		return (0);
	}
}
