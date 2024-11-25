/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:08:56 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

mlx_texture_t	*get_texture(t_ray *ray, t_map *data)
{
	if (ray->side == 0 && ray->raydir_x > 0)
		return (data->we);
	if (ray->side == 0 && ray->raydir_x < 0)
		return (data->ea);
	if (ray->side == 1 && ray->raydir_y < 0)
		return (data->so);
	if (ray->side == 1 && ray->raydir_y > 0)
		return (data->no);
	return (data->no);
}

void	draw_tex(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int			y;
	uint32_t	col;

	y = ray->draw_start - 1;
	if (ray->wall_dist >= FOG_MAX && data->fog == true)
	{
		while (y < ray->draw_end)
			try_put_pixel(data->rayc, x, y++, FOG);
		return ;
	}
	while (y < ray->draw_end)
	{
		ray->texture_y = (int)ray->texture_pos & (tex->height - 1);
		ray->texture_pos += ray->step;
		col = ((uint32_t *)tex->pixels)[ft_abs(tex->height
				* (ray->texture_y + 1) - (ray->texture_x + 1))];
		if (ray->wall_dist >= FOG_MIN && data->fog == true)
			ray->color = color_fog(col, ray);
		else
			ray->color = color_tex(col);
		try_put_pixel(data->rayc, x, y, ray->color);
		y++;
	}
}

void	draw_ray(int x, t_ray *ray, t_map *data)
{
	mlx_texture_t	*tex;
	int				i;

	i = 0;
	tex = get_texture(ray, data);
	if (data->ceiling == true)
		draw_nuit(ray, data, x, data->night);
	else
	{
		if (!ray->isdoor)
		{
			while (i < ray->draw_start)
				mlx_put_pixel(data->rayc, x, i++, data->up);
		}
	}
	ray->texture_x = (int)(ray->wall_x * (double)tex->height);
	if ((ray->side == 0 && ray->raydir_x > 0)
		|| (ray->side == 1 && ray->raydir_y < 0))
		ray->texture_x = tex->width - ray->texture_x - 1;
	ray->step = 1.0 * tex->height / ray->line_height;
	ray->texture_pos = (ray->draw_start - WINDOWSH * 0.5
			+ ray->line_height * 0.5) * ray->step;
	draw_tex(ray, data, x, tex);
}

void	raycasting(t_map *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = data->raycast;
	ray->isdoor = false;
	while (x < WINDOWSW)
	{
		init_raycast(x, ray, data->game);
		init_step(ray, data);
		set_side_step(ray, data, x);
		calcul_projected_cam(ray, data);
		draw_ray(x, ray, data);
		draw_floor(ray, data, x, ray->draw_end);
		if (!data->ceiling)
			draw_ceiling(ray, data, x, ray->draw_start);
		chois_door(data);
		x++;
	}
	if (data->mini_iso->enabled && data->w_map <= 35 && data->h_map <= 25)
		draw_minimap(data);
	if (data->weapon.item.isvisible == true)
		display_item(data, &data->weapon.item);
}
