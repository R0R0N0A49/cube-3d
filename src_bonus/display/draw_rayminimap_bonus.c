/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rayminimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:24:23 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 19:24:51 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_lines(t_map *data, t_vector x0, t_vector x1, uint32_t color)
{
	t_line_bresenham	bres;
	int					e2;

	init_draw_lines(&bres, x0, x1);
	while (x0.x != x1.x || x0.y != x1.y)
	{
		try_put_pixel(data->minima, x0.x, x0.y, color);
		e2 = bres.err * 2;
		if (e2 > -bres.dy)
		{
			bres.err -= bres.dy;
			x0.x += bres.sx;
		}
		if (e2 < bres.dx)
		{
			bres.err += bres.dx;
			x0.y += bres.sy;
		}
	}
}

void	algo_raymini(t_map *data, t_raymini *ray_mi)
{
	ray_mi->ray_x += ray_mi->step_x;
	ray_mi->ray_y += ray_mi->step_y;
	ray_mi->map_x = (int)ray_mi->ray_x;
	ray_mi->map_y = (int)ray_mi->ray_y;
	ray_mi->screen_x = X_MINI + (ray_mi->ray_x - data->game->player_x) \
		* CUBE;
	ray_mi->screen_y = Y_MINI + (ray_mi->ray_y - data->game->player_y) \
		* CUBE;
	ray_mi->dist_sq = (ray_mi->screen_x - X_MINI) \
		* (ray_mi->screen_x - X_MINI) + (ray_mi->screen_y - Y_MINI) \
		* (ray_mi->screen_y - Y_MINI);
}

void	loop_raymini(t_map *data, t_raymini *ray_mi)
{
	while (ray_mi->step < R_MINI * 10)
	{
		algo_raymini(data, ray_mi);
		if (ray_mi->dist_sq >= (R_MINI * R_MINI))
			break ;
		if (data->map[ray_mi->map_y][ray_mi->map_x] == '1'
			|| data->map[ray_mi->map_y][ray_mi->map_x] == '\n'
			|| (data->map[ray_mi->map_y][ray_mi->map_x] == 'D'
			&& !data->door[index_door(data->door, data->nmb_door, \
				ray_mi->map_x, ray_mi->map_y)].isopen))
		{
			draw_lines(data, set_vector((double)X_MINI, (double)Y_MINI), \
				set_vector(ray_mi->screen_x, ray_mi->screen_y), 0xFDDCC6FF);
			ray_mi->hit = 1;
			break ;
		}
		ray_mi->step++;
	}
}

void	cast_rays_in_circle(t_map *data)
{
	t_raymini	ray_mi;

	ray_mi.center_angle = atan2(data->game->dir_y, data->game->dir_x);
	ray_mi.center_angle = normalize_angle(ray_mi.center_angle);
	ray_mi.fov = calculate_fov(data->game->dir_x, data->game->dir_y, \
		data->game->plane_x, data->game->plane_y);
	ray_mi.fov = normalize_angle(ray_mi.fov);
	ray_mi.angle_left = normalize_angle(ray_mi.center_angle - ray_mi.fov / 2);
	ray_mi.angle_right = normalize_angle(ray_mi.center_angle + ray_mi.fov / 2);
	ray_mi.num_rays = 800;
	ray_mi.i = 0;
	while (ray_mi.i <= ray_mi.num_rays)
	{
		init_loop_raymini(data, &ray_mi);
		loop_raymini(data, &ray_mi);
		ray_mi.dist_sq = (ray_mi.screen_x - X_MINI) \
			* (ray_mi.screen_x - X_MINI) + (ray_mi.screen_y - Y_MINI) \
			* (ray_mi.screen_y - Y_MINI);
		if (!ray_mi.hit)
			draw_lines(data, set_vector((double)X_MINI, (double)Y_MINI), \
				set_vector(ray_mi.screen_x - 1, ray_mi.screen_y - 1), \
				0xFDDCC6FF);
		ray_mi.i++;
	}
}
