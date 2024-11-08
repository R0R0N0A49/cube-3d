/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/11/08 10:27:23 by derey            ###   ########.fr       */
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
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > WINDOWSH - 0.25 || ray->map_x > WINDOWSW - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
		else if (data->weapon.item.enabled && ray->map_y == (int)(data->weapon.item.posy) && ray->map_x == (int)(data->weapon.item.posx))
		{
			data->weapon.item.isvisible = true;
			if (data->weapon.item.x == -1)
				data->weapon.item.x = x;
			data->weapon.item.x_max = x;
		}
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

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	try_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, int color)
{
	if (x > img->width || y > img->height)
		return ;
	mlx_put_pixel(img, x, y, color);
}



void	draw_nuit(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
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

void	draw_ceiling(t_ray *ray, t_map *data, int x)
{
	int			y;
	double		current_dist;
	double		w;
	uint32_t	color;

	y = ray->draw_start;
	init_floorcelling(ray);
	while (y >= 0)
	{
		current_dist = -(WINDOWSH / (2.0 * y - WINDOWSH));
		w = current_dist / ray->wall_dist;
		ray->current_fc_x = w * ray->fl_x + (1.0 - w) * data->game->player_x;
		ray->current_fc_y = w * ray->fl_y + (1.0 - w) * data->game->player_y;
		ray->texture_x = (int)(ray->current_fc_x * data->plaf->width)
			% data->plaf->width;
		ray->texture_y = (int)(ray->current_fc_y * data->plaf->height)
			% data->plaf->height;
		color = color_tex(((uint32_t *)data->plaf->pixels)
			[ray->texture_y * data->plaf->width + ray->texture_x]);
		if (current_dist >= FOG_MIN && current_dist < FOG_MAX && data->fog == true)
			color = apply_fog(color, current_dist);
		if (current_dist >= FOG_MAX && data->fog == true)
			try_put_pixel(data->rayc, x, y, FOG);
		else
			try_put_pixel(data->rayc, x, y, color);
		y--;
	}
}

void	draw_floor(t_ray *ray, t_map *data, int x)
{
	int			y;
	double		current_dist;
	double		w;
	uint32_t	color;

	y = ray->draw_end;
	init_floorcelling(ray);
	while (y < WINDOWSH)
	{
		current_dist = WINDOWSH / (2.0 * y - WINDOWSH);
		w = current_dist / ray->wall_dist;
		ray->current_fc_x = w * ray->fl_x + (1.0 - w) * data->game->player_x;
		ray->current_fc_y = w * ray->fl_y + (1.0 - w) * data->game->player_y;
		ray->texture_x = (int)(ray->current_fc_x * data->sol->width)
			% data->sol->width;
		ray->texture_y = (int)(ray->current_fc_y * data->sol->height)
			% data->sol->height;
		color = color_tex(((uint32_t *)data->sol->pixels)
			[ray->texture_y * data->sol->width + ray->texture_x]);
		if (current_dist >= FOG_MIN && current_dist < FOG_MAX && data->fog == true)
			color = apply_fog(color, current_dist);
		if (current_dist >= FOG_MAX && data->fog == true)
			try_put_pixel(data->rayc, x, y, FOG);
		else
			try_put_pixel(data->rayc, x, y, color);
		y++;
	}
}

size_t	ft_strlen_w(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != NULL)
		i++;
	return (i);
}

void draw_lines(t_map *data, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        try_put_pixel(data->rayc, x0, y0, color_tex(color));
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

void	draw_ray(int x, t_ray *ray, t_map *data)
{
	mlx_texture_t	*tex;
	int				i;

	i = 0;
	tex = get_texture(ray, data);
	if (data->plafond == true)
		draw_nuit(ray, data, x, data->nuit);
	else
	{
		while (i < ray->draw_start)
		{
			mlx_put_pixel(data->rayc, x, i, data->up);
			i++;
		}
	}
	ray->texture_x = (int)(ray->wall_x * (double)tex->height);
	if ((ray->side == 0 && ray->raydir_x > 0)
		|| (ray->side == 1 && ray->raydir_y < 0))
		ray->texture_x = tex->width - ray->texture_x - 1;
	ray->step = 1.0 * tex->height / ray->line_height;
	ray->texture_pos = (ray->draw_start - WINDOWSH / 2
			+ ray->line_height / 2) * ray->step;
	draw_tex(ray, data, x, tex);
	i = ray->draw_end;
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
		set_side_step(ray, data, x);
		calcul_projected_cam(ray, data);
		draw_ray(x, ray, data);
		draw_floor(ray, data, x);
		if (!data->plafond)
			draw_ceiling(ray, data, x);
		x++;
	}
	if (data->plafond)
		draw_minimap(data);
	if (data->weapon.item.isvisible == true)
		display_item(data, &data->weapon.item);
}
