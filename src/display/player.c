/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/05 16:54:16 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

# define COLOR_PLAYER 0xFF5000FF

void rotate_point(int cx, int cy, double angle, int *x, int *y) {
	double rad = angle * 3.14159265358979323846 / 180.0;
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
		mlx_put_pixel(game->frame, x1, y1, COLOR_PLAYER);
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
			mlx_put_pixel(game->frame, x, y, COLOR_PLAYER);
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

		rad = map->game->angle * 3.14159265358979323846 / 180.0;
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
	point[1][0] = map->game->triangle_x - 4;
	point[1][1] = map->game->triangle_y + 10;
	point[2][0] = map->game->triangle_x + 4;
	point[2][1] = map->game->triangle_y + 10;
	cx = (point[0][0] + point[1][0] + point[2][0]) / 3;
	cy = (point[0][1] + point[1][1] + point[2][1]) / 3;
	i = 0;
	while (i < 3)
	{
		rotate_point(cx, cy, map->game->angle, &point[i][0], &point[i][1]);
		i++;
	}
	draw_line(map->game, point[0][0], point[0][1], point[1][0], point[1][1]);
	draw_line(map->game, point[1][0], point[1][1], point[2][0], point[2][1]);
	draw_line(map->game, point[2][0], point[2][1], point[0][0], point[0][1]);
	fill_triangle(map->game, point[0][0], point[0][1], point[1][0], point[1][1], point[2][0], point[2][1]);
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	for (int y = 0; y < 1920; y++) {
		for (int x = 0; x < 1080; x++) {
			mlx_put_pixel(data->game->frame, y, x, 0x00000000); // Black color
		}
	}
    if (data->game->move == 1) {
		data->mini_map->pos_y = data->mini_map->pos_y - 1;
        data->game->move = 0;
	}
    if (data->game->move == 2) {
		data->mini_map->pos_y = data->mini_map->pos_y + 1;
        data->game->move = 0;
	}
    if (data->game->move == 3) {
		data->mini_map->pos_x = data->mini_map->pos_x - 1;
        data->game->move = 0;
	}
    if (data->game->move == 4) {
		data->mini_map->pos_x = data->mini_map->pos_x + 1;
        data->game->move = 0;
	}
	if (data->game->rotating_left) {
		data->game->angle -= 5;
	}
	if (data->game->rotating_right) {
		data->game->angle += 5;
	}
    mini(data, data->mlx);
	draw_arrow(data);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.action == MLX_PRESS) {
		if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(map->mlx);
		if (keydata.key == MLX_KEY_UP) {
			map->game->moove = 1;
            map->game->move = 1;
		} else if (keydata.key == MLX_KEY_DOWN) {
			map->game->moove = 2;
            map->game->move = 2;
		} else if (keydata.key == MLX_KEY_LEFT) {
			map->game->moove = 3;
            map->game->move = 3;
		} else if (keydata.key == MLX_KEY_RIGHT) {
			map->game->moove = 4;
            map->game->move = 4;
		} else if (keydata.key == MLX_KEY_Q) {
			map->game->rotating_left = true;
		} else if (keydata.key == MLX_KEY_E) {
			map->game->rotating_right = true;
		}
	} if (keydata.action == MLX_RELEASE) {
		if (keydata.key == MLX_KEY_Q) {
			map->game->rotating_left = false;
		} else if (keydata.key == MLX_KEY_E) {
			map->game->rotating_right = false;
		}
	}
}