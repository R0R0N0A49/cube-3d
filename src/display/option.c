/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/28 12:37:59 by trebours         ###   ########.fr       */
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

void	button_fov(t_opt *option)
{
	int x;
	int y;

	option->but_fov->but_x_min = ((WINDOWSW / 3) / 3) * 2 + (WINDOWSW / 3);
	option->but_fov->but_y_min = (WINDOWSH / 3);
	option->but_fov->but_x_max = option->but_fov->but_x_min + WINDOWSW / 3 + 40;
	option->but_fov->but_y_max = option->but_fov->but_y_min + WINDOWSW / 13;
	y = option->but_fov->but_y_min;
	while (y < option->but_fov->but_y_max)
	{
		x = option->but_fov->but_x_min;
		while (x < option->but_fov->but_x_max)
		{
			if ((option->index == 2 || option->but_fov->click) && (y >= option->but_fov->but_y_max - 10 || x >= option->but_fov->but_x_max - 10))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_fov->but_y_max - 10 || x >= option->but_fov->but_x_max - 10)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->but_fov->click || option->index == 2)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_fov->click = false;
}

void	button_floor(t_opt *option)
{
	int x;
	int y;

	option->but_floor->but_x_min = ((WINDOWSW / 3) / 3) - 40;
	option->but_floor->but_y_min = (WINDOWSH / 3) * 2;
	option->but_floor->but_x_max = option->but_floor->but_x_min + WINDOWSW / 3 + 40;
	option->but_floor->but_y_max = option->but_floor->but_y_min + WINDOWSW / 13;
	y = option->but_floor->but_y_min;
	while (y < option->but_floor->but_y_max)
	{
		x = option->but_floor->but_x_min;
		while (x < option->but_floor->but_x_max)
		{
			if ((option->index == 3 || option->but_floor->click) && (y >= option->but_floor->but_y_max - 10 || x >= option->but_floor->but_x_max - 10))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_floor->but_y_max - 10 || x >= option->but_floor->but_x_max - 10)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->index == 3 || option->but_floor->click)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_floor->click = false;
}

void	button_roof(t_opt *option)
{
	int x;
	int y;

	option->but_roof->but_x_min = ((WINDOWSW / 3) / 3) * 2 + (WINDOWSW / 3);
	option->but_roof->but_y_min = (WINDOWSH / 3) * 2;
	option->but_roof->but_x_max = option->but_roof->but_x_min + WINDOWSW / 3 + 40;
	option->but_roof->but_y_max = option->but_roof->but_y_min + WINDOWSW / 13;
	y = option->but_roof->but_y_min;
	while (y < option->but_roof->but_y_max)
	{
		x = option->but_roof->but_x_min;
		while (x < option->but_roof->but_x_max)
		{
			if ((option->index == 4 || option->but_roof->click) && (y >= option->but_roof->but_y_max - 10 || x >= option->but_roof->but_x_max - 10))
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			else if(y >= option->but_roof->but_y_max - 10 || x >= option->but_roof->but_x_max - 10)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else if (option->index == 4 || option->but_roof->click)
				mlx_put_pixel(option->bottom, x, y, 0x850606FF);
			else
				mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
			x++;
		}
		y++;
	}
	option->but_roof->click = false;
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
	button_fov(data->opt);
	button_floor(data->opt);
	button_roof(data->opt);
}
