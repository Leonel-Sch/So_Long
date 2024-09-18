/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:29:31 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/18 19:52:29 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft2/libft.h"
#include "So_long.h"

int ft_check_characters_values(t_solong *data)
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
	return (ft_check_characters_values(data));
}

int	ft_check_square(t_solong *data)
{
	int	i;
	unsigned long	len;

	i = 0;
	len = ft_strlen(data->tabmap[i]);
	while (data->tabmap[i])
	{
		if (ft_strlen(data->tabmap[i]) != len)
			return (EXIT_FAILURE);
		i++;
	}
	return (ft_check_characters(data));
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
	return (EXIT_SUCCESS);
}