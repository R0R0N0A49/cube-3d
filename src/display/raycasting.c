/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/09/16 17:02:37 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		ray->sidedist_x = (data->game->player_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - data->game->player_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->game->player_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - data->game->player_y) * ray->deltadist_y;
	}
}

void	set_side_step(t_ray *ray, t_map *data)
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
		if (ray->map_y < 0.25 || ray->map_x < 0.25 || ray->map_y > WINDOWSH - 0.25 || ray->map_x > WINDOWSW - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
	
}

void	calcul_projected_cam(t_ray *ray, t_map *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOWSH / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WINDOWSH / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height) / 2 + WINDOWSH / 2;
	if (ray->draw_end >= WINDOWSH)
		ray->draw_end = WINDOWSH - 1;
	if (ray->side == 0)
		ray->wall_x = data->game->player_y + ray->wall_dist * ray->raydir_y;
	else
		ray->wall_x = data->game->player_x + ray->wall_dist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	draw_ray(int x, t_ray *ray, t_map *data)
{
	uint32_t color;
	int	start;
	int	i;

	i= 0;
	start = ray->draw_start;
	color = 0x7f;
	if (ray->side == 1)
		color = 0x7f11e0;
	while (i < start)
	{
		mlx_put_pixel(data->rayc, x, i, 0xFFFFFFF);
		i++;
	}
	while (start <= ray->draw_end)
	{
		mlx_put_pixel(data->rayc, x, start, color);
		start++;
	}
	i = ray->draw_end;
	while (i < WINDOWSH)
	{
		mlx_put_pixel(data->rayc, x, i, 0xFFF);
		i++;
	}
}

void	raycasting(t_map *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = data->raycast;
	clean_frame(data);
	while (x < WINDOWSW)
	{
		init_raycast(x, ray, data->game);
		init_step(ray, data);
		set_side_step(ray, data);
		calcul_projected_cam(ray, data);
		draw_ray(x, ray, data);
		x++;
	}
	
}
