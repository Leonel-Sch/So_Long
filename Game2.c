/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:46:33 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/22 15:48:46 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_go_left(t_hooks *hooks)
{
	int	*coords;

	coords = ft_player_coords(hooks->data);
	if (hooks->data->tabmap[coords[0]][coords[1] - 1] == '0')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0]][coords[1] - 1] = 'P';
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	if (hooks->data->tabmap[coords[0]][coords[1] - 1] == 'C')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0]][coords[1] - 1] = 'P';
		hooks->data->countc--;
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	ft_go_left2(hooks, coords);
}

void	ft_go_left2(t_hooks *hooks, int *coords)
{
	if (hooks->data->tabmap[coords[0]][coords[1] - 1] == 'E'
		&& hooks->data->countc == 0)
	{
		free(coords);
		ft_end_game(hooks);
	}
	if (hooks->data->tabmap[coords[0]][coords[1] - 1] == 'E'
		&& hooks->data->countc != 0)
	{
		hooks->data->exit[0] = coords[0];
		hooks->data->exit[1] = coords[1] - 1;
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0]][coords[1] - 1] = 'P';
	}
	free(coords);
}

void	ft_go_right(t_hooks *hooks)
{
	int	*coords;

	coords = ft_player_coords(hooks->data);
	if (hooks->data->tabmap[coords[0]][coords[1] + 1] == '0')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0]][coords[1] + 1] = 'P';
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	if (hooks->data->tabmap[coords[0]][coords[1] + 1] == 'C')
	{
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0]][coords[1] + 1] = 'P';
		hooks->data->countc--;
		if (hooks->data->exit[0] == coords[0]
			&& hooks->data->exit[1] == coords[1])
			hooks->data->tabmap[coords[0]][coords[1]] = 'E';
	}
	ft_go_right2(hooks, coords);
}

void	ft_go_right2(t_hooks *hooks, int *coords)
{
	if (hooks->data->tabmap[coords[0]][coords[1] + 1] == 'E'
		&& hooks->data->countc == 0)
	{
		free(coords);
		ft_end_game(hooks);
	}
	if (hooks->data->tabmap[coords[0]][coords[1] + 1] == 'E'
		&& hooks->data->countc != 0)
	{
		hooks->data->exit[0] = coords[0];
		hooks->data->exit[1] = coords[1] + 1;
		hooks->data->tabmap[coords[0]][coords[1]] = '0';
		hooks->data->tabmap[coords[0]][coords[1] + 1] = 'P';
	}
	free(coords);
}
