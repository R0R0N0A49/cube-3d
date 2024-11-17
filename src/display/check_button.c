/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:46:05 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 18:18:58 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_but_play(t_map *data)
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;

	xmin = get_pc(data->mlx->width, data->but_play->but_x_min, WINDOWSW);
	xmax = get_pc(data->mlx->width, data->but_play->but_x_max, WINDOWSW);
	ymin = get_pc(data->mlx->height, data->but_play->but_y_min, WINDOWSH);
	ymax = get_pc(data->mlx->height, data->but_play->but_y_max, WINDOWSH);
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

void	check_but_option(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, data->but_option->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, data->but_option->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, data->but_option->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, data->but_option->but_y_max, WINDOWSH);
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
}

void	check_but_exit(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, data->but_exit->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, data->but_exit->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, data->but_exit->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, data->but_exit->but_y_max, WINDOWSH);
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

void	check_but_rtn(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, \
		data->menu_option->but_rtn->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, \
		data->menu_option->but_rtn->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, \
		data->menu_option->but_rtn->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, \
		data->menu_option->but_rtn->but_y_max, WINDOWSH);
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
			&& data->menu_option->but_rtn->good)
		|| data->menu_option->but_rtn->press_enter)
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
}

void	check_but_music(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, \
		data->menu_option->but_music->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, \
		data->menu_option->but_music->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, \
		data->menu_option->but_music->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, \
		data->menu_option->but_music->but_y_max, WINDOWSH);
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
			&& data->menu_option->but_music->good)
		|| data->menu_option->but_music->press_enter)
	{
		data->menu_option->but_music->good = false;
		data->menu_option->but_music->press_enter = false;
		data->menu_option->play_music = !data->menu_option->play_music;
		data->menu_option->valid->instances[0].enabled = \
			data->menu_option->play_music;
		data->menu_option->unvalid->instances[0].enabled = \
			!data->menu_option->play_music;
	}
}

void	check_but_map(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, \
		data->menu_option->but_map->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, \
		data->menu_option->but_map->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, \
		data->menu_option->but_map->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, \
		data->menu_option->but_map->but_y_max, WINDOWSH);
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
			&& data->menu_option->but_map->good)
		|| data->menu_option->but_map->press_enter)
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
}

void	check_but_fps(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, \
		data->menu_option->but_fps->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, \
		data->menu_option->but_fps->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, \
		data->menu_option->but_fps->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, \
		data->menu_option->but_fps->but_y_max, WINDOWSH);
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
			&& data->menu_option->but_fps->good)
		|| data->menu_option->but_fps->press_enter)
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
}

void	check_but_night(t_map *data)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = get_pc(data->mlx->width, \
		data->menu_option->but_night->but_x_min, WINDOWSW);
	x_max = get_pc(data->mlx->width, \
		data->menu_option->but_night->but_x_max, WINDOWSW);
	y_min = get_pc(data->mlx->height, \
		data->menu_option->but_night->but_y_min, WINDOWSH);
	y_max = get_pc(data->mlx->height, \
		data->menu_option->but_night->but_y_max, WINDOWSH);
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
			&& data->menu_option->but_night->good)
		|| data->menu_option->but_night->press_enter)
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
}
