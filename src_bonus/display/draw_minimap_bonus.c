/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:21:36 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 19:22:24 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_cube(t_map *data, int i, int j, uint32_t te)
{
	int	a;
	int	b;
	int	c;

	a = i + CUBE;
	b = j + CUBE;
	c = j;
	while (i < a)
	{
		j = c;
		while (j < b)
		{
			mlx_put_pixel(data->minima, i, j, te);
			j++;
		}
		i++;
	}
}

void	draw_partial_cube(t_map *data, int x, int y, uint32_t color)
{
	int	a;
	int	b;
	int	i;
	int	j;
	int	dist;

	a = x + CUBE;
	b = y + CUBE;
	i = x;
	while (i < a)
	{
		j = y;
		while (j < b)
		{
			dist = (i - X_MINI) * (i - X_MINI) + (j - Y_MINI) * (j - Y_MINI);
			if (dist <= R_MINI * R_MINI)
				mlx_put_pixel(data->minima, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_w(t_map *data, int xx, int yy)
{
	int	r;
	int	y;
	int	x;
	int	dist;

	r = 5;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			dist = (xx - X_MINI) * (xx - X_MINI) + (yy - Y_MINI)
				* (yy - Y_MINI);
			if (dist <= R_MINI * R_MINI)
			{
				if (x * x + y * y <= r * r)
					mlx_put_pixel(data->minima, xx + x, yy + y, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
}

void	draw_map_in_circle(t_map *data, double px, double py)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)ft_strlen_w(data->map))
	{
		x = -1;
		while (++x < (int)ft_strlen(data->map[y]))
		{
			if (data->map[y][x] == '1')
				init_pt(data, set_vector(x, px), set_vector(y, py), 0x8E806AFF);
			if (data->map[y][x] == '0')
				init_pt(data, set_vector(x, px), set_vector(y, py), 0xD3B8A5FF);
			if (data->map[y][x] == 'D' && data->door[index_door(data->door \
				, data->nmb_door, x, y)].isopen)
				init_pt(data, set_vector(x, px), set_vector(y, py), 0x8CB23EFF);
			if (data->map[y][x] == 'D' && !data->door[index_door(data->door, \
				data->nmb_door, x, y)].isopen)
				init_pt(data, set_vector(x, px), set_vector(y, py), 0xDC0030FF);
			if ((int)data->weapon.item.posx == x && (int)data->weapon.item.posy \
				== y && data->weapon.item.enabled)
				init_pw(data, set_vector(x, px), set_vector(y, py), 0xD3B8A5FF);
		}
	}
}

void	draw_circle(t_map *data, int r)
{
	int	y;
	int	x;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				mlx_put_pixel(data->minima, X_MINI + x, Y_MINI + y, 0xFFF);
			x++;
		}
		y++;
	}
}
