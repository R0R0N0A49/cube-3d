/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/30 12:33:37 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	button_rtn(t_opt *option)
{
	int x;
	int y;

	option->but_rtn->but_x_min = 50 + (183 / 2 - 25);
//	option->but_rtn->but_y_min = 50 + 183;
	option->but_rtn->but_y_min = 50 + (183 / 2 - 25);
	option->but_rtn->but_x_max = option->but_rtn->but_x_min + 50;
	option->but_rtn->but_y_max = option->but_rtn->but_y_min + 50;
	y = option->but_rtn->but_y_min;
	while (y < option->but_rtn->but_y_max)
	{
		x = option->but_rtn->but_x_min;
		while (x < option->but_rtn->but_x_max)
		{
			if (option->but_rtn->click && (y >= option->but_rtn->but_y_max - 5 || x >= option->but_rtn->but_x_max - 5))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_rtn->but_y_max - 5 || x >= option->but_rtn->but_x_max - 5)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->but_rtn->click)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_rtn->click = false;
}

void	button_music(t_opt *option)
{
	int x;
	int y;

	option->but_music->but_x_min = (WINDOWSW / 3) / 3 - 40;
	option->but_music->but_y_min = (WINDOWSH / 3);
	option->but_music->but_x_max = option->but_music->but_x_min + WINDOWSW / 3 + 40;
	option->but_music->but_y_max = option->but_music->but_y_min + WINDOWSW / 13;
	y = option->but_music->but_y_min;
	while (y < option->but_music->but_y_max)
	{
		x = option->but_music->but_x_min;
		while (x < option->but_music->but_x_max)
		{
			if ((option->index == 1 || option->but_music->click) && (y >= option->but_music->but_y_max - 10 || x >= option->but_music->but_x_max - 10))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_music->but_y_max - 10 || x >= option->but_music->but_x_max - 10)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->but_music->click || option->index == 1)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_music->click = false;
}

void	button_map(t_opt *option)
{
	int x;
	int y;

	option->but_map->but_x_min = ((WINDOWSW / 3) / 3) * 2 + (WINDOWSW / 3);
	option->but_map->but_y_min = (WINDOWSH / 3);
	option->but_map->but_x_max = option->but_map->but_x_min + WINDOWSW / 3 + 40;
	option->but_map->but_y_max = option->but_map->but_y_min + WINDOWSW / 13;
	y = option->but_map->but_y_min;
	while (y < option->but_map->but_y_max)
	{
		x = option->but_map->but_x_min;
		while (x < option->but_map->but_x_max)
		{
			if ((option->index == 2 || option->but_map->click) && (y >= option->but_map->but_y_max - 10 || x >= option->but_map->but_x_max - 10))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_map->but_y_max - 10 || x >= option->but_map->but_x_max - 10)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->but_map->click || option->index == 2)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_map->click = false;
}

void	button_fps(t_map *data)
{
	int x;
	int y;

	data->opt->but_fps->but_x_min = ((WINDOWSW / 3) / 3) - 40;
	data->opt->but_fps->but_y_min = (WINDOWSH / 3) * 2;
	data->opt->but_fps->but_x_max = data->opt->but_fps->but_x_min + WINDOWSW / 3 + 40;
	data->opt->but_fps->but_y_max = data->opt->but_fps->but_y_min + WINDOWSW / 13;
	y = data->opt->but_fps->but_y_min;
	while (y < data->opt->but_fps->but_y_max)
	{
		x = data->opt->but_fps->but_x_min;
		while (x < data->opt->but_fps->but_x_max)
		{
			if ((data->opt->index == 3 || data->opt->but_fps->click) && (y >= data->opt->but_fps->but_y_max - 10 || x >= data->opt->but_fps->but_x_max - 10))
				mlx_put_pixel(data->opt->bottom, x, y, 0xED0010FF);
			else if(y >= data->opt->but_fps->but_y_max - 10 || x >= data->opt->but_fps->but_x_max - 10)
				mlx_put_pixel(data->opt->bottom, x, y, 0x850606FF);
			else if (data->opt->index == 3 || data->opt->but_fps->click)
				mlx_put_pixel(data->opt->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(data->opt->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	data->opt->but_fps->click = false;
}

void	button_night(t_opt *option)
{
	int x;
	int y;

	option->but_night->but_x_min = ((WINDOWSW / 3) / 3) * 2 + (WINDOWSW / 3);
	option->but_night->but_y_min = (WINDOWSH / 3) * 2;
	option->but_night->but_x_max = option->but_night->but_x_min + WINDOWSW / 3 + 40;
	option->but_night->but_y_max = option->but_night->but_y_min + WINDOWSW / 13;
	y = option->but_night->but_y_min;
	while (y < option->but_night->but_y_max)
	{
		x = option->but_night->but_x_min;
		while (x < option->but_night->but_x_max)
		{
			if ((option->index == 4 || option->but_night->click) && (y >= option->but_night->but_y_max - 10 || x >= option->but_night->but_x_max - 10))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_night->but_y_max - 10 || x >= option->but_night->but_x_max - 10)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->index == 4 || option->but_night->click)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_night->click = false;
}

void	option(t_map *data)
{
//	int	y;
//	int	x;
//
//	y = 0;
//	x = 0;
//	while (y < WINDOWSW)
//	{
//		x = 0;
//		while (x < WINDOWSH)
//		{
//			mlx_put_pixel(data->opt->bottom, y, x, 0x000000ff);
//			x++;
//		}
//		y++;
//	}
	button_rtn(data->opt);
	button_music(data->opt);
	button_map(data->opt);
	button_fps(data);
	button_night(data->opt);
}
