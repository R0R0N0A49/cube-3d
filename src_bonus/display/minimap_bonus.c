/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:43:18 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 19:24:45 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalize_angle(double angle)
{
	while (angle >= M_PI)
		angle -= 2 * M_PI;
	while (angle <= -M_PI)
		angle += 2 * M_PI;
	return (angle);
}

double	calculate_fov(double dir_x, double dir_y, double plane_x,
			double plane_y)
{
	double	dir_angle;
	double	plane_angle;
	double	fov;

	dir_angle = atan2(dir_y, dir_x);
	plane_angle = atan2(plane_y, plane_x);
	fov = fabs(dir_angle - plane_angle) - 0.4;
	if (fov > M_PI)
		fov = 2 * M_PI - fov;
	return (fov);
}

void	mini(t_map *data)
{
	draw_circle(data, R_MINI + 5);
	draw_map_in_circle(data, data->game->player_x - 0.5, \
		data->game->player_y - 0.5);
	cast_rays_in_circle(data);
	draw_circle(data, 4);
}
