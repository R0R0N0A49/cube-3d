/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:04 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 18:37:44 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	button_play(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	data->but_play->but_y_min = 480;
	data->but_play->but_x_min = WINDOWSW / 3;
	data->but_play->but_y_max = 150 + 480;
	data->but_play->but_x_max = WINDOWSW / 3 + WINDOWSW / 3;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			draw_button_play(data, x, y);
			x++;
		}
		y++;
	}
	data->but_play->click = false;
}

void	button_option(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	data->but_option->but_y_min = 660;
	data->but_option->but_x_min = 640;
	data->but_option->but_y_max = 660 + 150;
	data->but_option->but_x_max = 640 + 640;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			draw_button_option(data, x, y);
			x++;
		}
		y++;
	}
	data->but_option->click = false;
}

void	button_exit(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	data->but_exit->but_y_min = 840;
	data->but_exit->but_x_min = 640;
	data->but_exit->but_y_max = 840 + 150;
	data->but_exit->but_x_max = 640 + 640;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			draw_button_exit(data, x, y);
			x++;
		}
		y++;
	}
	data->but_exit->click = false;
}

void	menu(t_map *data)
{
	button_play(data);
	button_option(data);
	button_exit(data);
}
