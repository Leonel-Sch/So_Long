/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:19:16 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/22 16:05:29 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_initialize_assets(t_mlx *mlx_data, int width, int height)
{
	mlx_data->assets[0] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Wall.xpm", &width, &height);
	mlx_data->assets[1] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Floor.xpm", &width, &height);
	mlx_data->assets[2] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Exit.xpm", &width, &height);
	mlx_data->assets[3] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Player.xpm", &width, &height);
	mlx_data->assets[4] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Collectibles.xpm", &width, &height);
}

void	ft_initialize_window(t_mlx *mlx_data, t_solong *data, int i, int j)
{
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

int	ft_close(t_hooks *hooks)
{
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->img);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[0]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[1]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[2]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[3]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[4]);
	mlx_destroy_window(hooks->mlx_data->mlx, hooks->mlx_data->win);
	mlx_destroy_display(hooks->mlx_data->mlx);
	free(hooks->mlx_data->mlx);
	free(hooks->mlx_data->assets);
	free(hooks->data->exit);
	ft_free_tab(hooks->data->tabmap, 0);
	exit(EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, t_hooks *hooks)
{
	if (keycode == ESC_KEY)
		ft_close(hooks);
	else if (keycode == W_KEY)
		ft_go_up(hooks);
	else if (keycode == A_KEY)
		ft_go_left(hooks);
	else if (keycode == S_KEY)
		ft_go_down(hooks);
	else if (keycode == D_KEY)
		ft_go_right(hooks);
	ft_initialize_window(hooks->mlx_data, hooks->data, 0, 0);
	return (0);
}

void	ft_mlx(t_solong *data)
{
	t_mlx	mlx_data;
	t_hooks	hooks;

	hooks.data = data;
	hooks.mlx_data = &mlx_data;
	mlx_data.mlx = mlx_init();
	mlx_data.assets = malloc(sizeof(void *) * 5);
	ft_initialize_assets(&mlx_data, 32, 32);
	mlx_data.win = mlx_new_window(mlx_data.mlx, 32 * ft_strlen(data->tabmap[0]),
			32 * ((ft_last_line(data)) + 1), "So_long");
	mlx_data.img = mlx_new_image(mlx_data.mlx, 32 * ft_strlen(data->tabmap[0]),
			32 * ((ft_last_line(data)) + 1));
	ft_initialize_window(&mlx_data, data, 0, 0);
	sleep(1);
	mlx_hook(mlx_data.win, 17, 0, ft_close, &hooks);
	if (mlx_key_hook(mlx_data.win, ft_key_hook, &hooks) == 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx_data.mlx);
}
