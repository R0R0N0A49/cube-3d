/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:00:28 by trebours          #+#    #+#             */
/*   Updated: 2024/11/18 14:01:27 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_music(t_map *data)
{
	static int	play = 0;
	int			i;

	if ((!play || play == 1) && data->menu_option->play_music && data->pause)
	{
		if (play)
			i = system("killall paplay");
		i = system("paplay Music/Menu.wav &");
		play = 2;
	}
	else if ((!play || play == 2) && data->menu_option->play_music && \
			!data->pause)
	{
		if (play)
			i = system("killall paplay");
		i = system("paplay ./Music/InGame.wav &");
		play = 1;
	}
	else if (play && !data->menu_option->play_music)
	{
		i = system("killall paplay &");
		play = 0;
	}
	(void)i;
}

void	check_door_open(t_map	*data)
{
	int	i;

	i = 0;
	while (i < data->nmb_door)
	{
		if (data->door[i].isopen)
		{
			if (ft_abs(data->door[i].map_x - (int)data->game->player_x) > 2)
			{
				data->door[i].isopen = false;
				data->door[i].index = 0;
			}
			if (ft_abs(data->door[i].map_y - (int)data->game->player_y) > 2)
			{
				data->door[i].isopen = false;
				data->door[i].index = 0;
			}
		}
		i++;
	}
}

int	check_open(t_map *data, int x, int y)
{
	if (data->map[y][x] == 'D')
	{
		if (data->door[index_door(data->door, data->nmb_door, x, y)].isopen)
			return (0);
		return (1);
	}
	return (0);
}
