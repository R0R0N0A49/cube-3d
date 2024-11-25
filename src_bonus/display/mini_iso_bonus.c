/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_iso_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:03:53 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:08:30 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	iso_transform(double x, double y, t_map *data)
{
	double	angle;

	angle = M_PI / 6;
	data->m_map->iso_x = (x - y) * cos(angle);
	data->m_map->iso_y = (x + y) * sin(angle);
}

void	draw_condition(t_map *data, int a)
{
	if (data->map[data->m_map->map_y][data->m_map->map_x] == '1' && a == 1)
		draw_isometric_rhombus(data->m_map->diamond_width - 5,
			data->m_map->diamond_height - 5, 0x8E806AFF, data);
	else if (data->m_map->map_y != 0
		&& data->map[data->m_map->map_y][data->m_map->map_x] == '0'
		&& data->map[data->m_map->map_y - 1][data->m_map->map_x] == '1'
		&& a == 0)
		draw_isome(data->m_map->diamond_width + 2,
			data->m_map->diamond_height + 2, 0xD3B8A5FF, data);
	else if (data->map[data->m_map->map_y][data->m_map->map_x] == '0'
		&& a == 0)
		draw_isometric_rhombus(data->m_map->diamond_width,
			data->m_map->diamond_height, 0xD3B8A5FF, data);
	else if (data->map[data->m_map->map_y][data->m_map->map_x] == 'D'
		&& data->door[index_door(data->door, data->nmb_door, \
		data->m_map->map_x, data->m_map->map_y)].isopen && a == 0)
		draw_isometric_rhombus(data->m_map->diamond_width,
			data->m_map->diamond_height, 0x8CB23EFF, data);
	else if (data->map[data->m_map->map_y][data->m_map->map_x] == 'D'
		&& !data->door[index_door(data->door, data->nmb_door, \
		data->m_map->map_x, data->m_map->map_y)].isopen && a == 0)
		draw_isometric_rhombus(data->m_map->diamond_width,
			data->m_map->diamond_height, 0xDC0030FF, data);
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
		draw_condition(data, a);
		if ((int)data->weapon.item.posx == data->m_map->map_x
			&& (int)data->weapon.item.posy == data->m_map->map_y
			&& data->weapon.item.enabled && a == 0)
			draw_isometric_rhombus(10, 20, 0xFFFFFFF, data);
		data->m_map->map_x++;
	}
	draw_isometric_rhombus(data->m_map->diamond_width,
		data->m_map->diamond_height, 0x00, data);
}

void	draw_minimap(t_map *data)
{
	data->m_map->map_y = 0;
	data->m_map->diamond_width = 59;
	data->m_map->diamond_height = 35;
	while (data->m_map->map_y < (int)ft_strlen_w(data->map))
	{
		loop_draw(data, 0);
		data->m_map->map_y++;
	}
	iso_transform(data->game->player_x, data->game->player_y, data);
	data->m_map->mini_x = (int)(data->m_map->iso_x
			* MINIMAP_SCALE) + MINIMAP_OFFSET_X - 5;
	data->m_map->mini_y = (int)(data->m_map->iso_y
			* MINIMAP_SCALE) + MINIMAP_OFFSET_Y - 15;
	draw_isometric_rhombus(10, 20, 0xFF0000FF, data);
	data->m_map->map_y = 0;
	while (data->m_map->map_y < (int)ft_strlen_w(data->map))
	{
		loop_draw(data, 1);
		data->m_map->map_y++;
	}
}
