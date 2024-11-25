/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:52:15 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static mlx_texture_t	*get_texture(t_ray *ray, t_map *data)
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

static uint32_t	color_tex(int32_t r)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t	aa;
	uint32_t	color;

	ra = ((r >> 24) & 0xFF);
	ga = ((r >> 16) & 0xFF);
	ba = ((r >> 8) & 0xFF);
	aa = (r & 0xFF);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	return (color);
}

static void	draw_tex(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int			y;
	uint32_t	col;

	y = ray->draw_start;
	while (y >= 0)
	{
		try_put_pixel(data->rayc, x, y, data->up);
		y--;
	}
	y = ray->draw_start - 1;
	while (y < ray->draw_end - 1)
	{
		ray->texture_y = (int)ray->texture_pos & (tex->height - 1);
		ray->texture_pos += ray->step;
		col = ((uint32_t *)tex->pixels)[ft_abs(tex->height
				* (ray->texture_y + 1) - (ray->texture_x + 1))];
		ray->color = color_tex(col);
		try_put_pixel(data->rayc, x, y, ray->color);
		y++;
	}
	while (y < WINDOWSH)
	{
		try_put_pixel(data->rayc, x, y, data->down);
		y++;
	}
}

static void	draw_ray(int x, t_ray *ray, t_map *data)
{
	mlx_texture_t	*tex;
	int				i;

	i = 0;
	tex = get_texture(ray, data);
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
