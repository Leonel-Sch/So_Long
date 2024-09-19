/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:44:43 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 19:34:48 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_clone_map(t_solong *data)
{
	int				i;
	unsigned long	j;

	i = 0;
	data->clonemap = malloc(sizeof(char *) * (ft_last_line(data) + 2));
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

int	ft_last_line(t_solong *data)
{
	int	i;

	i = 0;
	while (data->tabmap[i])
		i++;
	i--;
	return (i);
}