/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:22:24 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:13:19 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	rotate_cur(t_map *data)
{
	double	angle;
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	angle = 0;
	if (data->pause == false)
	{
		angle += (x - WINDOWSW * 0.5) * 0.0005;
		if (angle != 0)
		{
			if (x - WINDOWSW * 0.5 < 0)
				rotate_left(data, 0.7 * -angle);
			else
				rotate_right(data, 0.7 * angle);
		}
		mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	}
}

void	rotate_left(t_map *map, double speed)
{
	double	olddri_x;
	double	oldplane_x;

	olddri_x = map->game->dir_x;
	map->game->dir_x = map->game->dir_x * cos(-speed)
		- map->game->dir_y * sin(-speed);
	map->game->dir_y = olddri_x * sin(-speed) + map->game->dir_y * cos(-speed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x = map->game->plane_x * cos(-speed)
		- map->game->plane_y * sin(-speed);
	map->game->plane_y = oldplane_x * sin(-speed)
		+ map->game->plane_y * cos(-speed);
}

void	rotate_right(t_map *map, double speed)
{
	double	olddri_x;
	double	oldplane_x;

	olddri_x = map->game->dir_x;
	map->game->dir_x = map->game->dir_x * cos(speed)
		- map->game->dir_y * sin(speed);
	map->game->dir_y = olddri_x * sin(speed) + map->game->dir_y * cos(speed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x = map->game->plane_x * cos(speed)
		- map->game->plane_y * sin(speed);
	map->game->plane_y = oldplane_x * sin(speed)
		+ map->game->plane_y * cos(speed);
}
