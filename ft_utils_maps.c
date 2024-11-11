/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:49:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 19:04:06 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_check(t_check *check, int height)
{
	int	i;

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

void	mapa_memory(t_mapa *data)
{
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->map == NULL)
	{
		ft_putendl_fd("Error al asignar memoria para el mapa", 2);
		exit_game(data, 2);
	}
}
