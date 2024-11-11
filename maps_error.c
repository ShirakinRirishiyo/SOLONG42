/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:20:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 16:31:56 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapa_objects(t_mapa *data)
{
	t_indices	indices;

	indices.j = 0;
	indices.end = 0;
	while (data->map[++indices.j])
	{
		indices.i = 0;
		while (data->map[indices.j][++indices.i])
		{
			if (data->map[indices.j][indices.i] == 'P')
			{
				data->x = indices.i;
				data->y = indices.j;
				data->player++;
			}
			else if (data->map[indices.j][indices.i] == 'C')
				data->colectables++;
			else if (data->map[indices.j][indices.i] == 'E')
				indices.end++;
		}
	}
	if (data->player != 1 || data->colectables < 1 || indices.end != 1)
		exit_error("Bad elements");
}

void	exit_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_check_borders(t_mapa *data)
{
	int	idx;

	idx = 0;
	while (idx < data->width)
	{
		if (data->map[0][idx] != '1' || data->map[data->height - 1][idx] != '1')
			exit_error("Error: El borde superior o inferior no está cerrado.");
		idx++;
	}
	idx = 0;
	while (idx < data->height)
	{
		if (data->map[idx][0] != '1' || data->map[idx][data->width - 1] != '1')
			exit_error("Error: El borde izquierdo o derecho no está cerrado.");
		idx++;
	}
}

void	comprobacion_open_ber(t_mapa *data)
{
	size_t	longitud;

	longitud = ft_strlen(data->text);
	if (longitud < 4 || ft_strncmp(&data->text[longitud - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: el archivo debe tener la extensión .ber\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_printf("El archivo %s es válido\n", data->text);
}
