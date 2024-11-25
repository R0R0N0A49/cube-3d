/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:02:20 by trebours          #+#    #+#             */
/*   Updated: 2024/11/18 11:02:22 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
