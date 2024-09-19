/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:38:06 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 19:57:57 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft2/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <minilibx-linux/mlx.h>

typedef struct s_solong
{
	char	**tabmap;
	char	**clonemap;
	char	*strmap;
	int		countp;
	int		counte;
	int		countc;
}			t_solong;

typedef struct s_flood_fill
{
	int		col;
	int		row;
}			t_flood_fill;


int			ft_map_parsing(t_solong *data);
int	ft_flood_fill(t_solong *data, int x , int y);
void ft_clone_map(t_solong *data);
int	ft_check_borders(t_solong *data);
int	ft_call_flood_fill(t_solong *data);
int	ft_last_line(t_solong *data);

#endif