/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/09/27 14:22:19 by derey            ###   ########.fr       */
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

mlx_texture_t *get_texture(t_ray *ray, t_map *data)
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

uint32_t	color_tex(int32_t r)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t aa;
	uint32_t color;

	ra = ((r >> 24) & 0xFF);
	ga = ((r >> 16) & 0xFF);
	ba = ((r >> 8) & 0xFF);
	aa = (r & 0xFF);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	return (color);
}

float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

uint32_t	color_fog(int32_t a, t_ray *ray)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t color;
	uint32_t aa;
	float	t;

	ra = ((a >> 24) & 0xFF);
	ga = ((a >> 16) & 0xFF);
	ba = ((a >> 8) & 0xFF);
	aa = (a & 0xFF);
	t = (ray->wall_dist - FOG_MIN) / (FOG_MAX - FOG_MIN);
	aa = ft_lerp(aa, 0x00, t);
	ga = ft_lerp(ga, 0x00, t);
	ba = ft_lerp(ba, 0x00, t);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	//printf("%X || %X\n", color, ra);
	return (color);
}

uint32_t	color_fog_2(int32_t a, int h)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t color;
	uint32_t aa;
	float	t;

	aa = ((a >> 24) & 0xFF);
	ba = ((a >> 16) & 0xFF);
	ga = ((a >> 8) & 0xFF);
	ra = (a & 0xFF);
	t = (4 * h / (float)WINDOWSH) - 2.0f;
	if (t < 0)
		t = -t;
	aa = ft_lerp(aa, 0x00, t);
	ga = ft_lerp(ga, 0x00, t);
	ba = ft_lerp(ba, 0x00, t);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	//printf("%X || %X\n", color, ra);
	return (color);
}

void	draw_nuit(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int y;
	uint32_t col;

	y = 0;
	ray->texture_y = 0;
	ray->step = WINDOWSH / tex->height;
	while (y < ray->draw_start)
	{
		ray->texture_y = y * ray->step;
		col = ((uint32_t *)tex->pixels)[ft_abs(tex->width * ray->texture_y + x)];
		ray->color = color_tex(col);
		try_put_pixel(data->rayc, x, y, ray->color);
		y++;
	}
}

void	draw_tex(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int y;
	uint32_t col;

	y = ray->draw_start - 1;
	if (ray->wall_dist >= FOG_MAX && data->fog == true)
	{
		while(y < ray->draw_end) try_put_pixel(data->rayc, x, y++, FOG);
		return;
	}
	while (y < ray->draw_end)
	{
		ray->texture_y = (int)ray->texture_pos & (tex->height - 1);
		ray->texture_pos += ray->step;
		//printf("%d\n", ray->line_height);
		col = ((uint32_t *)tex->pixels)[ft_abs(tex->height * (ray->texture_y + 1) - (ray->texture_x + 1))];
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
	mlx_texture_t *tex;
	int	i;

	i= 0;
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
	if ((ray->side == 0 && ray->raydir_x > 0) || (ray->side == 1 && ray->raydir_y < 0))
		ray->texture_x = tex->width - ray->texture_x - 1;
	ray->step = 1.0 * tex->height / ray->line_height;
	ray->texture_pos = (ray->draw_start - WINDOWSH / 2 + ray->line_height / 2) * ray->step;
	draw_tex(ray, data, x, tex);
	i = ray->draw_end;
	while (i < WINDOWSH)
	{
		if (i <= 3 * (WINDOWSH / 4))
			mlx_put_pixel(data->rayc, x, i, color_fog_2(data->down, i - WINDOWSH / 4));
		else
			mlx_put_pixel(data->rayc, x, i, data->down);
		i++;
	}
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
