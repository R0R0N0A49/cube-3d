/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:01:23 by derey             #+#    #+#             */
/*   Updated: 2024/11/19 08:58:55 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_map *data)
{
	double	savex;
	double	savey;

	savex = data->game->player_x;
	savey = data->game->player_y;
	savex += data->game->dir_x * data->speed * data->mlx->delta_time;
	savey += data->game->dir_y * data->speed * data->mlx->delta_time;
	if (data->map[(int)savey][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)savex] == '1')
			return ;
		data->game->player_x = savex;
		return ;
	}
	data->game->player_y = savey;
	if (data->map[(int)data->game->player_y][(int)savex] == '1')
		return ;
	data->game->player_x = savex;
}

void	move_s(t_map *data)
{
	double	savex;
	double	savey;

	savex = data->game->player_x;
	savey = data->game->player_y;
	savex -= data->game->dir_x * data->speed * data->mlx->delta_time;
	savey -= data->game->dir_y * data->speed * data->mlx->delta_time;
	if (data->map[(int)savey][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)savex] == '1')
			return ;
		data->game->player_x = savex;
		return ;
	}
	data->game->player_y = savey;
	if (data->map[(int)data->game->player_y][(int)savex] == '1')
		return ;
	data->game->player_x = savex;
}

void	move_a(t_map *data)
{
	double	savex;
	double	savey;

	savex = data->game->player_x;
	savey = data->game->player_y;
	savex += data->game->dir_y * data->speed * data->mlx->delta_time;
	savey -= data->game->dir_x * data->speed * data->mlx->delta_time;
	if (data->map[(int)savey][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)savex] == '1')
			return ;
		data->game->player_x = savex;
		return ;
	}
	data->game->player_y = savey;
	if (data->map[(int)data->game->player_y][(int)savex] == '1')
		return ;
	data->game->player_x = savex;
}

void	move_d(t_map *data)
{
	double	savex;
	double	savey;

	savex = data->game->player_x;
	savey = data->game->player_y;
	savex -= data->game->dir_y * data->speed * data->mlx->delta_time;
	savey += data->game->dir_x * data->speed * data->mlx->delta_time;
	if (data->map[(int)savey][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)savex] == '1')
			return ;
		data->game->player_x = savex;
		return ;
	}
	data->game->player_y = savey;
	if (data->map[(int)data->game->player_y][(int)savex] == '1')
		return ;
	data->game->player_x = savex;
}
