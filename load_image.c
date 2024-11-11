/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:42:24 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 15:42:24 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	load_image(t_mapa *data, void **img, char *ruta)
{
	int img_width;
	int img_height;

	if (data == NULL || data->mlx == NULL)
	{
		perror("Error: data o data->mlx es NULL.\n");
		return (1);
	}
	ft_printf("Cargando imagen desde: %s\n", ruta);
	*img = mlx_xpm_file_to_image(data->mlx, ruta, &img_width, &img_height);
	if (*img == NULL)
	{
		perror("Error al cargar la imagen");
		return (1);
	}
	ft_printf("Imagen cargada exitosamente.\n");
	return (0);
}

int	load_images(t_mapa *data)
{
	ft_printf("Intentando cargar imágenes...\n");
	data->imagenes = (t_imagenes *)malloc(sizeof(t_imagenes));
	if (data->imagenes == NULL)
	{
		ft_putstr_fd("Error al asignar memoria para imágenes.\n", 2);
		return (1);
	}
	if (load_image(data, &(data->imagenes->wall), WALL_IMAGE))
		return (1);
	if (load_image(data, &(data->imagenes->space), SPACE_IMAGE))
		return (1);
	if (load_image(data, &(data->imagenes->player_frame1), PLAYER_F1))
		return (1);
	if (load_image(data, &(data->imagenes->collect), COLLECT1_IMAGE))
		return (1);
	if (load_image(data, &(data->imagenes->exit), EXIT_IMAGE))
		return (1);
	ft_printf("Todas las imágenes cargadas correctamente.\n");
	return (0);
}

int	call_function(t_mapa *data, char **argv)
{
	reset_data(data, argv[1]);
	check_general(data);
	load_images(data);
	return (EXIT_SUCCESS);
}
