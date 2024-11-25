/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_button_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:46:05 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:07:40 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_but_play(t_map *data)
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;

	xmin = get_pc(data->mlx->width, data->but_play->x_min, WINDOWSW);
	xmax = get_pc(data->mlx->width, data->but_play->x_max, WINDOWSW);
	ymin = get_pc(data->mlx->height, data->but_play->y_min, WINDOWSH);
	ymax = get_pc(data->mlx->height, data->but_play->y_max, WINDOWSH);
	if (data->game->cursor_x > xmin && data->game->cursor_x < xmax
		&& data->game->cursor_y > ymin && data->game->cursor_y < ymax)
	{
		data->idx_menu = 0;
		data->but_play->click = true;
	}
	if (data->game->cursor_x < xmin || data->game->cursor_x > xmax
		|| data->game->cursor_y < ymin || data->game->cursor_y > ymax)
		data->but_play->good = false;
	if ((data->game->cursor_x > xmin && data->game->cursor_x < xmax
			&& data->game->cursor_y > ymin && data->game->cursor_y < ymax
			&& data->but_play->good == true)
		|| data->but_play->press_enter == true)
		play_game(data);
}

static void	but_option_utils(t_map *data)
{
	data->pause = true;
	data->idx_menu = 0;
	data->menu_option->index = 0;
	data->but_option->press_enter = false;
	data->but_option->good = false;
	data->menu->enabled = false;
	data->menu_option->visible = true;
	data->cubd->enabled = false;
	data->img_play->enabled = false;
	data->img_option->enabled = false;
	data->img_exit->enabled = false;
	data->menu_option->bottom->enabled = true;
	data->menu_option->rtn->enabled = true;
	data->menu_option->cub->enabled = true;
	data->menu_option->music->enabled = true;
	data->menu_option->fps->enabled = true;
	data->menu_option->roof->enabled = true;
	data->menu_option->mini->enabled = true;
	data->menu_option->unvalid->enabled = true;
	data->menu_option->valid->enabled = true;
}

void	check_but_option(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, data->but_option->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, data->but_option->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, data->but_option->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, data->but_option->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->but_option->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->but_option->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y >= y_min && data->game->cursor_y < y_max
			&& data->but_option->good == true)
		|| data->but_option->press_enter == true)
		but_option_utils(data);
}

void	check_but_exit(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, data->but_exit->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, data->but_exit->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, data->but_exit->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, data->but_exit->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->but_exit->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->but_exit->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y > y_min && data->game->cursor_y < y_max
			&& data->but_exit->good == true)
		|| data->but_exit->press_enter == true)
		exit_cub3d(data);
}
