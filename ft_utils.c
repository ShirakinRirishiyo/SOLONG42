/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:48:48 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 22:31:42 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(char *file)
{
	char		*filename;

	if (ft_strlen(file) <= 4 || ft_strncmp(&file[ft_strlen(file) - 4],
			".ber", 4))
		return (ft_putstr_fd("Incorrect Name\n", 2), 1);
	filename = ft_strrchr(file, '/');
	if (filename != NULL && ft_strncmp(filename, "/.ber", 5) == 0)
		return (ft_putstr_fd("Incorrect Name!!!\n", 2), 1);
	return (0);
}

int	exit_game(t_mapa *data, int win)
{
	if (win == 0)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|              You gave up :(                    |\n");
		ft_printf("|   Is the game too hard for you? Try again...   |\n");
		ft_printf("--------------------------------------------------\n");
	}
	else if (win == 1)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|  You won!! :D Now Play Albion!                 |\n");
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
