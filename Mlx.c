/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:19:16 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/19 20:50:52 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_mlx(t_solong *data)
{
	void *mlx;
	void *win;
	t_mlx img;

	data->countc = 0;
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	win = mlx_new_window(mlx, 800, 600, "So_long");
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	//mlx_hook(win, 2, 1L << 0, ft_key_hook, data);
	//mlx_hook(win, 17, 1L << 17, ft_close, mlx);

	mlx_loop(mlx);
}