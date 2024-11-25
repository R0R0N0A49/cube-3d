/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:45:36 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:07:47 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
		if (door->dist >= FOG_MAX && data->fog == true)
			col = FOG;
		else if (door->dist >= FOG_MIN && data->fog == true)
			col = color_fog_door(col_tmp, door);
		else
			col = color_tex(col_tmp);
		try_put_pixel(data->rayc, x, y, col);
		y++;
	}
}

static void	select_tex(t_door *door)
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

static void	draw_doo(int x, t_map *data, int i)
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
	int	*j;

	i = 0;
	j = ft_calloc(data->nmb_door, sizeof(int));
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
	free(j);
}
