/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:30:20 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 18:30:20 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	frame_s(t_mapa *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	if (data->colectables == 0 && data->player == 1 && data->finish == 1)
	{
		ft_game_result(data);
	}
	return (0);
}

void	check_general(t_mapa *data)
{
	t_check		*check;

	comprobacion_open_ber(data);
	mapa_objects(data);
	check = do_check(data->height, data->width);
	find_position(check, data);
	if (accesibility(data) == 0)
	{
		write(2, "Error", 6);
		ft_putstr_fd("Invalid map\n Fail to reach colectables o exit\n", 2);
		free_check(check, data->height);
		exit(EXIT_FAILURE);
	}
	free_check(check, data->height);
}

void	reset_data(t_mapa *data, char *name)
{
	data->text = name;
}

int	main(int argc, char *argv[])
{
	t_mapa		data;

	if (argc != 2)
		return (ft_putstr_fd("Use: ./so_long <map.ber>\n", 2), 1);
	if (file_check(argv[1]) == 1)
		return (1);
	data = *((t_mapa *)memset(&data, 0, sizeof(t_mapa)));
	data.mlx = mlx_init();
	data.text = argv[1];
	load_map(&data);
	ft_check_borders(&data);
	call_function(&data, argv);
	data.win = mlx_new_window(data.mlx, data.width * SPRITE_SIZE, data.height
			* SPRITE_SIZE, "so_long");
	mlx_hook(data.win, 17, 0, exit_game, (void *)&data);
	mlx_key_hook(data.win, key_hook, (void *)&data);
	frame_s(&data);
	mlx_loop(data.mlx);
	free_game(&data);
	return (0);
}
