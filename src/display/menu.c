/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:04 by derey             #+#    #+#             */
/*   Updated: 2024/09/20 17:10:47 by derey            ###   ########.fr       */
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
	data->but_play->but_x_min = (WINDOWSW / 2 - WINDOWSW / 6);
	data->but_play->but_y_max = 150 + 300;
	data->but_play->but_x_max = 640 + 640;
	ft_printf("%d , %d , %d , %d\n", data->but_play->but_x_min, data->but_play->but_x_max, data->but_play->but_x_max, data->but_play->but_y_max);
	while (y < 640)
	{
		x = 0;
		while (x < 150)
		{
			if (data->but_play->click == true && data->press == true)
				mlx_put_pixel(data->menu, y + 640 , x + (300), 0x850606FF);
			else
				mlx_put_pixel(data->menu, y + 640 , x + (300), 0xED0010FF);
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
	while (y < WINDOWSW / 3)
	{
		x = 0;
		while (x < 150)
		{
			mlx_put_pixel(data->menu, y + (WINDOWSW / 2 - WINDOWSW / 6) , x + (480), 0xED0010FF);
			x++;
		}
		y++;
	}
}

void	button_edit(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WINDOWSW / 3)
	{
		x = 0;
		while (x < 150)
		{
			mlx_put_pixel(data->menu, y + (WINDOWSW / 2 - WINDOWSW / 6) , x + (660), 0xED0010FF);
			x++;
		}
		y++;
	}
}

void	button_exit(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WINDOWSW / 3)
	{
		x = 0;
		while (x < 150)
		{
			mlx_put_pixel(data->menu, y + (WINDOWSW / 2 - WINDOWSW / 6) , x + (840), 0xED0010FF);
			x++;
		}
		y++;
	}
}

void	menu(t_map *data)
{
	
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WINDOWSW)
	{
		x = 0;
		while (x < WINDOWSH)
		{
			mlx_put_pixel(data->menu, y, x, 0x0000FF);
			x++;
		}
		y++;
	}
	if (data->menu->enabled == true)
		printf("enable\n");
	if (data->menu->enabled == false)
		printf("disable\n");
	button_play(data);
	button_option(data);
	button_edit(data);
	button_exit(data);
}