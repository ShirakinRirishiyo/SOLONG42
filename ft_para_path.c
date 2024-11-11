/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:14:53 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 16:48:52 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	way_to_colectables(t_check *check)
{
	return (check->coins_left == 0);
}

int	way_to_exit(t_check *check)
{
	return (check->maps[check->exit_x][check->exit_y] == 1);
}

int	is_valid(int x, int y, t_check *check, t_mapa *data)
{
	if (x >= 0 && x < data->height && y >= 0 && y < data->width
		&& data->map[x][y] != '1' && check->maps[x][y] == 0)
	{
		return (1);
	}
	return (0);
}
