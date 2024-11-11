/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:09:14 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 15:46:47 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

void	free_game(t_mapa *data)
{
	mlx_destroy_image(data->mlx, data->imagenes->wall);
	mlx_destroy_image(data->mlx, data->imagenes->space);
	mlx_destroy_image(data->mlx, data->imagenes->player_frame1);
	mlx_destroy_image(data->mlx, data->imagenes->collect);
	mlx_destroy_image(data->mlx, data->imagenes->exit);
	free(data->imagenes);
	free_array(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}