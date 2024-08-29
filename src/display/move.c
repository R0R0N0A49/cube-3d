/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/08/29 16:13:56 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    bresenham(int x1, int y1, int x2, int y2, mlx_image_t *img, uint32_t color)
{
	int dx=abs(x2 - x1);
	int dy=abs(y2 - y1);
	int sx;
	int sy;
	int err = dx -dy;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		mlx_put_pixel(img, x1, y1, color);  // Rouge
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}

static void	player(t_map *data, float angle)
{
	int px1 = 0, py1 = -5;
	int px2 = 5, py2 = 5;
	int px3 = -(5), py3 = 5;

	int p1x_rot = (int)(px1 * cos(angle) - py1 * sin(angle)) + 3;
	int p1y_rot = (int)(px1 * sin(angle) + py1 * cos(angle)) + 4;

	int p2x_rot = (int)(px2 * cos(angle) - py2 * sin(angle)) - 1;
	int p2y_rot = (int)(px2 * sin(angle) + py2 * cos(angle)) + 3;

	int p3x_rot = (int)(px3 * cos(angle) - py3 * sin(angle)) + 15;
	int p3y_rot = (int)(px3 * sin(angle) + py3 * cos(angle)) + 8;

	bresenham(p1x_rot, p1y_rot, p2x_rot, p2y_rot, data->mini_map->player, 0x60FF06FF);
	bresenham(p1x_rot, p1y_rot, p3x_rot, p3y_rot, data->mini_map->player, 0x60FF06FF);
	bresenham(p2x_rot, p2y_rot, p3x_rot, p3y_rot, data->mini_map->player, 0xFF0000FF);
//	ft_printf("x1 = %d, y1 = %d\nx2 = %d, y2 = %d\nx3 = %d, y3 = %d\n\n", p1x_rot, p1y_rot, p2x_rot, p2y_rot, p3x_rot, p3y_rot);
//	mlx_put_pixel(data->mini_map->player, p1x_rot, p1y_rot, 0x60FF06FF);
//	mlx_put_pixel(data->mini_map->player, p2x_rot, p2y_rot, 0xFF0000FF);
//	mlx_put_pixel(data->mini_map->player, p3x_rot, p3y_rot, 0xFF0000FF);
	mlx_image_to_window(data->mlx, data->mini_map->player, 300, 300);
}

void	high(t_map *data)
{
//	mlx_delete_image(data->mlx, data->mini_map->player);
	player(data, 0.5f);
//	data->mini_map->player = mlx_texture_to_image(data->mlx, data->mini_map->player_t);
	data->mini_map->pos_y-=2;
	mlx_image_to_window(data->mlx, data->mini_map->player, data->mini_map->pos_x, data->mini_map->pos_y);
}

void	botom(t_map *data)
{
	mlx_delete_image(data->mlx, data->mini_map->player);
	data->mini_map->player = mlx_texture_to_image(data->mlx, data->mini_map->player_t);
	data->mini_map->pos_y+=2;
	mlx_image_to_window(data->mlx, data->mini_map->player, data->mini_map->pos_x, data->mini_map->pos_y);
}

void	right(t_map *data)
{
	mlx_delete_image(data->mlx, data->mini_map->player);
	data->mini_map->player = mlx_texture_to_image(data->mlx, data->mini_map->player_t);
	data->mini_map->pos_x+=2;
	mlx_image_to_window(data->mlx, data->mini_map->player, data->mini_map->pos_x, data->mini_map->pos_y);
}

void	left(t_map *data)
{
	mlx_delete_image(data->mlx, data->mini_map->player);
	data->mini_map->player = mlx_texture_to_image(data->mlx, data->mini_map->player_t);
	data->mini_map->pos_x-=2;
	mlx_image_to_window(data->mlx, data->mini_map->player, data->mini_map->pos_x, data->mini_map->pos_y);
}