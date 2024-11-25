/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:27:19 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:07:55 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_corners(t_map *data, int width, int height)
{
	data->m_map->corners[0][0] = data->m_map->mini_x;
	data->m_map->corners[0][1] = data->m_map->mini_y - height * 0.5;
	data->m_map->corners[1][0] = data->m_map->mini_x + (width * 0.5);
	data->m_map->corners[1][1] = data->m_map->mini_y;
	data->m_map->corners[2][0] = data->m_map->mini_x;
	data->m_map->corners[2][1] = data->m_map->mini_y + height * 0.5;
	data->m_map->corners[3][0] = data->m_map->mini_x - (width * 0.5);
	data->m_map->corners[3][1] = data->m_map->mini_y;
}

void	draw_isometric_rhombus(int width, int height, int color, t_map *data)
{
	int		y;
	int		x;

	init_corners(data, width, height);
	y = data->m_map->corners[0][1];
	while (y <= data->m_map->corners[2][1])
	{
		x = data->m_map->corners[3][0];
		while (x <= data->m_map->corners[1][0])
		{
			data->m_map->dx = fabs((x - data->m_map->mini_x) / (double)width);
			data->m_map->dy = fabs((y - data->m_map->mini_y) / (double)height);
			if (data->m_map->dx + data->m_map->dy <= 0.5)
				try_put_pixel(data->mini_iso, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_isome(int width, int height, int color, t_map *data)
{
	int		y;
	int		x;

	init_corners(data, width, height);
	y = data->m_map->corners[0][1];
	data->m_map->slope = (double)(data->m_map->corners[2][1]
			- data->m_map->corners[0][1]) / (data->m_map->corners[1][0]
			- data->m_map->corners[3][0]);
	while (y++ <= data->m_map->corners[2][1])
	{
		x = data->m_map->corners[3][0];
		while (x++ <= data->m_map->corners[1][0])
		{
			data->m_map->dx = fabs((x - data->m_map->mini_x) / (double)width);
			data->m_map->dy = fabs((y - data->m_map->mini_y) / (double)height);
			if (data->m_map->dx + data->m_map->dy <= 0.5)
			{
				data->m_map->adj_color = color;
				if (y <= data->m_map->corners[0][1] + data->m_map->slope *
					(x - data->m_map->corners[3][0]))
					data->m_map->adj_color = 0x1A1D21FF;
				try_put_pixel(data->mini_iso, x, y, data->m_map->adj_color);
			}
		}
	}
}
