/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:37:15 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 18:37:49 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_button_play(t_map *data, int x, int y)
{
	if ((x >= 140 || y >= 630) && ((data->but_play->click == true)
			|| data->idx_menu == 1))
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_play->y_min, 0xED0010FF);
	else if ((data->but_play->click == true) || data->idx_menu == 1)
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_play->y_min, 0x850606FF);
	else if (x >= 140 || y >= 630)
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_play->y_min, 0x850606FF);
	else
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_play->y_min, 0xED0010FF);
}

void	draw_button_option(t_map *data, int x, int y)
{
	if ((x >= 140 || y >= 630) && ((data->but_option->click == true)
			|| data->idx_menu == 2))
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_option->y_min, 0xED0010FF);
	else if ((data->but_option->click == true) || data->idx_menu == 2)
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_option->y_min, 0x850606FF);
	else if (x >= 140 || y >= 630)
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_option->y_min, 0x850606FF);
	else
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_option->y_min, 0xED0010FF);
}

void	draw_button_exit(t_map *data, int x, int y)
{
	if ((x >= 140 || y >= 630) && ((data->but_exit->click == true)
			|| data->idx_menu == 3))
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_exit->y_min, 0xED0010FF);
	else if ((data->but_exit->click == true) || data->idx_menu == 3)
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_exit->y_min, 0x850606FF);
	else if (x >= 140 || y >= 630)
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_exit->y_min, 0x850606FF);
	else
		mlx_put_pixel(data->menu, y + 640, \
			x + data->but_exit->y_min, 0xED0010FF);
}
