/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:45:36 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 18:49:52 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	button_rtn(t_opt *option)
{
	int	x;
	int	y;

	option->but_rtn->x_min = 50 + (183 * 0.5 - 25);
	option->but_rtn->y_min = 50 + (183 * 0.5 - 25);
	option->but_rtn->x_max = option->but_rtn->x_min + 50;
	option->but_rtn->y_max = option->but_rtn->y_min + 50;
	y = option->but_rtn->y_min;
	while (y < option->but_rtn->y_max)
	{
		x = option->but_rtn->x_min;
		while (x < option->but_rtn->x_max)
		{
			condition_button_rtn(option, x, y);
			x++;
		}
		y++;
	}
	option->but_rtn->click = false;
}

void	button_music(t_opt *option)
{
	int	x;
	int	y;

	option->but_music->x_min = (WINDOWSW / 3) / 3 - 40;
	option->but_music->y_min = (WINDOWSH / 3);
	option->but_music->x_max = option->but_music->x_min \
		+ WINDOWSW / 3 + 40;
	option->but_music->y_max = option->but_music->y_min \
		+ WINDOWSW / 13;
	y = option->but_music->y_min;
	while (y < option->but_music->y_max)
	{
		x = option->but_music->x_min;
		while (x < option->but_music->x_max)
		{
			condition_button_music(option, x, y);
			x++;
		}
		y++;
	}
	option->but_music->click = false;
}

void	button_map(t_opt *option)
{
	int	x;
	int	y;

	option->but_map->x_min = ((WINDOWSW / 3) / 3) * 2 + (WINDOWSW / 3);
	option->but_map->y_min = (WINDOWSH / 3);
	option->but_map->x_max = option->but_map->x_min + WINDOWSW / 3 + 40;
	option->but_map->y_max = option->but_map->y_min + WINDOWSW / 13;
	y = option->but_map->y_min;
	while (y < option->but_map->y_max)
	{
		x = option->but_map->x_min;
		while (x < option->but_map->x_max)
		{
			condition_button_map(option, x, y);
			x++;
		}
		y++;
	}
	option->but_map->click = false;
}

void	button_fps(t_map *data)
{
	int	x;
	int	y;

	data->menu_option->but_fps->x_min = ((WINDOWSW / 3) / 3) - 40;
	data->menu_option->but_fps->y_min = (WINDOWSH / 3) * 2;
	data->menu_option->but_fps->x_max = \
		data->menu_option->but_fps->x_min + WINDOWSW / 3 + 40;
	data->menu_option->but_fps->y_max = \
		data->menu_option->but_fps->y_min + WINDOWSW / 13;
	y = data->menu_option->but_fps->y_min;
	while (y < data->menu_option->but_fps->y_max)
	{
		x = data->menu_option->but_fps->x_min;
		while (x < data->menu_option->but_fps->x_max)
		{
			condition_button_fps(data, x, y);
			x++;
		}
		y++;
	}
	data->menu_option->but_fps->click = false;
}

void	button_night(t_opt *option)
{
	int	x;
	int	y;

	option->but_night->x_min = ((WINDOWSW / 3) / 3) * 2 + (WINDOWSW / 3);
	option->but_night->y_min = (WINDOWSH / 3) * 2;
	option->but_night->x_max = option->but_night->x_min \
		+ WINDOWSW / 3 + 40;
	option->but_night->y_max = option->but_night->y_min \
		+ WINDOWSW / 13;
	y = option->but_night->y_min;
	while (y < option->but_night->y_max)
	{
		x = option->but_night->x_min;
		while (x < option->but_night->x_max)
		{
			condition_button_night(option, x, y);
			x++;
		}
		y++;
	}
	option->but_night->click = false;
}
