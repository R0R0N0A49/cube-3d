/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/28 10:10:27 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_x * data->speed * data->mlx->delta_time;
	testy += data->game->dir_y * data->speed * data->mlx->delta_time;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
	
}

void	move_s(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx -= data->game->dir_x * data->speed * data->mlx->delta_time;
	testy -= data->game->dir_y * data->speed * data->mlx->delta_time;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
}

void	move_a(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_y * data->speed * data->mlx->delta_time;
	testy -= data->game->dir_x * data->speed * data->mlx->delta_time;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
}

void	move_d(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx -= data->game->dir_y * data->speed * data->mlx->delta_time;
	testy += data->game->dir_x * data->speed * data->mlx->delta_time;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
}