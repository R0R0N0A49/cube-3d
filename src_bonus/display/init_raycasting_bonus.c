/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:36:14 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:08:15 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_struct_ray(t_ray *ray)
{
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->camera_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_raycast(int x, t_ray *ray, t_game *game)
{
	init_struct_ray(ray);
	ray->camera_x = 2 * x / (double)WINDOWSW - 1;
	ray->raydir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->raydir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->player_x;
	ray->map_y = (int)game->player_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
}

void	init_step(t_ray *ray, t_map *data)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->game->player_x - ray->map_x)
			* ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - data->game->player_x)
			* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->game->player_y - ray->map_y)
			* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - data->game->player_y)
			* ray->deltadist_y;
	}
}

void	init_doors(t_ray *ray, t_map *data, int tmp, int x)
{
	data->door[tmp].x = x;
	data->door[tmp].sidedist_y = ray->sidedist_y;
	data->door[tmp].sidedist_x = ray->sidedist_x;
	data->door[tmp].isvisible = true;
	data->door[tmp].raydir_x = ray->raydir_x;
	data->door[tmp].raydir_y = ray->raydir_y;
	data->door[tmp].dist_center = fabs(data->game->player_y
			- (double)data->door[tmp].map_y - 0.5)
		+ fabs(data->game->player_x - (double)data->door[tmp].map_x - 0.5);
}

void	init_floorcelling(t_ray *ray)
{
	if (ray->side == 0 && ray->raydir_x > 0)
	{
		ray->fl_x = ray->map_x;
		ray->fl_y = ray->map_y + ray->wall_x;
	}
	else if (ray->side == 0 && ray->raydir_x < 0)
	{
		ray->fl_x = ray->map_x + 1.0;
		ray->fl_y = ray->map_y + ray->wall_x;
	}
	else if (ray->side == 1 && ray->raydir_y > 0)
	{
		ray->fl_x = ray->map_x + ray->wall_x;
		ray->fl_y = ray->map_y;
	}
	else
	{
		ray->fl_x = ray->map_x + ray->wall_x;
		ray->fl_y = ray->map_y + 1.0;
	}
}
