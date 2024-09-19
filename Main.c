/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:37:05 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 20:19:05 by lscheupl         ###   ########.fr       */
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
	data->clonemap = NULL;
}

int	main(int argc, char **argv)
{
	t_solong	data;

	ft_init_data(&data);
	if (argc != 2)
	{
		ft_putendl_fd("Wrong Number of Arguments", 2);
	}
	data.strmap = argv[1];
	if (ft_map_parsing(&data) == EXIT_FAILURE)
		return (ft_putendl_fd("Invalid Map", 2), EXIT_FAILURE);
	ft_mlx(&data);
	return (EXIT_SUCCESS);
}
