/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 16:46:28 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	loop_door(t_map *data)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	tmp = 0;
	while (data->map[j] && tmp < data->nmb_door)
	{
		i = 0;
		while (data->map[j][i] && tmp < data->nmb_door)
		{
			if (data->map[j][i] == 'D')
			{
				data->door[tmp].map_x = i;
				data->door[tmp].map_y = j;
				if (data->map[j][i + 1] == '1')
					data->door[tmp].side = !data->door[tmp].side;
				tmp++;
			}
			i++;
		}
		j++;
	}
}

static void	init_image(t_door *door)
{
	door->door = ft_calloc(14, sizeof(TXT *));
	door->door[0] = mlx_load_png("tiles/textures/door/door_1.png");
	door->door[1] = mlx_load_png("tiles/textures/door/door_2.png");
	door->door[2] = mlx_load_png("tiles/textures/door/door_3.png");
	door->door[3] = mlx_load_png("tiles/textures/door/door_4.png");
	door->door[4] = mlx_load_png("tiles/textures/door/door_5.png");
	door->door[5] = mlx_load_png("tiles/textures/door/door_6.png");
	door->door[6] = mlx_load_png("tiles/textures/door/door_7.png");
	door->door[7] = mlx_load_png("tiles/textures/door/door_8.png");
	door->door[8] = mlx_load_png("tiles/textures/door/door_9.png");
	door->door[9] = mlx_load_png("tiles/textures/door/door_10.png");
	door->door[10] = mlx_load_png("tiles/textures/door/door_11.png");
	door->door[11] = mlx_load_png("tiles/textures/door/door_12.png");
	door->door[12] = mlx_load_png("tiles/textures/door/door_13.png");
	door->door[13] = mlx_load_png("tiles/textures/door/door_14.png");
}

void	init_loop_door(t_map *data, int i)
{
	data->door[i].isvisible = false;
	data->door[i].isopen = false;
	data->door[i].dist = 0;
	data->door[i].i = 0;
	data->door[i].j = 0;
	data->door[i].map_x = 0;
	data->door[i].map_y = 0;
	data->door[i].sidedist_x = 0;
	data->door[i].sidedist_y = 0;
	data->door[i].side = 1;
	data->door[i].line_height = 0;
	data->door[i].draw_start = 0;
	data->door[i].draw_end = 0;
	data->door[i].texture_x = 0;
	data->door[i].texture_y = 0;
	data->door[i].door_x = 0;
	data->door[i].door_y = 0;
	data->door[i].raydir_y = 0;
	data->door[i].raydir_x = 0;
	data->door[i].step = 0;
	data->door[i].texture_pos = 0;
	data->door[i].dist_center = -1;
	data->door[i].isanime = false;
	data->door[i].time = 0;
	data->door[i].index = 0;
}

void	init_door(t_map *data)
{
	int	i;

	if (!data->nmb_door)
		return ;
	data->door = malloc(data->nmb_door * sizeof(t_door));
	if (!data->door)
		exit(1);
	i = 0;
	while (i < data->nmb_door)
	{
		init_image(&data->door[i]);
		init_loop_door(data, i);
		i++;
	}
	if (i != 0)
		loop_door(data);
}
