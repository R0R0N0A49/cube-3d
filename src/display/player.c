/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/16 09:20:59 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	clean_frame(mlx_image_t *frame)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WINDOWSW)
	{
		while (x < WINDOWSH)
		{
			mlx_put_pixel(frame, y, x, 0x00000000);
			x++;
		}
		y++;
	}
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	clean_frame(data->rayc);
	raycasting(data);
	mini(data);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(map->mlx);
	}
}
