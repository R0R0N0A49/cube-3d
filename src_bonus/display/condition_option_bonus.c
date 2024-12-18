/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_option_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:48:24 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:07:45 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	condition_button_music(t_opt *option, int x, int y)
{
	if ((option->index == 1 || option->but_music->click)
		&& (y >= option->but_music->y_max - 10
			|| x >= option->but_music->x_max - 10))
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
	else if (y >= option->but_music->y_max - 10
		|| x >= option->but_music->x_max - 10)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else if (option->but_music->click || option->index == 1)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
}

void	condition_button_rtn(t_opt *option, int x, int y)
{
	if (option->but_rtn->click && (y >= option->but_rtn->y_max - 5
			|| x >= option->but_rtn->x_max - 5))
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
	else if (y >= option->but_rtn->y_max - 5
		|| x >= option->but_rtn->x_max - 5)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else if (option->but_rtn->click)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
}

void	condition_button_map(t_opt *option, int x, int y)
{
	if ((option->index == 2 || option->but_map->click)
		&& (y >= option->but_map->y_max - 10
			|| x >= option->but_map->x_max - 10))
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
	else if (y >= option->but_map->y_max - 10
		|| x >= option->but_map->x_max - 10)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else if (option->but_map->click || option->index == 2)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
}

void	condition_button_fps(t_map *data, int x, int y)
{
	if ((data->menu_option->index == 3
			|| data->menu_option->but_fps->click)
		&& (y >= data->menu_option->but_fps->y_max - 10
			|| x >= data->menu_option->but_fps->x_max - 10))
		mlx_put_pixel(data->menu_option->bottom, x, y, 0xED0010FF);
	else if (y >= data->menu_option->but_fps->y_max - 10
		|| x >= data->menu_option->but_fps->x_max - 10)
		mlx_put_pixel(data->menu_option->bottom, x, y, 0x850606FF);
	else if (data->menu_option->index == 3
		|| data->menu_option->but_fps->click)
		mlx_put_pixel(data->menu_option->bottom, x, y, 0x850606FF);
	else
		mlx_put_pixel(data->menu_option->bottom, x, y, 0xED0010FF);
}

void	condition_button_night(t_opt *option, int x, int y)
{
	if ((option->index == 4 || option->but_night->click)
		&& (y >= option->but_night->y_max - 10
			|| x >= option->but_night->x_max - 10))
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
	else if (y >= option->but_night->y_max - 10
		|| x >= option->but_night->x_max - 10)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else if (option->index == 4 || option->but_night->click)
		mlx_put_pixel(option->bottom, x, y, 0x850606FF);
	else
		mlx_put_pixel(option->bottom, x, y, 0xED0010FF);
}
