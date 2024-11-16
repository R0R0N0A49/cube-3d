/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minidata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:43:18 by derey             #+#    #+#             */
/*   Updated: 2024/11/14 14:42:50 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_cube(t_map *data, int i, int j, uint32_t te)
{
	int	a;
	int	b;
	int	c;

	a = i + CUBE;
	b = j + CUBE;
	c = j;
	(void) data;
	while (i < a)
	{
		j = c;
		while (j < b)
		{
			mlx_put_pixel(data->minima, i, j, te);
			j++;
		}
		i++;
	}
}

void draw_lines(t_map *data, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = ft_abs(x1 - x0);
    int dy = ft_abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        try_put_pixel(data->rayc, x0, y0, color);
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

double	normalize_angle(double angle)
{
    while (angle >= M_PI)
        angle -= 2 * M_PI;
    while (angle <= -M_PI)
        angle += 2 * M_PI;
    return angle;
}

double	calculate_fov(double dir_x, double dir_y, double plane_x, double plane_y)
{
	double dir_angle;
	double plane_angle;
	double fov;

	dir_angle = atan2(dir_y, dir_x);
	plane_angle = atan2(plane_y, plane_x);
	fov = fabs(dir_angle - plane_angle ) - 0.4;
	if (fov > M_PI)
		fov = 2 * M_PI - fov;
	return (fov);
}

void	draw_partial_cube(t_map *data, int x, int y, uint32_t color)
{
	int a;
	int	b;
	int i;
	int	j;
	int	dist;

	a = x + CUBE;
	b = y + CUBE;
	i = x;
	while (i < a)
	{
		j = y;
		while (j < b)
		{
			dist = (i - X_MINI) * (i - X_MINI) + (j - Y_MINI) * (j - Y_MINI);
			if (dist <= R_MINI * R_MINI)
				mlx_put_pixel(data->minima, i, j, color);
			j++;
		}
		i++;
	}
}


void	draw_map_in_circle(t_map *data)
{
	double px = data->game->player_x - 0.5;
	double py = data->game->player_y - 0.5;

	for (int y = 0; y < (int)ft_strlen_w(data->map); y++)
	{
		for (int x = 0; x < (int)ft_strlen(data->map[y]); x++)
		{
			if (data->map[y][x] == '1')
			{
				int rel_x = (x - px) * CUBE;
				int rel_y = (y - py) * CUBE;
				int draw_x = X_MINI + rel_x;
				int draw_y = Y_MINI + rel_y;
				draw_partial_cube(data, draw_x - CUBE * 0.5, draw_y - CUBE * 0.5, 0x8E806AFF);
			}
			if (data->map[y][x] == '0')
			{
				int rel_x = (x - px) * CUBE;
				int rel_y = (y - py) * CUBE;
				int draw_x = X_MINI + rel_x;
				int draw_y = Y_MINI + rel_y;
				draw_partial_cube(data, draw_x - CUBE * 0.5, draw_y - CUBE * 0.5, 0xD3B8A5FF);
			}
		}
	}
}

void	draw_circle(t_map *data)
{
	int r = R_MINI + 4;
	double center_angle = atan2(data->game->dir_y, data->game->dir_x);
	center_angle = normalize_angle(center_angle);
	for (int y = -r; y <= r; y++) {
		for (int x = -r; x <= r; x++) {
			if (x * x + y * y <= r * r) {
				mlx_put_pixel(data->minima, X_MINI + x, Y_MINI + y, 0xFFF);
			}
		}
	}
}

void cast_rays_in_circle(t_map *data)
{
	double center_angle = atan2(data->game->dir_y, data->game->dir_x);
	center_angle = normalize_angle(center_angle);
	double fov = calculate_fov(data->game->dir_x, data->game->dir_y, data->game->plane_x, data->game->plane_y);
	fov = normalize_angle(fov);
	double angle_left = normalize_angle(center_angle - fov / 2);
	double angle_right = normalize_angle(center_angle + fov / 2);
	int num_rays = 200;
	for (int i = 0; i <= num_rays; i++)
	{
		double t = (double)i / num_rays;
		double ray_angle;
		if (angle_right < angle_left)
			ray_angle = normalize_angle(angle_left + t * (2 * M_PI + angle_right - angle_left));
		else
			ray_angle = angle_left + t * (angle_right - angle_left);
		double ray_x = data->game->player_x;
		double ray_y = data->game->player_y;
		double step_x = cos(ray_angle) * 0.1;
		double step_y = sin(ray_angle) * 0.1;
		int hit = 0;
		int map_x, map_y;
		int screen_x, screen_y;
		for (int step = 0; step < R_MINI * 10; step++)
		{
			ray_x += step_x;
			ray_y += step_y;
			map_x = (int)ray_x;
			map_y = (int)ray_y;
			screen_x = X_MINI + (ray_x - data->game->player_x) * CUBE;
			screen_y = Y_MINI + (ray_y - data->game->player_y) * CUBE;
			int dist_sq = (screen_x - X_MINI) * (screen_x - X_MINI) + (screen_y - Y_MINI) * (screen_y - Y_MINI);
			if (dist_sq >= (R_MINI * R_MINI))
				break;
			if (data->map[map_y][map_x] == '1')
			{
				draw_lines(data, X_MINI, Y_MINI, screen_x, screen_y, 0xFFFFFFF);
				hit = 1;
				break;
			}
		}
		if (!hit)
			draw_lines(data, X_MINI, Y_MINI, screen_x, screen_y, 0xFFFFFFF);
	}
}


void mini(t_map *data)
{
	draw_circle(data);
	draw_map_in_circle(data);
	cast_rays_in_circle(data);
}

