/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_button_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/28 17:02:36 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_but_play(t_map *data)
{
	if (data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max)
	{
		printf("PLAY\n");
		data->idx_menu = 0;
		data->but_play->click = true;
	}
	if (data->game->cursor_x < data->but_play->but_x_min || data->game->cursor_x > data->but_play->but_x_max || data->game->cursor_y < data->but_play->but_y_min || data->game->cursor_y > data->but_play->but_y_max)
		data->but_play->good = false;
	if ((data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max && data->but_play->good == true ) || data->but_play->press_enter == true)
	{
		system("paplay ./Music/button_son.wav &");
		play(data);
	}
}


void	check_but_option(t_map *data)
{
	if (data->game->cursor_x > data->but_option->but_x_min && data->game->cursor_x < data->but_option->but_x_max && data->game->cursor_y > data->but_option->but_y_min && data->game->cursor_y < data->but_option->but_y_max)
	{
		printf("OPTION\n");
		data->idx_menu = 0;
		data->but_option->click = true;
	}	
	if (data->game->cursor_x < data->but_option->but_x_min || data->game->cursor_x > data->but_option->but_x_max || data->game->cursor_y < data->but_option->but_y_min || data->game->cursor_y > data->but_option->but_y_max)
		data->but_option->good = false;
	if ((data->game->cursor_x > data->but_option->but_x_min && data->game->cursor_x < data->but_option->but_x_max && data->game->cursor_y >= data->but_option->but_y_min && data->game->cursor_y < data->but_option->but_y_max && data->but_option->good == true) || data->but_option->press_enter == true )
	{
		system("paplay ./Music/button_son.wav &");
		data->pause = true;
		data->idx_menu = 0;
		data->but_option->press_enter = false;
		data->but_option->good = false;
		data->menu->enabled = false;
		data->opt->option = true;
		data->cubd->enabled = false;
		data->img_play->enabled = false;
		data->img_option->enabled = false;
		data->img_edit->enabled = false;
		data->img_exit->enabled = false;
		data->opt->bottom->enabled = true;
		data->opt->rtn->enabled = true;
		data->opt->cub->enabled = true;
		data->opt->music->enabled = true;
		verif_option(data->opt);
	}
}

void	check_but_edit(t_map *data)
{
	if (data->game->cursor_x > data->but_edit->but_x_min && data->game->cursor_x < data->but_edit->but_x_max && data->game->cursor_y > data->but_edit->but_y_min && data->game->cursor_y < data->but_edit->but_y_max)
	{
		printf("EDIT\n");
		data->idx_menu = 0;
		data->but_edit->click = true;
	}
	if (data->game->cursor_x < data->but_edit->but_x_min || data->game->cursor_x > data->but_edit->but_x_max || data->game->cursor_y < data->but_edit->but_y_min || data->game->cursor_y > data->but_edit->but_y_max)
		data->but_edit->good = false;
	if ((data->game->cursor_x > data->but_edit->but_x_min && data->game->cursor_x < data->but_edit->but_x_max && data->game->cursor_y > data->but_edit->but_y_min && data->game->cursor_y < data->but_edit->but_y_max && data->but_edit->good == true) || data->but_edit->press_enter == true)
	{
		data->editor->edit = true;
		data->pause = true;
		data->idx_menu = 0;
		data->but_edit->good = false;
		data->but_edit->press_enter = false;
		data->edit->enabled = true;
		data->opt->rtn->enabled = true;
		data->editeur = true;
		data->menu->enabled = false;
		data->img_play->enabled = false;
		data->img_option->enabled = false;
		data->img_edit->enabled = false;
		data->img_exit->enabled = false;
		
	}
	
}

void	check_but_exit(t_map *data)
{
	if (data->game->cursor_x > data->but_exit->but_x_min && data->game->cursor_x < data->but_exit->but_x_max && data->game->cursor_y > data->but_exit->but_y_min && data->game->cursor_y < data->but_exit->but_y_max)
	{
		printf("QUIT\n");
		data->idx_menu = 0;
		data->but_exit->click = true;
	}
	if (data->game->cursor_x < data->but_exit->but_x_min || data->game->cursor_x > data->but_exit->but_x_max || data->game->cursor_y < data->but_exit->but_y_min || data->game->cursor_y > data->but_exit->but_y_max)
		data->but_exit->good = false;
	if ((data->game->cursor_x > data->but_exit->but_x_min && data->game->cursor_x < data->but_exit->but_x_max && data->game->cursor_y > data->but_exit->but_y_min && data->game->cursor_y < data->but_exit->but_y_max && data->but_exit->good == true) || data->but_exit->press_enter == true)
	{
		system("paplay ./Music/button_son.wav &");
		exit_cub3d(data);
	}
	
}