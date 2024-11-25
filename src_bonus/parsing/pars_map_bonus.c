/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:10:03 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	isfine(char **map, int i, int j)
{
	char	*lstchar;
	int		k;

	lstchar = "210 NSWED\n\0";
	k = 0;
	while (lstchar[k])
	{
		if (map[j][i] == lstchar[k])
			return (0);
		k++;
	}
	return (1);
}

int	isplayer(char const c)
{
	if (c == 'S')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'W')
		return (1);
	if (c == 'E')
		return (1);
	return (0);
}

int	checkline(char **map, int j, int len, t_map *data)
{
	int	i;

	if (j == 0)
		i = first_line(map, j, data);
	else if (j == len - 1)
		i = last_line(map, j, data);
	else
		i = middle_line(map, j, data);
	return (i);
}

int	verif_char(t_map *data)
{
	int	i;
	int	j;
	int	player;

	if (!data->map)
		return (-1);
	j = 0;
	player = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (isfine(data->map, i, j))
				exit(print_charerror(data->map, j, i, data));
			if (isplayer(data->map[j][i]))
				player++;
			i++;
		}
		check_space(data->map, j, ' ', '2');
		checkline(data->map, j++, data->len_map, data);
	}
	if (player != 1 || pars_door(data->map, data))
		error_player(player, data);
	return (0);
}
