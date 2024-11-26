/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:39:46 by derey             #+#    #+#             */
/*   Updated: 2024/11/26 14:27:13 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_ceiling(t_ray *ray, t_map *data, int x, int y)
{
	double		cur_dist;
	double		w;
	uint32_t	color;

	init_floorcelling(ray);
	while (y >= 0)
	{
		cur_dist = -(WINDOWSH / (2.0 * y - WINDOWSH));
		w = cur_dist / ray->wall_dist;
		ray->current_fc_x = w * ray->fl_x + (1.0 - w) * data->game->player_x;
		ray->current_fc_y = w * ray->fl_y + (1.0 - w) * data->game->player_y;
		ray->texture_x = (int)(ray->current_fc_x * data->cell->width)
			% data->cell->width;
		ray->texture_y = (int)(ray->current_fc_y * data->cell->height)
			% data->cell->height;
		color = color_tex(((uint32_t *)data->cell->pixels)
			[ray->texture_y * data->cell->width + ray->texture_x]);
		if (cur_dist >= FOG_MIN && cur_dist < FOG_MAX && data->fog == true)
			color = apply_fog(color, cur_dist);
		if (cur_dist >= FOG_MAX && data->fog == true)
			try_put_pixel(data->rayc, x, y, FOG);
		else
			try_put_pixel(data->rayc, x, y, color);
		y--;
	}
}

void	draw_floor(t_ray *ray, t_map *data, int x, int y)
{
	double		cur_dist;
	double		w;
	uint32_t	color;

	init_floorcelling(ray);
	while (y < WINDOWSH)
	{
		cur_dist = WINDOWSH / (2.0 * y - WINDOWSH);
		w = cur_dist / ray->wall_dist;
		ray->current_fc_x = w * ray->fl_x + (1.0 - w) * data->game->player_x;
		ray->current_fc_y = w * ray->fl_y + (1.0 - w) * data->game->player_y;
		ray->texture_x = (int)(ray->current_fc_x * data->floor->width)
			% data->floor->width;
		ray->texture_y = (int)(ray->current_fc_y * data->floor->height)
			% data->floor->height;
		color = color_tex(((uint32_t *)data->floor->pixels)
			[ray->texture_y * data->floor->width + ray->texture_x]);
		if (cur_dist >= FOG_MIN && cur_dist < FOG_MAX && data->fog == true)
			color = apply_fog(color, cur_dist);
		if (cur_dist >= FOG_MAX && data->fog == true)
			try_put_pixel(data->rayc, x, y, FOG);
		else
			try_put_pixel(data->rayc, x, y, color);
		y++;
	}
}

void	draw_night(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int			y;
	uint32_t	cl;

	y = 0;
	ray->texture_y = 0;
	ray->step = WINDOWSH / tex->height;
	while (y < ray->draw_start)
	{
		ray->texture_y = y * ray->step;
		cl = ((uint32_t *)tex->pixels)[ft_abs(tex->width * ray->texture_y + x)];
		ray->color = color_tex(cl);
		try_put_pixel(data->rayc, x, y, ray->color);
		y++;
	}
}

void	door(t_ray *ray, t_map *data, int x)
{
	int	tmp;

	tmp = index_door(data->door, data->nmb_door, ray->map_x, ray->map_y);
	if (tmp == -1)
		return ;
	if (!ray_hit_door(data, ray, tmp))
		return ;
	init_doors(ray, data, tmp, x);
	if (data->door[tmp].side == 1)
		data->door[tmp].dist = ((ray->sidedist_x + 0.5) - ray->deltadist_x);
	else
		data->door[tmp].dist = ((ray->sidedist_y + 0.5) - ray->deltadist_y);
	if (fabs(data->game->player_y - (double)data->door[tmp].map_y - 0.5) <= 2
		&& fabs(data->game->player_x
			- (double)data->door[tmp].map_x - 0.5) <= 2)
	{
		data->door[tmp].isanime = true;
		data->door[tmp].isopen = true;
	}
	else
		data->door[tmp].isopen = false;
}
