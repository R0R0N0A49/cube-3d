/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:35:38 by derey             #+#    #+#             */
/*   Updated: 2024/11/26 13:42:21 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	but_rtn_utils(t_map *data)
{
	data->pause = true;
	data->idx_menu = 0;
	data->menu_option->index = 0;
	data->menu->enabled = true;
	data->menu_option->visible = false;
	data->cubd->enabled = true;
	data->img_play->enabled = true;
	data->img_option->enabled = true;
	data->img_exit->enabled = true;
	data->but_option->good = false;
	data->menu_option->bottom->enabled = false;
	data->menu_option->rtn->enabled = false;
	data->menu_option->cub->enabled = false;
	data->menu_option->but_rtn->press_enter = false;
	data->menu_option->unvalid->enabled = false;
	data->menu_option->valid->enabled = false;
	data->menu_option->music->enabled = false;
	data->menu_option->fps->enabled = false;
	data->menu_option->roof->enabled = false;
	data->menu_option->mini->enabled = false;
}

void	but_music_utils(t_map *data)
{
	data->menu_option->but_music->good = false;
	data->menu_option->but_music->press_enter = false;
	data->menu_option->play_music = !data->menu_option->play_music;
	data->menu_option->valid->instances[0].enabled = \
			data->menu_option->play_music;
	data->menu_option->unvalid->instances[0].enabled = \
			!data->menu_option->play_music;
}

void	but_map_utils(t_map *data)
{
	data->menu_option->but_map->good = false;
	data->menu_option->but_map->press_enter = false;
	data->menu_option->display_map = !data->menu_option->display_map;
	data->minima->enabled = data->menu_option->display_map;
	data->menu_option->valid->instances[1].enabled = \
			data->menu_option->display_map;
	data->menu_option->unvalid->instances[1].enabled = \
			!data->menu_option->display_map;
}

void	but_fps_utils(t_map *data)
{
	data->menu_option->but_fps->good = false;
	data->menu_option->but_fps->press_enter = false;
	data->menu_option->display_fps = !data->menu_option->display_fps;
	fonts_disabled(data);
	data->menu_option->valid->instances[2].enabled = \
			data->menu_option->display_fps;
	data->menu_option->unvalid->instances[2].enabled = \
			!data->menu_option->display_fps;
}

void	but_night_utils(t_map *data)
{
	data->menu_option->but_night->good = false;
	data->menu_option->but_night->press_enter = false;
	data->menu_option->night_mode = !data->menu_option->night_mode;
	data->fog = !data->fog;
	data->ceiling = !data->ceiling;
	data->menu_option->valid->instances[3].enabled = \
			data->menu_option->night_mode;
	data->menu_option->unvalid->instances[3].enabled = \
			!data->menu_option->night_mode;
}
