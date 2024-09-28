/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/28 10:19:54 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_but_rtn(t_opt *option, t_map *data)
{
	if (data->game->cursor_x > option->but_rtn->but_x_min && data->game->cursor_x < option->but_rtn->but_x_max && data->game->cursor_y > option->but_rtn->but_y_min && data->game->cursor_y < option->but_rtn->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_rtn->click = true;
	}
	if (data->game->cursor_x < option->but_rtn->but_x_min || data->game->cursor_x > option->but_rtn->but_x_max || data->game->cursor_y < option->but_rtn->but_y_min || data->game->cursor_y > option->but_rtn->but_y_max)
		data->opt->but_rtn->good = false;
	if ((data->game->cursor_x > option->but_rtn->but_x_min && data->game->cursor_x < option->but_rtn->but_x_max && data->game->cursor_y > option->but_rtn->but_y_min && data->game->cursor_y < option->but_rtn->but_y_max && data->opt->but_rtn->good) || data->opt->but_rtn->press_enter)
	{
		data->pause = true;
		data->idx_menu = 0;
		data->menu->enabled = true;
		data->opt->option = false;
		data->cubd->enabled = true;
		data->img_play->enabled = true;
		data->img_option->enabled = true;
		data->img_edit->enabled = true;
		data->img_exit->enabled = true;
		data->opt->bottom->enabled = false;
		data->opt->rtn->enabled = false;
		data->opt->cub->enabled = false;
		data->opt->but_rtn->press_enter = false;
		data->opt->m_unvalid->enabled = false;
		data->opt->f_unvalid->enabled = false;
		data->opt->fl_unvalid->enabled = false;
		data->opt->r_unvalid->enabled = false;
		data->opt->m_valid->enabled = false;
		data->opt->f_valid->enabled = false;
		data->opt->fl_valid->enabled = false;
		data->opt->r_valid->enabled = false;
		data->opt->music->enabled = false;
	}
}

void	check_but_music(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_music->but_x_min && data->game->cursor_x < data->opt->but_music->but_x_max && data->game->cursor_y > data->opt->but_music->but_y_min && data->game->cursor_y < data->opt->but_music->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_music->click = true;
	}
	if (data->game->cursor_x < data->opt->but_music->but_x_min || data->game->cursor_x > data->opt->but_music->but_x_max || data->game->cursor_y < data->opt->but_music->but_y_min || data->game->cursor_y > data->opt->but_music->but_y_max)
		data->opt->but_music->good = false;
	if (data->game->cursor_x > data->opt->but_music->but_x_min && data->game->cursor_x < data->opt->but_music->but_x_max && data->game->cursor_y > data->opt->but_music->but_y_min && data->game->cursor_y < data->opt->but_music->but_y_max && data->opt->but_music->good)
	{
		system("paplay ./Music/button_son.wav &");
		data->opt->but_music->good = false;
		data->opt->play_music = !data->opt->play_music;
		verif_option(data->opt);
	}
}

void	check_but_fov(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_fov->but_x_min && data->game->cursor_x < data->opt->but_fov->but_x_max && data->game->cursor_y > data->opt->but_fov->but_y_min && data->game->cursor_y < data->opt->but_fov->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_fov->click = true;
	}
	if (data->game->cursor_x < data->opt->but_fov->but_x_min || data->game->cursor_x > data->opt->but_fov->but_x_max || data->game->cursor_y < data->opt->but_fov->but_y_min || data->game->cursor_y > data->opt->but_fov->but_y_max)
		data->opt->but_fov->good = false;
	if (data->game->cursor_x > data->opt->but_fov->but_x_min && data->game->cursor_x < data->opt->but_fov->but_x_max && data->game->cursor_y > data->opt->but_fov->but_y_min && data->game->cursor_y < data->opt->but_fov->but_y_max && data->opt->but_fov->good)
	{
		system("paplay ./Music/button_son.wav &");
		data->opt->but_fov->good = false;
		data->opt->show_fov = !data->opt->show_fov;
		verif_option(data->opt);
	}
}

void	check_but_floor(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_floor->but_x_min && data->game->cursor_x < data->opt->but_floor->but_x_max && data->game->cursor_y > data->opt->but_floor->but_y_min && data->game->cursor_y < data->opt->but_floor->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_floor->click = true;
	}
	if (data->game->cursor_x < data->opt->but_floor->but_x_min || data->game->cursor_x > data->opt->but_floor->but_x_max || data->game->cursor_y < data->opt->but_floor->but_y_min || data->game->cursor_y > data->opt->but_floor->but_y_max)
		data->opt->but_floor->good = false;
	if (data->game->cursor_x > data->opt->but_floor->but_x_min && data->game->cursor_x < data->opt->but_floor->but_x_max && data->game->cursor_y > data->opt->but_floor->but_y_min && data->game->cursor_y < data->opt->but_floor->but_y_max && data->opt->but_floor->good)
	{
		system("paplay ./Music/button_son.wav &");
		data->opt->but_floor->good = false;
		data->opt->txt_floor = !data->opt->txt_floor;
		verif_option(data->opt);
	}
}

void	check_but_roof(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_roof->but_x_min && data->game->cursor_x < data->opt->but_roof->but_x_max && data->game->cursor_y > data->opt->but_roof->but_y_min - 43 && data->game->cursor_y < data->opt->but_roof->but_y_max - 49)
	{
		data->idx_menu = 0;
		data->opt->but_roof->click = true;
	}
	if (data->game->cursor_x < data->opt->but_roof->but_x_min || data->game->cursor_x > data->opt->but_roof->but_x_max || data->game->cursor_y < data->opt->but_roof->but_y_min || data->game->cursor_y > data->opt->but_roof->but_y_max)
		data->opt->but_roof->good = false;
	if (data->game->cursor_x > data->opt->but_roof->but_x_min && data->game->cursor_x < data->opt->but_roof->but_x_max && data->game->cursor_y > data->opt->but_roof->but_y_min && data->game->cursor_y < data->opt->but_roof->but_y_max && data->opt->but_roof->good)
	{
		system("paplay ./Music/button_son.wav &");
		data->opt->but_roof->good = false;
		data->opt->txt_roof = !data->opt->txt_roof;
		data->plafond = !data->plafond;
		verif_option(data->opt);
	}
}


void	verif_option(t_opt *opt)
{
	if (opt->play_music)
	{
		opt->m_valid->enabled = true;
		opt->m_unvalid->enabled = false;
	}
	else if (!opt->play_music)
	{
		opt->m_valid->enabled = false;
		opt->m_unvalid->enabled = true;
	}
	if (opt->show_fov)
	{
		opt->f_valid->enabled = true;
		opt->f_unvalid->enabled = false;
	}
	else
	{
		opt->f_valid->enabled = false;
		opt->f_unvalid->enabled = true;
	}
	if (opt->txt_floor)
	{
		opt->fl_valid->enabled = true;
		opt->fl_unvalid->enabled = false;
	}
	else
	{
		opt->fl_unvalid->enabled = true;
		opt->fl_valid->enabled = false;

	}
	if (opt->txt_roof)
	{
		opt->r_valid->enabled = true;
		opt->r_unvalid->enabled = false;
	}
	else
	{
		opt->r_unvalid->enabled = true;
		opt->r_valid->enabled = false;
	}
}