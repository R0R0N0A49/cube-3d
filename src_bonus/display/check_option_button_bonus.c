/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option_button_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:35:38 by derey             #+#    #+#             */
/*   Updated: 2024/11/26 13:42:20 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_but_rtn(t_map *data)
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_button	*but;

	but = data->menu_option->but_rtn;
	x_min = get_pc(data->mlx->width, but->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, but->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, but->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, but->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->menu_option->but_rtn->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->menu_option->but_rtn->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y > y_min && data->game->cursor_y < y_max
			&& but->good) || but->press_enter)
		but_rtn_utils(data);
}

void	check_but_music(t_map *data)
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_button	*but;

	but = data->menu_option->but_music;
	x_min = get_pc(data->mlx->width, but->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, but->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, but->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, but->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->menu_option->index = 0;
		data->menu_option->but_music->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->menu_option->but_music->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y > y_min && data->game->cursor_y < y_max
			&& but->good) || but->press_enter)
		but_music_utils(data);
}

void	check_but_map(t_map *data)
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_button	*but;

	but = data->menu_option->but_map;
	x_min = get_pc(data->mlx->width, but->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, but->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, but->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, but->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->menu_option->index = 0;
		data->menu_option->but_map->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->menu_option->but_map->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y > y_min && data->game->cursor_y < y_max
			&& but->good) || but->press_enter)
		but_map_utils(data);
}

void	check_but_fps(t_map *data)
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_button	*but;

	but = data->menu_option->but_fps;
	x_min = get_pc(data->mlx->width, but->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, but->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, but->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, but->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->menu_option->index = 0;
		data->menu_option->but_fps->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->menu_option->but_fps->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y > y_min && data->game->cursor_y < y_max
			&& but->good) || but->press_enter)
		but_fps_utils(data);
}

void	check_but_night(t_map *data)
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_button	*but;

	but = data->menu_option->but_night;
	x_min = get_pc(data->mlx->width, but->x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, but->x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, but->y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, but->y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max
		&& data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->menu_option->index = 0;
		data->menu_option->but_night->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max
		|| data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->menu_option->but_night->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max
			&& data->game->cursor_y > y_min && data->game->cursor_y < y_max
			&& but->good) || but->press_enter)
		but_night_utils(data);
}
