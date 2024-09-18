/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/18 15:44:49 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	loop_map(char **map, int j, int i, t_map *	data)
{
	while (map[j][i])
	{
		if (map[j][i] == '2')
		{
			if (map[j][i + 1] == ' ' || map[j][i - 1] == ' '
				|| map[j - 1][i] == ' ' || map[j + 1][i] == ' ')
			{
				map[j][i] = ' ';
				return (print_charerror(map, j, i, data));
			}
		}
		i++;
	}
	if (ft_strlen(map[j]) > ft_strlen(map[j + 1]))
	{
		i = ft_strlen(map[j + 1]) - 1;
		while (map[j][i] == '1')
			i++;
		if (map[j][i] == '0' || map[j][i] == '2')
			return (print_charerror(map, j, i, data));
	}
	if (ft_strlen(map[j - 1]) < ft_strlen(map[j]))
	{
		i = ft_strlen(map[j - 1]) - 1;
		while (map[j][i] == '1')
			i++;
		if (map[j][i] == '0' || (map[j][i] == ' ' && map[j - 1][i] != '1'))
			return (print_charerror(map, j, i, data));
	}
	return (0);
}

static int	first_line(char **map, int j, t_map *data)
{
	unsigned long	i;

	i = 0;
	while (map[j][i] == ' ' || map[j][i] == '1')
	{
		if (i < ft_strlen(map[j + 1]) - 1 && map[j][i] == ' '
			&& map[j + 1][i] != ' ' && map[j + 1][i] != '1'
			&& map[j + 1][i] != '2')
			return (print_charerror(map, j, i, data));
		i++;
	}
	if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
		return (print_charerror(map, j, i, data));
	return (0);
}

static int	last_line(char **map, int j, t_map *data)
{
	unsigned long	i;

	i = 0;
	while (map[j][i] == ' ' || map[j][i] == '1')
	{
		if (i < ft_strlen(map[j - 1]) - 1 && map[j][i] == ' '
			&& map[j - 1][i] != ' ' && map[j - 1][i] != '1'
			&& map[j - 1][i] != '2')
			return (print_charerror(map, j, i, data));
		i++;
	}
	if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
		return (print_charerror(map, j, i, data));
	return (0);
}

static int	middle_line(char **map, int j, t_map *data)
{
	int	i;

	i = ft_strlen(map[j]) - 2;
	while (map[j][i] == ' ')
		i--;
	if (map[j][i] != '1')
		return (print_charerror(map, j, i, data));
	i = 0;
	if (map[j][i] == ' ')
	{
		while (map[j][i] == ' ' && map[j][i + 1] == ' ')
			i++;
		if (map[j][i] == ' ' && map[j - 1][i] != ' ' && map[j - 1][i] != '1')
			return (1);
		i++;
	}
	if (map[j][i] != '1')
		return (print_charerror(map, j, i, data));
	return (loop_map(map, j, i, data));
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
