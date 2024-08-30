/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/08/30 16:25:33 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// loop
// key_hook


void	move_forward(t_map *map)
{
	double rad;

	rad = map->game->angle * M_PI / 180.0;
	map->game->triangle_y -= (int)(2 * cos(rad));
	map->game->triangle_x += (int)(2 * sin(rad));
}

void rotate_point(int cx, int cy, double angle, int *x, int *y) {
	double rad = angle * M_PI / 180.0;
	int tx = *x - cx;
	int ty = *y - cy;
	*x = cx + (int)(tx * cos(rad) - ty * sin(rad));
	*y = cy + (int)(tx * sin(rad) + ty * cos(rad));
}

void draw_line(t_game *game, int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1) {
		int e2 = 2 * err;
		mlx_put_pixel(game->frame, x1, y1, 0x80FF8080);
		if (x1 == x2 && y1 == y2)
			break ;
		if (e2 > -dy) {
			err -= dy; x1 += sx;
		}
		if (e2 < dx) {
			err += dx; y1 += sy;
		}
	}
}

void fill_triangle(t_game *game, int x1, int y1, int x2, int y2, int x3, int y3) {
	// Sort the vertices by y-coordinate
	if (y1 > y2) {
		int temp = x1; x1 = x2; x2 = temp;
		temp = y1; y1 = y2; y2 = temp;
	}
	if (y1 > y3) {
		int temp = x1; x1 = x3; x3 = temp;
		temp = y1; y1 = y3; y3 = temp;
	}
	if (y2 > y3) {
		int temp = x2; x2 = x3; x3 = temp;
		temp = y2; y2 = y3; y3 = temp;
	}

	// Fill the triangle
	for (int y = y1; y <= y3; y++) {
		int x_start, x_end;

		if (y <= y2) {
			if (y2 - y1 != 0) {
				x_start = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
			} else {
				x_start = x1;
			}
			if (y3 - y1 != 0) {
				x_end = x1 + (x3 - x1) * (y - y1) / (y3 - y1);
			} else {
				x_end = x1;
			}
		} else {
			if (y3 - y2 != 0) {
				x_start = x2 + (x3 - x2) * (y - y2) / (y3 - y2);
			} else {
				x_start = x2;
			}
			if (y3 - y1 != 0) {
				x_end = x1 + (x3 - x1) * (y - y1) / (y3 - y1);
			} else {
				x_end = x1;
			}
		}

		if (x_start > x_end) {
			int temp = x_start;
			x_start = x_end;
			x_end = temp;
		}

		for (int x = x_start; x <= x_end; x++) {
			mlx_put_pixel(game->frame, x, y, 0x60FF60FF);
		}
	}
}

bool	verif_pos(t_map *map)
{
	int x;
	int y;

	if (!map)
		return (true);
	x = map->game->triangle_x / 15;
	y = map->game->triangle_y / 15;
	if (map->map[y][x] == '1')
	{
		double rad;

		rad = map->game->angle * M_PI / 180.0;
		map->game->triangle_y += (int)(2 * cos(rad));
		map->game->triangle_x -= (int)(2 * sin(rad));
	}
	return false;
}

void	draw_arrow(t_map *map)
{
	int	point[3][2];
	int cx;
	int cy;
	int i;

	point[0][0] = map->game->triangle_x;
	point[0][1] = map->game->triangle_y;
	point[1][0] = map->game->triangle_x - 3;
	point[1][1] = map->game->triangle_y + 8;
	point[2][0] = map->game->triangle_x + 3;
	point[2][1] = map->game->triangle_y + 8;
	cx = (point[0][0] + point[1][0] + point[2][0]) / 3;
	cy = (point[0][1] + point[1][1] + point[2][1]) / 3;
	i = 0;
	while (i < 3)
	{
		rotate_point(cx, cy, map->game->angle, &point[i][0], &point[i][1]);
		i++;
	}
	if (verif_pos(map))
		return ;
	draw_line(map->game, point[0][0], point[0][1], point[1][0], point[1][1]);
	draw_line(map->game, point[1][0], point[1][1], point[2][0], point[2][1]);
	draw_line(map->game, point[2][0], point[2][1], point[0][0], point[0][1]);
	fill_triangle(map->game, point[0][0], point[0][1], point[1][0], point[1][1], point[2][0], point[2][1]);
}

void	loop(void *param)
{
	t_map	*map;

	map = (t_map *)param;

	for (int y = 0; y < (14 * 15); y++) {
		for (int x = 0; x < (33 * 15); x++) {
			mlx_put_pixel(map->game->frame, x, y, 0x00000000); // Black color
		}
	}
	if (map->game->moving_forward) {
		move_forward(param);
	}
	if (map->game->rotating_left) {
		map->game->angle -= 5;
	}
	if (map->game->rotating_right) {
		map->game->angle += 5;
	}
	draw_arrow(map);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.action == MLX_PRESS) {
		if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(map->mlx);
		if (keydata.key == MLX_KEY_UP) {
			map->game->moving_forward = true;
		} else if (keydata.key == MLX_KEY_DOWN) {
			map->game->triangle_y += 1;
		} else if (keydata.key == MLX_KEY_LEFT) {
			map->game->triangle_x -= 1;
		} else if (keydata.key == MLX_KEY_RIGHT) {
			map->game->triangle_x += 1;
		} else if (keydata.key == MLX_KEY_Q) {
			map->game->rotating_left = true;
		} else if (keydata.key == MLX_KEY_E) {
			map->game->rotating_right = true;
		}
	} else if (keydata.action == MLX_RELEASE) {
		if (keydata.key == MLX_KEY_UP) {
			map->game->moving_forward = false;
		} else if (keydata.key == MLX_KEY_Q) {
			map->game->rotating_left = false;
		} else if (keydata.key == MLX_KEY_E) {
			map->game->rotating_right = false;
		}
	}
}