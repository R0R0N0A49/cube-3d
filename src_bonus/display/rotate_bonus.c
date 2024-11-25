/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:22:24 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 18:22:47 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;
	double	speed;

	olddri_x = map->game->dir_x;
	speed = map->rotspeed * map->mlx->delta_time;
	map->game->dir_x = map->game->dir_x * cos(-speed)
		- map->game->dir_y * sin(-speed);
	map->game->dir_y = olddri_x * sin(-speed) + map->game->dir_y * cos(-speed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x = map->game->plane_x * cos(-speed)
		- map->game->plane_y * sin(-speed);
	map->game->plane_y = oldplane_x * sin(-speed)
		+ map->game->plane_y * cos(-speed);
}

void	rotate_right(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;
	double	speed;

	olddri_x = map->game->dir_x;
	speed = map->rotspeed * map->mlx->delta_time;
	map->game->dir_x = map->game->dir_x * cos(speed)
		- map->game->dir_y * sin(speed);
	map->game->dir_y = olddri_x * sin(speed) + map->game->dir_y * cos(speed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x = map->game->plane_x * cos(speed)
		- map->game->plane_y * sin(speed);
	map->game->plane_y = oldplane_x * sin(speed)
		+ map->game->plane_y * cos(speed);
}
