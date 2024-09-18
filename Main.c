/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:37:05 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/18 15:45:39 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main(int argc, char **argv)
{
	int validity;
	t_solong data;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong Number of Arguments", 2);
	}
	data.strmap = argv[1];
	validity = ft_map_parsing(&data);
	if (validity != 0)
		ft_putendl_fd("Invalid Map", 2);
	return (validity);
}