/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:35:38 by derey             #+#    #+#             */
/*   Updated: 2024/11/26 13:42:19 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	loop_button(t_map *data)
{
	if (data->menu->enabled)
	{
		check_but_play(data);
		check_but_option(data);
		check_but_exit(data);
		button_play(data);
		button_option(data);
		button_exit(data);
	}
	if (data->menu_option->visible)
	{
		check_but_rtn(data);
		check_but_music(data);
		check_but_map(data);
		check_but_fps(data);
		check_but_night(data);
		button_rtn(data->menu_option);
		button_music(data->menu_option);
		button_map(data->menu_option);
		button_fps(data);
		button_night(data->menu_option);
	}
}

void	loop_moove(t_map *data)
{
	if (data->game->move_w)
		move_w(data);
	if (data->game->move_s)
		move_s(data);
	if (data->game->move_a)
		move_a(data);
	if (data->game->move_d)
		move_d(data);
	if (data->game->rotate_left)
		rotate_left(data, data->rotspeed * data->mlx->delta_time);
	if (data->game->rotate_right)
		rotate_right(data, data->rotspeed * data->mlx->delta_time);
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (data->pause != true)
	{
		raycasting(data);
		choose_weapon(data);
		if (data->menu_option->display_map)
			mini(data);
	}
	time_fps(data);
	loop_moove(data);
	loop_button(data);
	check_music(data);
	fonts_update(data);
	check_door_open(data);
	rotate_cur(data);
}
