/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:09:59 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	verif_nmb(char **map, int i, int j)
{
	int	rsl;

	rsl = 0;
	if (map[j - 1][i] == '1')
		rsl++;
	if (map[j + 1][i] == '1')
		rsl++;
	if (map[j][i - 1] == '1')
		rsl++;
	if (map[j][i + 1] == '1')
		rsl++;
	return (rsl);
}

static int	verif_pos(char **map, size_t i, size_t j)
{
	int	z;
	int	o;

	z = '0';
	o = '1';
	if (verif_nmb(map, (int)i, (int)j) != 2)
		return (1);
	if (ft_strlen(map[j - 1]) - 1 <= i || ft_strlen(map[j + 1]) - 1 <= i)
		return (1);
	if (map[j][i - 1] == o && (map[j][i + 1] != o && map[j][i + 1] != '2'))
		return (1);
	if (map[j][i - 1] == z && (map[j][i + 1] != z && !isplayer(map[j][i + 1])))
		return (1);
	if (map[j - 1][i] == o && (map[j + 1][i] != o && map[j + 1][i] != '2'))
		return (1);
	if (map[j - 1][i] == z && (map[j + 1][i] != z && !isplayer(map[j + 1][i])))
		return (1);
	return (0);
}

int	pars_door(char **map, t_map *data)
{
	int	i;
	int	j;

	j = 1;
	while (map && map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'D')
			{
				data->nmb_door++;
				if (i == 0)
					exit(print_charerror(map, j, i, data));
				if (i == 1 && map[j][i - 1] != 1)
					exit(print_charerror(map, j, i, data));
				if (verif_pos(map, i, j))
					exit(print_charerror(map, j, i, data));
			}
			i++;
		}
		j++;
	}
	return (0);
}
