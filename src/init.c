/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:11 by derey             #+#    #+#             */
/*   Updated: 2024/11/19 11:11:00 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_null(t_map *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->down = 0;
	data->up = 0;
	data->file = -1;
	data->map = NULL;
}

static void	init_pos(t_map *data, int i, int j)
{
	data->game->plane_x = 0;
	data->game->plane_y = 0;
	data->game->dir_x = 0;
	data->game->dir_y = 0;
	if (data->map[j][i] == 'N')
	{
		data->game->plane_x = 0.66;
		data->game->dir_y = -1;
	}
	if (data->map[j][i] == 'S')
	{
		data->game->plane_x = -0.66;
		data->game->dir_y = 1;
	}
	if (data->map[j][i] == 'W')
	{
		data->game->plane_y = -0.66;
		data->game->dir_x = -1;
	}
	if (data->map[j][i] == 'E')
	{
		data->game->plane_y = 0.66;
		data->game->dir_x = 1;
	}
}

void	init_player(t_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				data->game->player_x = (double)i + 0.5;
				data->game->player_y = (double)j + 0.5;
				init_pos(data, i, j);
				data->map[j][i] = '0';
				break ;
			}
			i++;
		}
		j++;
	}
}

void	init_game(t_map *data)
{
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_w = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
}
