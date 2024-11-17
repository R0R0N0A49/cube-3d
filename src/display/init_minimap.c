/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:18:26 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 19:19:05 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_draw_lines(t_line_bresenham *bres, t_vector x0, t_vector x1)
{
	bres->dx = ft_abs(x1.x - x0.x);
	bres->dy = ft_abs(x1.y - x0.y);
	if (x0.x < x1.x)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (x0.y < x1.y)
		bres->sy = 1;
	else
		bres->sy = -1;
	bres->err = bres->dx - bres->dy;
}

void	init_pt(t_map *data, t_vector x, t_vector y, uint32_t color)
{
	int	rel_x;
	int	rel_y;
	int	draw_x;
	int	draw_y;

	rel_x = (x.x - x.y) * CUBE;
	rel_y = (y.x - y.y) * CUBE;
	draw_x = X_MINI + rel_x;
	draw_y = Y_MINI + rel_y;
	draw_partial_cube(data, draw_x - CUBE * 0.5, draw_y - CUBE * 0.5, color);
}

void	init_pw(t_map *data, t_vector x, t_vector y, uint32_t color)
{
	int	rel_x;
	int	rel_y;
	int	draw_x;
	int	draw_y;

	rel_x = (x.x - x.y) * CUBE;
	rel_y = (y.x - y.y) * CUBE;
	draw_x = X_MINI + rel_x;
	draw_y = Y_MINI + rel_y;
	draw_partial_cube(data, draw_x - CUBE * 0.5, draw_y - CUBE * 0.5, color);
	draw_w(data, draw_x, draw_y);
}

void	init_loop_raymini(t_map *data, t_raymini *ray_mi)
{
	ray_mi->t = (double)ray_mi->i / ray_mi->num_rays;
	if (ray_mi->angle_right < ray_mi->angle_left)
		ray_mi->ray_angle = normalize_angle(ray_mi->angle_left + ray_mi->t \
			* (2 * M_PI + ray_mi->angle_right - ray_mi->angle_left));
	else
		ray_mi->ray_angle = ray_mi->angle_left + ray_mi->t \
			* (ray_mi->angle_right - ray_mi->angle_left);
	ray_mi->ray_x = data->game->player_x;
	ray_mi->ray_y = data->game->player_y;
	ray_mi->step_x = cos(ray_mi->ray_angle) * 0.1;
	ray_mi->step_y = sin(ray_mi->ray_angle) * 0.1;
	ray_mi->hit = 0;
	ray_mi->step = 0;
}
