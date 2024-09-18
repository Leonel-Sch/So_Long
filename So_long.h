/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:38:06 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/18 19:48:21 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft2/libft.h"
# include <stdio.h>

typedef struct s_solong
{
	char	**tabmap;
	char	*strmap;
	int		countp;
	int		counte;
	int		countc;
}			t_solong;

int			ft_map_parsing(t_solong *data);

#endif