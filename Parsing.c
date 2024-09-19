/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:29:31 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 17:46:19 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft2/libft.h"
#include "So_long.h"

int	ft_last_line(t_solong *data)
{
	int	i;

	i = 0;
	while (data->tabmap[i])
		i++;
	i--;
	return (i);
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

	// bool	visited[30][60];
	ft_clone_map(data);
	coords = ft_player_coords(data);
	if (ft_flood_fill(data, coords) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->countc != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_clone_map(t_solong *data)
{
	int				i;
	unsigned long	j;

	i = 0;
	data->clonemap = malloc(sizeof(char *) * (ft_last_line(data) + 1));
	while (data->tabmap[i])
	{
		j = 0;
		data->clonemap[i] = malloc(sizeof(char) * (ft_strlen(data->tabmap[i])
					+ 1));
		while (data->tabmap[i][j])
		{
			data->clonemap[i][j] = data->tabmap[i][j];
			j++;
		}
		data->clonemap[i][j] = '\0';
		i++;
	}
	data->clonemap[i] = NULL;
}

int	ft_flood_fill(t_solong *data, int *coords)
{
	if (coords[0] < 0 || coords[0] >= ft_last_line(data) || coords[1] < 0
		|| coords[1] >= (int)ft_strlen(data->clonemap[0]))
		return (EXIT_FAILURE);
	if (data->clonemap[coords[0]][coords[1]] == '1'
		|| data->clonemap[coords[0]][coords[1]] == 'V')
		return (EXIT_FAILURE);
	if (data->clonemap[coords[0]][coords[1]] == 'C')
	{
		data->clonemap[coords[0]][coords[1]] = '0';
		data->countc--;
	}
	if (data->clonemap[coords[0]][coords[1]] == 'E')
		return (EXIT_SUCCESS);
	data->clonemap[coords[0]][coords[1]] = 'V';
	coords[0]--;
	if (ft_flood_fill(data, coords) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	coords[0]++;
	coords[0]++;
	if (ft_flood_fill(data, coords) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	coords[0]--;
	coords[1]--;
	if (ft_flood_fill(data, coords) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	coords[1]++;
	coords[1]++;
	if (ft_flood_fill(data, coords) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	coords[1]--;
	data->clonemap[coords[0]][coords[1]] = '0';
	return (EXIT_FAILURE);
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

int	ft_check_characters_values(t_solong *data)
{
	if (data->countc <= 0)
		return (EXIT_FAILURE);
	if (data->counte != 1)
		return (EXIT_FAILURE);
	if (data->countp != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_characters(t_solong *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (data->tabmap[i])
	{
		j = 0;
		while (data->tabmap[i][j])
		{
			if (data->tabmap[i][j] != '1' && data->tabmap[i][j] != '0'
				&& data->tabmap[i][j] != 'E' && data->tabmap[i][j] != 'P'
				&& data->tabmap[i][j] != 'C')
				return (EXIT_FAILURE);
			if (data->tabmap[i][j] == 'E')
				data->counte++;
			if (data->tabmap[i][j] == 'C')
				data->countc++;
			if (data->tabmap[i][j] == 'P')
				data->countp++;
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_square(t_solong *data)
{
	int				i;
	unsigned long	len;

	i = 0;
	len = ft_strlen(data->tabmap[i]);
	if (len > 60)
		return (EXIT_FAILURE);
	while (data->tabmap[i])
	{
		if (ft_strlen(data->tabmap[i]) != len)
			return (EXIT_FAILURE);
		i++;
	}
	if (i > 29)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_get_map(t_solong *data)
{
	int		fd;
	char	*line;
	char	*linetotal;

	fd = open(data->strmap, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	linetotal = "";
	while (line)
	{
		linetotal = ft_strjoin(linetotal, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->tabmap = ft_split(linetotal, '\n');
	return (ft_check_square(data));
}

int	ft_map_parsing(t_solong *data)
{
	int len;

	len = ft_strlen(data->strmap);
	if (!(data->strmap[len - 1] == 'r' && data->strmap[len - 2] == 'e'
			&& data->strmap[len - 3] == 'b' && data->strmap[len - 4] == '.'
			&& data->strmap[len - 5] >= 32 && data->strmap[len - 5] <= 127
			&& data->strmap[len - 5] != '/'))
		return (EXIT_FAILURE);
	if (ft_get_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_square(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_characters(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_characters_values(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_borders(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_call_flood_fill(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}