/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:03:53 by derey             #+#    #+#             */
/*   Updated: 2024/11/12 13:56:35 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	iso_transform(double x, double y, t_map *data)
{
	double	angle;

	angle = M_PI / 6;
	data->m_map->iso_x = (x - y) * cos(angle);
	data->m_map->iso_y = (x + y) * sin(angle);
}

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
					data->m_map->adj_color = color * 0.5;
				try_put_pixel(data->mini_iso, x, y, data->m_map->adj_color);
			}
		}
	}
}

void	loop_draw(t_map *data, int a)
{
	data->m_map->map_x = 0;
	while (data->m_map->map_x
		< (int)ft_strlen(data->map[data->m_map->map_y]))
	{
		iso_transform(data->m_map->map_x, data->m_map->map_y, data);
		data->m_map->mini_x = (int)(data->m_map->iso_x
				* MINIMAP_SCALE) + MINIMAP_OFFSET_X;
		data->m_map->mini_y = (int)(data->m_map->iso_y
				* MINIMAP_SCALE) + MINIMAP_OFFSET_Y;
		if (data->map[data->m_map->map_y][data->m_map->map_x] == '1' && a == 1)
			draw_isometric_rhombus(data->m_map->losange_width - 5,
				data->m_map->losange_height - 5, WALL_COLOR, data);
		else if (data->m_map->map_y != 0
			&& data->map[data->m_map->map_y][data->m_map->map_x] == '0'
			&& data->map[data->m_map->map_y - 1][data->m_map->map_x] == '1' && a == 0)
			draw_isome(data->m_map->losange_width + 2,
				data->m_map->losange_height + 2, 0xFFFF, data);
		else if (data->map[data->m_map->map_y][data->m_map->map_x] == '0' && a == 0)
			draw_isometric_rhombus(data->m_map->losange_width,
				data->m_map->losange_height, 0xFFFF, data);
		data->m_map->map_x++;
	}
}

void	draw_minimap(t_map *data)
{
	data->m_map->map_y = 0;
	data->m_map->losange_width = 59;
	data->m_map->losange_height = 35;
	while (data->m_map->map_y < (int)ft_strlen_w(data->map))
	{
		loop_draw(data, 0);
		data->m_map->map_y++;
	}
	iso_transform(data->game->player_x, data->game->player_y, data);
	data->m_map->mini_x = (int)(data->m_map->iso_x
			* MINIMAP_SCALE) + MINIMAP_OFFSET_X - 20;
	data->m_map->mini_y = (int)(data->m_map->iso_y
			* MINIMAP_SCALE) + MINIMAP_OFFSET_Y;
	draw_isometric_rhombus(10, 20, PLAYER_COLOR, data);
	data->m_map->map_y = 0;
	while (data->m_map->map_y < (int)ft_strlen_w(data->map))
	{
		loop_draw(data, 1);
		data->m_map->map_y++;
	}
}
