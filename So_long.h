/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:38:06 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/22 15:47:23 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "Libft2/libft.h"
# include <stdbool.h>
# include <stdio.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

typedef struct s_solong
{
	char		**tabmap;
	char		**clonemap;
	char		*strmap;
	int			countp;
	int			counte;
	int			countc;
	int			*exit;
}				t_solong;

typedef struct s_mlx
{
	void		**assets;
	void		*img;
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_hooks
{
	t_solong	*data;
	t_mlx		*mlx_data;
}				t_hooks;

int				ft_map_parsing(t_solong *data);
int				ft_flood_fill(t_solong *data, int x, int y);
void			ft_clone_map(t_solong *data);
int				ft_check_borders(t_solong *data);
int				ft_call_flood_fill(t_solong *data);
int				ft_last_line(t_solong *data);
void			ft_mlx(t_solong *data);
void			ft_go_up(t_hooks *hooks);
void			ft_go_up2(t_hooks *hooks, int *coords);
void			ft_go_down(t_hooks *hooks);
void			ft_go_down2(t_hooks *hooks, int *coords);
void			ft_go_right(t_hooks *hooks);
void			ft_go_right2(t_hooks *hooks, int *coords);
void			ft_go_left(t_hooks *hooks);
void			ft_go_left2(t_hooks *hooks, int *coords);
int				*ft_player_coords(t_solong *data);
void			ft_end_game(t_hooks *hooks);

#endif