/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:36:53 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 19:43:38 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	ft_flood_fill(t_solong *data, int x, int y)
{
	if (x < 0 || x >= ft_last_line(data) || y < 0
		|| y >= (int)ft_strlen(data->clonemap[0]))
		return (EXIT_FAILURE);
	if (data->clonemap[x][y] == '1' || data->clonemap[x][y] == 'V')
		return (EXIT_FAILURE);
	if (data->clonemap[x][y] == 'C')
	{
		data->clonemap[x][y] = '0';
		data->countc--;
	}
	if (data->clonemap[x][y] == 'E')
		data->counte--;
	if ((data->clonemap[x][y] == 'E' || data->counte == 0) && data->countc == 0)
		return (EXIT_SUCCESS);

	data->clonemap[x][y] = 'V';
	if (ft_flood_fill(data, x + 1, y) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (ft_flood_fill(data, x - 1, y) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (ft_flood_fill(data, x, y + 1) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (ft_flood_fill(data, x, y - 1) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	data->clonemap[x][y] = '0';
	return (EXIT_FAILURE);
}

int	*ft_player_coords(t_solong *data)
{
	int	i;
	int	j;
	int	*coords;

	i = 0;
	coords = malloc(sizeof(int) * 2);
	while (data->tabmap[i])
	{
		j = 0;
		while (data->tabmap[i][j])
		{
			if (data->tabmap[i][j] == 'P')
			{
				coords[0] = i;
				coords[1] = j;
				return (coords);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	ft_call_flood_fill(t_solong *data)
{
	int	*coords;

	ft_clone_map(data);
	coords = ft_player_coords(data);
	if (ft_flood_fill(data, coords[0], coords[1]) == EXIT_FAILURE)
		return (free(coords), ft_free_tab(data->clonemap, 0), EXIT_FAILURE);
	if (data->countc != 0)
		return (free(coords), ft_free_tab(data->clonemap, 0), EXIT_FAILURE);
	return (free(coords), ft_free_tab(data->clonemap, 0), EXIT_SUCCESS);
}

int	ft_check_borders(t_solong *data)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (data->tabmap[i])
	{
		j = 0;
		while (data->tabmap[i][j])
		{
			if (i == 0 || i == ft_last_line(data))
			{
				if (data->tabmap[i][j] != '1')
					return (EXIT_FAILURE);
			}
			if (j == 0 || j == ft_strlen(data->tabmap[i]) - 1)
			{
				if (data->tabmap[i][j] != '1')
					return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

