/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:49:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 16:50:46 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_mapa *data, t_mapa_info *info)
{
	info->fd = open(data->text, O_RDONLY);
	if (info->fd == -1)
	{
		ft_putendl_fd("Error al abrir el archivo de mapa.\n", 2);
		exit_game(data, 2);
	}
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
	{
		ft_putendl_fd("Malloc error\n", 2);
		exit_game(data, 2);
	}
	info->i = 0;
}
