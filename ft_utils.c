/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:48:48 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 16:51:03 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printing(long n)
{
	ft_printf("Steps: %d\n", n);
}

int	exit_game(t_mapa *data, int win)
{
	if (win == 0)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|              You gave up :(                    |\n");
		ft_printf("|   Is the game hard for you? Try again......    |\n");
		ft_printf("--------------------------------------------------\n");
	}
	else if (win == 1)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|                You won!! :D                    |\n");
		ft_printf("--------------------------------------------------\n");
	}
	free_game(data);
	if (win == 2)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	ft_game_result(t_mapa *data)
{
	int	x;
	int	y;

	mlx_clear_window(data->mlx, data->win);
	x = data->width * 40 / 2.4;
	y = data->height * 40 / 4;
	ft_printf("Drawing result (%d, %d)\n", x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->imagenes->player_frame1,
		x, y);
}

void	update_window(t_mapa *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
}
