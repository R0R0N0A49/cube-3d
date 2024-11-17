/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/08 14:16:45 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int verif_nmb(char **map, int i, int j)
{
	int rsl;

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

static int	verif_pos(char **map, int i, int j)
{
	if (verif_nmb(map, i, j) != 2)
		return (1);
//	printf(" %c \n%c%c%c\n %c \n", map[j - 1][i], map[j][i - 1], map[j][i], map[j][i + 1], map[j + 1][i]);
	if ((int)ft_strlen(map[j - 1]) - 1 <= i || (int)ft_strlen(map[j + 1]) - 1 <= i)
		return (1);
	if (map[j][i - 1] == '1' && (map[j][i + 1] != '1' && map[j][i + 1] != '2'))
		return (1);
	if (map[j][i - 1] == '0' && (map[j][i + 1] != '0' && !isplayer(map[j][i + 1])))
		return (1);
	if (map[j - 1][i] == '1' && (map[j + 1][i] != '1' && map[j + 1][i] != '2'))
		return (1);
	if (map[j - 1][i] == '0' && (map[j + 1][i] != '0' && !isplayer(map[j + 1][i])))
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
					exit(print_charerror(map, j, i, data)); // msg erreur
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
