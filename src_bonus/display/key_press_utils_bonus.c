/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:10 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:08:21 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	key_esc(t_map *data)
{
	if (data->pause == true && !data->menu_option->visible)
		play_game(data);
	else if (data->menu_option->visible)
		data->menu_option->but_rtn->press_enter = true;
	else
		pause_game(data);
}

void	key_left_right(t_map *data, int i)
{
	if (i == 1)
	{
		if (!data->pause)
			data->game->rotate_left = true;
		else
		{
			if (data->menu_option->index > 1)
				data->menu_option->index = data->menu_option->index - 1;
			else
				data->menu_option->index = 4;
		}
		return ;
	}
	if (!data->menu_option->visible)
		data->game->rotate_right = true;
	else
	{
		if (data->menu_option->index >= 4)
			data->menu_option->index = 1;
		else
			data->menu_option->index++;
	}
}

void	key_down(t_map *data)
{
	if (!data->menu_option->visible)
	{
		if (data->idx_menu >= 3)
			data->idx_menu = 1;
		else
			data->idx_menu++;
	}
	else
	{
		if (data->menu_option->index == 3)
			data->menu_option->index--;
		else if (data->menu_option->index > 0)
			data->menu_option->index = (data->menu_option->index + 2) % 5;
		else
			data->menu_option->index = 1;
	}
}

void	key_up(t_map *data)
{
	if (data->menu->enabled)
	{
		if (data->idx_menu > 1)
			data->idx_menu--;
		else
			data->idx_menu = 3;
	}
	else if (data->menu_option->visible)
	{
		if (data->menu_option->index == 1)
			data->menu_option->index = 4;
		else if (data->menu_option->index == 2)
			data->menu_option->index = 3;
		else if (data->menu_option->index > 0)
			data->menu_option->index = (data->menu_option->index - 2) % 5;
		else
			data->menu_option->index = 1;
	}
}

void	key_enter(t_map *data)
{
	if (data->idx_menu == 1)
		data->but_play->press_enter = true;
	if (data->idx_menu == 2)
		data->but_option->press_enter = true;
	if (data->idx_menu == 3)
		data->but_exit->press_enter = true;
	if (data->menu_option->index == 1)
		data->menu_option->but_music->press_enter = true;
	if (data->menu_option->index == 2)
		data->menu_option->but_map->press_enter = true;
	if (data->menu_option->index == 3)
		data->menu_option->but_fps->press_enter = true;
	if (data->menu_option->index == 4)
		data->menu_option->but_night->press_enter = true;
}
