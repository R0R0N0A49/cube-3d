/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 18:51:11 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	time_fps(t_map	*data)
{
	double	time_dif;

	time_dif = difftime(time(NULL), data->time_fps);
	if (time_dif >= 1)
	{
		data->fps = (int)(1 / data->mlx->delta_time);
		data->time_fps = time(NULL);
	}
}

int	get_pc(int value, int size, int max)
{
	return ((size * value) / max);
}

void	pause_game(t_map *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	data->weapon.selected[2]->enabled = false;
	data->weapon.selected[data->weapon.index_weapon]->enabled = false;
	data->pause = true;
	data->menu->enabled = true;
	data->cubd->enabled = true;
	data->img_play->enabled = true;
	data->img_option->enabled = true;
	data->img_exit->enabled = true;
	data->game->move_w = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->weapon.enable_anim = false;
	choose_weapon(data);
	data->weapon.center->enabled = false;
}

void	exit_cub3d(t_map *data)
{
	mlx_close_window(data->mlx);
}

void	play_game(t_map *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	data->weapon.selected[2]->enabled = true;
	data->weapon.selected[data->weapon.index_weapon]->enabled = true;
	data->pause = false;
	data->idx_menu = 0;
	data->but_play->press_enter = false;
	data->but_play->good = false;
	data->menu->enabled = false;
	data->cubd->enabled = false;
	data->img_play->enabled = false;
	data->img_option->enabled = false;
	data->img_exit->enabled = false;
	data->game->move_w = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->but_play->good = false;
	data->but_option->good = false;
	data->but_exit->good = false;
	data->menu_option->but_rtn->good = false;
	data->weapon.enable_anim = true;
	data->weapon.center->enabled = true;
}
