/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/10 18:47:12 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	loop(char **map, int j, int i)
{
	while (map[j][i])
	{
		if (map[j][i] == '2')
		{
			if (map[j][i + 1] == ' ' || map[j][i - 1] == ' '
				|| map[j - 1][i] == ' ' || map[j + 1][i] == ' ')
			{
				map[j][i] = ' ';
				return (print_charerror(map, j, i));
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
			return (print_charerror(map, j, i));
	}
	if (ft_strlen(map[j - 1]) < ft_strlen(map[j]))
	{
		i = ft_strlen(map[j - 1]) - 1;
		while (map[j][i] == '1')
			i++;
		if (map[j][i] == '0' || map[j][i] == '2')
			return (print_charerror(map, j, i));
	}
	return (0);
}

static int	first_line(char **map, int j)
{
	unsigned long	i;

	i = 0;
	while (map[j][i] == ' ' || map[j][i] == '1')
	{
		if (i < ft_strlen(map[j + 1]) - 1 && map[j][i] == ' '
			&& map[j + 1][i] != ' ' && map[j + 1][i] != '1'
			&& map[j + 1][i] != '2')
			return (print_charerror(map, j, i));
		i++;
	}
	if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
		return (print_charerror(map, j, i));
	return (0);
}

static int	last_line(char **map, int j)
{
	unsigned long	i;

	i = 0;
	while (map[j][i] == ' ' || map[j][i] == '1')
	{
		if (i < ft_strlen(map[j - 1]) - 1 && map[j][i] == ' '
			&& map[j - 1][i] != ' ' && map[j - 1][i] != '1'
			&& map[j - 1][i] != '2')
			return (print_charerror(map, j, i));
		i++;
	}
	if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
		return (print_charerror(map, j, i));
	return (0);
}

static int	middle_line(char **map, int j)
{
	int	i;

	i = ft_strlen(map[j]) - 2;
	while (map[j][i] == ' ')
		i--;
	if (map[j][i] != '1')
		return (print_charerror(map, j, i));
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
		return (print_charerror(map, j, i));
	return (loop(map, j, i));
}

int	checkline(char **map, int j, int len)
{
	int	i;

	if (j == 0)
		i = first_line(map, j);
	else if (j == len - 1)
		i = last_line(map, j);
	else
		i = middle_line(map, j);
	return (i);
}
