/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:40 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 17:46:20 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	set_side_step_end(t_ray *ray, t_map *data, int x)
{
	if (ray->map_y < 0.25 || ray->map_x < 0.25
		|| ray->map_y > WINDOWSH - 0.25 || ray->map_x > WINDOWSW - 1.25)
		return (-1);
	else if (data->map[ray->map_y][ray->map_x] > '0'
		&& data->map[ray->map_y][ray->map_x] < 'D')
		return (1);
	else if (data->weapon.item.enabled
		&& ray->map_y == (int)(data->weapon.item.posy)
		&& ray->map_x == (int)(data->weapon.item.posx))
	{
		data->weapon.item.isvisible = true;
		if (ray->side == 0)
			data->weapon.item.dist = ray->sidedist_x - ray->deltadist_x;
		else
			data->weapon.item.dist = ray->sidedist_y - ray->deltadist_y;
		if (data->weapon.item.x == -1)
			data->weapon.item.x = x;
		data->weapon.item.x_max = x;
	}
	return (0);
}

void	set_side_step(t_ray *ray, t_map *data, int x)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		hit = set_side_step_end(ray, data, x);
		if (hit == -1)
			break ;
		if (data->map[ray->map_y][ray->map_x] == 'D')
			door(ray, data, x);
	}
}

void	calcul_projected_cam(t_ray *ray, t_map *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOWSH / ray->wall_dist);
	ray->draw_start = -(ray->line_height) * 0.5 + WINDOWSH * 0.5;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height) * 0.5 + WINDOWSH * 0.5;
	if (ray->draw_end >= WINDOWSH)
		ray->draw_end = WINDOWSH - 1;
	if (ray->side == 0)
		ray->wall_x = data->game->player_y + ray->wall_dist * ray->raydir_y;
	else
		ray->wall_x = data->game->player_x + ray->wall_dist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
}
