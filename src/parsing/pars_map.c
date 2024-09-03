/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/03 11:07:06 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int isfine(char **map, int i, int j)
{
	char	*lstchar;
	int 	k;

	lstchar = "10 NSWE\n\0";
	k = 0;
	while (lstchar[k])
	{
		if (map[j][i] == lstchar[k])
			return (0);
		k++;
	}
	return (1);
}

void	checkline(char **map, int j, int len)
{
	int		i;

	i = 0;
	while (map[j][i] == ' ')
		i++;
	if (j == 0)
	{
		while (map[j][i] == '1' || map[j][i] == ' ')
			i++;
	}
	// else
	// {
		// if (map[j][i] == '1')
	// }
	if (map[j][i] == '\n')
		return ;
	exit(231);
}

void	check_space(t_map *data, int i , int j)
{
	if (data->map[j][i] == '0')
	{
		if (data->map[j + 1][i] == ' ')
			data->map[j + 1][i] = '1';
		if (j && data->map[j - 1][i] == ' ')
			data->map[j - 1][i] = '1';
		if (i && data->map[j][i - 1] == ' ')
			data->map[j][i - 1] = '1';
		if (data->map[j][i + 1] == ' ')
			data->map[j][i + 1] = '1';
	}
}

int	verif_char(t_map *data)
{
	int i;
	int j;

	if (!data->map)
		return (-1);
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (isfine(data->map, i, j))
			{
				print_charerror(data->map[j], i, j);
				return (1);
			}
			check_space(data, i, j);
			i++;
		}
		j++;
	}
	return (0);
}
