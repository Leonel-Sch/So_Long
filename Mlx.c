/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:19:16 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/21 21:14:13 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void ft_initialize_assets(t_mlx *mlx_data, int width, int height)
{
	mlx_data->assets[0] = mlx_xpm_file_to_image(mlx_data->mlx, "assets/Wall.xpm",
			&width, &height);
	mlx_data->assets[1] = mlx_xpm_file_to_image(mlx_data->mlx, "assets/Floor.xpm",
			&width, &height);
	mlx_data->assets[2] = mlx_xpm_file_to_image(mlx_data->mlx, "assets/Exit.xpm",
			&width, &height);
	mlx_data->assets[3] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Player.xpm", &width, &height);
	mlx_data->assets[4] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Collectibles.xpm", &width, &height);
}

void ft_initialize_window(t_mlx *mlx_data, t_solong *data)
{
	int i;
	int j;
	i = 0;
	while (data->tabmap[i])
	{
		j = 0;
		while (data->tabmap[i][j])
		{
			if (data->tabmap[i][j] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[0], j * 32, i * 32);
			if (data->tabmap[i][j] == '0')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[1], j * 32, i * 32);
			if (data->tabmap[i][j] == 'E')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[2], j * 32, i * 32);
			if (data->tabmap[i][j] == 'P')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[3], j * 32, i * 32);
			if (data->tabmap[i][j] == 'C')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[4], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	ft_mlx(t_solong *data)
{
	t_mlx mlx_data;
	int width;
	int height;

	mlx_data.mlx = mlx_init();
	mlx_data.assets = malloc(sizeof(void *) * 6);
	width = 32;
	height = 32;
	ft_initialize_assets(&mlx_data, width, height);
	mlx_data.img = mlx_new_image(mlx_data.mlx, 32 * ft_strlen(data->tabmap[0]),
			32 * ((ft_last_line(data)) + 1));
	mlx_data.win = mlx_new_window(mlx_data.mlx, 32 * ft_strlen(data->tabmap[0]),
			32 * ((ft_last_line(data)) + 1), "So_long");
	ft_initialize_window(&mlx_data, data);
	sleep(3);
	data->tabmap[0][0] = 'P';
	ft_initialize_window(&mlx_data, data);
	sleep(1);
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	mlx_loop(mlx_data.mlx);
}