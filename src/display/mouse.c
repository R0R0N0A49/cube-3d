/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/18 13:30:00 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse_left_r(t_map	*data)
{
	data->press = false;
	if (data->menu->enabled)
	{
		data->but_play->good = true;
		data->but_option->good = true;
		data->but_exit->good = true;
	}
	if (data->menu_option->visible)
	{
		data->menu_option->but_rtn->good = true;
		data->menu_option->but_music->good = true;
		data->menu_option->but_map->good = true;
		data->menu_option->but_fps->good = true;
		data->menu_option->but_night->good = true;
	}
}

void	mouse(mouse_key_t but, action_t action, modifier_key_t mod, void *param)
{
	t_map	*data;

	data = (t_map *)param;
	(void)mod;
	if (but == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		if (data->pause)
		{
			data->idx_menu = 0;
			data->press = true;
		}
	}
	if (but == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE)
		mouse_left_r(data);
}

void	cursor(double xpos, double ypos, void *param)
{
	t_map	*data;

	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (data->pause == false)
		mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
}

void	scroll(double i, double y, void *param)
{
	t_map	*data;

	(void)i;
	(void)y;
	data = (t_map *)param;
	if (!data->pause && data->weapon.nb_availed_weapon == 2)
	{
		data->weapon.selected[data->weapon.index_weapon]->enabled = false;
		data->weapon.index_weapon = !data->weapon.index_weapon;
		data->weapon.selected[data->weapon.index_weapon]->enabled = true;
	}
}
