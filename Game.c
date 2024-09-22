/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:31:42 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/22 16:04:14 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_end_game(t_hooks *hooks)
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
	ft_putendl_fd("You Win!", 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
}

void	ft_go_up(t_hooks *hooks)
{
	int	*coords;

	coords = ft_player_coords(hooks->data);
	if (hooks->data->tabmap[coords[0] - 1][coords[1]] == '0')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0] - 1][coords[1]] = 'P';
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	if (hooks->data->tabmap[coords[0] - 1][coords[1]] == 'C')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0] - 1][coords[1]] = 'P';
		hooks->data->countc--;
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	ft_go_up2(hooks, coords);
}

void	ft_go_up2(t_hooks *hooks, int *coords)
{
	if (hooks->data->tabmap[coords[0] - 1][coords[1]] == 'E'
		&& hooks->data->countc == 0)
	{
		free(coords);
		ft_end_game(hooks);
	}
	if (hooks->data->tabmap[coords[0] - 1][coords[1]] == 'E'
		&& hooks->data->countc != 0)
	{
		hooks->data->exit[0] = coords[0] - 1;
		hooks->data->exit[1] = coords[1];
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0] - 1][coords[1]] = 'P';
	}
	free(coords);
}

void	ft_go_down(t_hooks *hooks)
{
	int	*coords;

	coords = ft_player_coords(hooks->data);
	if (hooks->data->tabmap[coords[0] + 1][coords[1]] == '0')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0] + 1][coords[1]] = 'P';
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	if (hooks->data->tabmap[coords[0] + 1][coords[1]] == 'C')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0] + 1][coords[1]] = 'P';
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
		hooks->data->countc--;
	}
	ft_go_down2(hooks, coords);
}

void	ft_go_down2(t_hooks *hooks, int *coords)
{
	if (hooks->data->tabmap[coords[0] + 1][coords[1]] == 'E'
		&& hooks->data->countc == 0)
	{
		free(coords);
		ft_end_game(hooks);
	}
	if (hooks->data->tabmap[coords[0] + 1][coords[1]] == 'E'
		&& hooks->data->countc != 0)
	{
		hooks->data->exit[0] = coords[0] + 1;
		hooks->data->exit[1] = coords[1];
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0] + 1][coords[1]] = 'P';
	}
	free(coords);
}
