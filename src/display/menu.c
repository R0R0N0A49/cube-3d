/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:04 by derey             #+#    #+#             */
/*   Updated: 2024/09/29 19:03:48 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	button_play(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->but_play->but_y_min = 300;
	data->but_play->but_x_min = data->mlx->width / 3;
	data->but_play->but_y_max = 150 + 300;
	data->but_play->but_x_max = data->mlx->width / 3 + data->mlx->width / 3;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			if ((x >= 140 || y >= 630) && ((data->but_play->click == true) || data->idx_menu == 1))
				mlx_put_pixel(data->menu, y + 640, x + data->but_play->but_y_min , 0xED0010FF);
			else if ((data->but_play->click == true) || data->idx_menu == 1)
				mlx_put_pixel(data->menu, y + 640, x + data->but_play->but_y_min , 0x850606FF);
			else if (x >= 140 || y >= 630)
				mlx_put_pixel(data->menu, y + 640, x + data->but_play->but_y_min , 0x850606FF);
			else
				mlx_put_pixel(data->menu, y + 640, x + data->but_play->but_y_min , 0xED0010FF);
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
	x = 0;
	data->but_option->but_y_min = 480;
	data->but_option->but_x_min = 640;
	data->but_option->but_y_max = 480 + 150;
	data->but_option->but_x_max = 640 + 640;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			if ((x >= 140 || y >= 630) && ((data->but_option->click == true) || data->idx_menu == 2))
				mlx_put_pixel(data->menu, y + 640, x + data->but_option->but_y_min, 0xED0010FF);
			else if ((data->but_option->click == true) || data->idx_menu == 2)
				mlx_put_pixel(data->menu, y + 640, x + data->but_option->but_y_min, 0x850606FF);
			else if (x >= 140 || y >= 630)
				mlx_put_pixel(data->menu, y + 640, x + data->but_option->but_y_min, 0x850606FF);
			else
				mlx_put_pixel(data->menu, y + 640, x + data->but_option->but_y_min, 0xED0010FF);
			x++;
		}
		y++;
	}
	data->but_option->click = false;
}

void	button_edit(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->but_edit->but_y_min = 660;
	data->but_edit->but_x_min = 640;
	data->but_edit->but_y_max = 660 + 150;
	data->but_edit->but_x_max = 640 + 640;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			if ((x >= 140 || y >= 630) && (((data->but_edit->click == true) || data->idx_menu == 3)))
				mlx_put_pixel(data->menu, y + 640, x + data->but_edit->but_y_min, 0xED0010FF);
			else if ((data->but_edit->click == true) || data->idx_menu == 3)
				mlx_put_pixel(data->menu, y + 640, x + data->but_edit->but_y_min, 0x850606FF);
			else if (x >= 140 || y >= 630)
				mlx_put_pixel(data->menu, y + 640, x + data->but_edit->but_y_min, 0x850606FF);
			else
				mlx_put_pixel(data->menu, y + 640, x + data->but_edit->but_y_min, 0xED0010FF);
			x++;
		}
		y++;
	}
	data->but_edit->click = false;
}

void	button_exit(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->but_exit->but_y_min = 840;
	data->but_exit->but_x_min = 640;
	data->but_exit->but_y_max = 840 + 150;
	data->but_exit->but_x_max = 640 + 640;
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			if ((x >= 140 || y >= 630) && ((data->but_exit->click == true) || data->idx_menu == 4))
				mlx_put_pixel(data->menu, y + 640, x + data->but_exit->but_y_min, 0xED0010FF);
			else if ((data->but_exit->click == true) || data->idx_menu == 4)
				mlx_put_pixel(data->menu, y + 640, x + data->but_exit->but_y_min, 0x850606FF);
			else if (x >= 140 || y >= 630)
				mlx_put_pixel(data->menu, y + 640, x + data->but_exit->but_y_min, 0x850606FF);
			else
				mlx_put_pixel(data->menu, y + 640, x + data->but_exit->but_y_min, 0xED0010FF);
			x++;
		}
		y++;
	}
	data->but_exit->click = false;
}

void	menu(t_map *data)
{
//	int	y;
//	int	x;
//
//	y = 0;
//	x = 0;
	/*while (y < WINDOWSW)
	{
		x = 0;
		while (x < WINDOWSH)
		{
			mlx_put_pixel(data->menu, y, x, 0x0000FF);
			x++;
		}
		y++;
	}*/
	if (data->menu->enabled == true)
		printf("enable\n");
	if (data->menu->enabled == false)
		printf("disable\n");
	button_play(data);
	button_option(data);
	button_edit(data);
	button_exit(data);
}
