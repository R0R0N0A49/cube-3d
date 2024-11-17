/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:45:36 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 18:07:04 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	set_vector(double x, double y)
{
	t_vector	result_vector;

	result_vector.x = x;
	result_vector.y = y;
	return (result_vector);
}

double	ft_fmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_fmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static double	cross_product(t_vector p1, t_vector p2, t_vector p3)
{
	return ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
}

static int	is_point_on_segment(t_vector p, t_vector q, t_vector r)
{
	return (r.x <= ft_fmax(p.x, q.x) && r.x >= ft_fmin(p.x, q.x) && \
			r.y <= ft_fmax(p.y, q.y) && r.y >= ft_fmin(p.y, q.y));
}

static int	is_line_hitting_segment(t_vector v1p1, t_vector v1p2, \
	t_vector v2p1, t_vector v2p2)
{
	double	d1;
	double	d2;
	double	d3;
	double	d4;

	d1 = cross_product(v1p1, v1p2, v2p1);
	d2 = cross_product(v1p1, v1p2, v2p2);
	d3 = cross_product(v2p1, v2p2, v1p1);
	d4 = cross_product(v2p1, v2p2, v1p2);
	if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
		return (1);
	if (d1 == 0 && is_point_on_segment(v1p1, v1p2, v2p1))
		return (1);
	if (d2 == 0 && is_point_on_segment(v1p1, v1p2, v2p2))
		return (1);
	if (d3 == 0 && is_point_on_segment(v2p1, v2p2, v1p1))
		return (1);
	if (d4 == 0 && is_point_on_segment(v2p1, v2p2, v1p2))
		return (1);
	return (0);
}

int	ray_hit_door(t_map *data, t_ray *ray, int i)
{
	return (((data->door[i].side == 1 && \
		is_line_hitting_segment(set_vector(data->game->player_x, \
		data->game->player_y), set_vector(data->game->player_x \
		+ ray->raydir_x, data->game->player_y + ray->raydir_y), \
		set_vector(data->door[i].map_x + 0.5, \
		data->door[i].map_y), set_vector(data->door[i].map_x + \
		0.5, data->door[i].map_y + 1))) || (data->door[i].side == 0 && \
		is_line_hitting_segment(set_vector(data->game->player_x, \
		data->game->player_y), set_vector(data->game->player_x + \
		ray->raydir_x, data->game->player_y + ray->raydir_y), \
		set_vector(data->door[i].map_x, data->door[i].map_y + 0.5), \
		set_vector(data->door[i].map_x + 1, data->door[i].map_y + 0.5)))));
}

int	index_door(t_door *door, int nmb_door, int x, int y)
{
	int	tmp;

	tmp = 0;
	while (tmp < nmb_door && (y != door[tmp].map_y || x != door[tmp].map_x))
		tmp++;
	if (tmp >= nmb_door)
		return (-1);
	return (tmp);
}

static float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

uint32_t	color_fog_door(int32_t a, t_door *ray)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t	aa;
	float		t;

	ra = ((a >> 24) & 0xFF);
	ga = ((a >> 16) & 0xFF);
	ba = ((a >> 8) & 0xFF);
	aa = (a & 0xFF);
	t = (ray->dist - FOG_MIN) / (FOG_MAX - FOG_MIN);
	aa = ft_lerp(aa, 0x00, t);
	ga = ft_lerp(ga, 0x00, t);
	ba = ft_lerp(ba, 0x00, t);
	return ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
}

static void	draw_tex(t_door *door, t_map *data, int x, mlx_texture_t *tex)
{
	int			y;
	uint32_t	col_tmp;
	uint32_t	col;

	y = door->draw_start - 1;
	while (y < door->draw_end)
	{
		door->texture_y = (int)door->texture_pos & (tex->height - 1);
		door->texture_pos += door->step;
		col_tmp = ((uint32_t *)tex->pixels)[ft_abs(tex->height
				* (door->texture_y + 1) - (door->texture_x + 1))];
		if ((col_tmp & 0xFFFFFFFF) == 0)
			return ;
		if (door->dist >= FOG_MIN && data->fog == true)
			col = color_fog_door(col_tmp, door);
		else
			col = color_tex(col_tmp);
		try_put_pixel(data->rayc, x, y, col);
		y++;
	}
}

void	select_tex(t_door *door)
{
	if (door->isopen && door->isanime && door->index < 13
		&& get_time() - door->time > 50)
		door->index++;
	else if (!door->isopen && door->dist_center > 2 && door->index > 0
		&& get_time() - door->time > 50)
	{
		door->index--;
		door->isanime = true;
	}
	else
		door->isanime = false;
	if (door->isanime)
		door->time = get_time();
}

void	draw_doo(int x, t_map *data, int i)
{
	mlx_texture_t	*tex;

	select_tex(&data->door[i]);
	tex = data->door[i].door[data->door[i].index];
	data->door[i].texture_x = (int)(data->door[i].door_x * (double)tex->height);
	if ((data->door[i].side == 1 && data->door[i].raydir_x > 0)
		|| (data->door[i].side == 0 && data->door[i].raydir_y < 0))
		data->door[i].texture_x = tex->width - data->door[i].texture_x - 1;
	data->door[i].step = 1.0 * tex->height / data->door[i].line_height;
	data->door[i].texture_pos = (data->door[i].draw_start - WINDOWSH / 2
			+ data->door[i].line_height / 2) * data->door[i].step;
	draw_tex(&data->door[i], data, x, tex);
	data->door[i].x = -1;
}

void	raycast_door(t_door *door, t_map *data)
{
	door->line_height = (int)(WINDOWSH / door->dist);
	door->draw_start = -(door->line_height) / 2 + WINDOWSH / 2;
	if (door->draw_start < 0)
		door->draw_start = 0;
	door->draw_end = (door->line_height) / 2 + WINDOWSH / 2;
	if (door->draw_end >= WINDOWSH)
		door->draw_end = WINDOWSH - 1;
	if (door->side == 1)
		door->door_x = data->game->player_y + door->dist * door->raydir_y;
	else
		door->door_x = data->game->player_x + door->dist * door->raydir_x;
	door->door_x -= floor(door->door_x);
}

static void	next(t_door *door, int *result, int max, int tmp)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		result[i] = i;
		i++;
	}
	i = 0;
	while (i < max - 1)
	{
		j = i + 1;
		while (j < max)
		{
			if (door[result[i]].dist_center < door[result[j]].dist_center)
			{
				tmp = result[i];
				result[i] = result[j];
				result[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	chois_door(t_map *data)
{
	int	i;
	int	j[data->nmb_door];

	i = 0;
	next(data->door, j, data->nmb_door, 0);
	while (i < data->nmb_door)
	{
		if (data->door[j[i]].isvisible == true && data->door[j[i]].x != -1)
		{
			raycast_door(&data->door[j[i]], data);
			draw_doo(data->door[j[i]].x, data, j[i]);
			data->door[j[i]].isvisible = false;
		}
		i++;
	}
}
