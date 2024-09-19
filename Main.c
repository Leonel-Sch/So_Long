/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:37:05 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 16:08:32 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_init_data(t_solong *data)
{
	data->countp = 0;
	data->counte = 0;
	data->countc = 0;
	data->strmap = NULL;
	data->tabmap = NULL;
}
void ft_print_map(t_solong *data)
{
	int i;

	i = 0;
	while (data->tabmap[i])
	{
		ft_putendl_fd(data->tabmap[i], 1);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int validity;
	t_solong data;

	ft_init_data(&data);
	if (argc != 2)
	{
		ft_putendl_fd("Wrong Number of Arguments", 2);
	}
	data.strmap = argv[1];
	validity = ft_map_parsing(&data);
	if (validity != 0)
		ft_putendl_fd("Invalid Map", 2);
	ft_print_map(&data);
	return (validity);
}