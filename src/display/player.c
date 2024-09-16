/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/16 16:32:08 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	clean_frame(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WINDOWSW)
	{
		while (x < WINDOWSH)
		{
			mlx_put_pixel(data->rayc, y, x, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	clean_frame(data);
	raycasting(data);
	clean_frame(data);
	mini(data);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	double	olddri_x;
	double	oldplane_x;

	map = (t_map *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(map->mlx);
		if (keydata.key == MLX_KEY_UP)
		{
			map->game->player_x += map->game->dir_x * 0.1;
			map->game->player_y += map->game->dir_y * 0.1;
		}
		if (keydata.key == MLX_KEY_LEFT)
		{
			olddri_x = map->game->dir_x;
			map->game->dir_x = map->game->dir_x * cos(-rotspeed) - map->game->dir_y * sin(-rotspeed);
			map->game->dir_y = olddri_x * sin(-rotspeed) + map->game->dir_y* cos(-rotspeed);
			oldplane_x = map->game->plane_x;
			map->game->plane_x =  map->game->plane_x * cos(-rotspeed) -  map->game->plane_y * sin(-rotspeed);
			map->game->plane_y =  oldplane_x * sin(-rotspeed) +  map->game->plane_y * cos(-rotspeed);
		}
		if (keydata.key == MLX_KEY_RIGHT)
		{
			olddri_x = map->game->dir_x;
			map->game->dir_x = map->game->dir_x * cos(rotspeed) - map->game->dir_y * sin(rotspeed);
			map->game->dir_y = olddri_x * sin(rotspeed) + map->game->dir_y * cos(rotspeed);
			oldplane_x = map->game->plane_x;
			map->game->plane_x =  map->game->plane_x * cos(rotspeed) -  map->game->plane_y * sin(rotspeed);
			map->game->plane_y =  oldplane_x * sin(rotspeed) +  map->game->plane_y * cos(rotspeed);
		}
		
	}
}
