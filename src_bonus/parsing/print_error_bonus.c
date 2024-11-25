/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:37 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:10:08 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	error_pline(char *line, int j, int i, int k)
{
	int	l;

	l = 0;
	while (line[l])
	{
		if (line[l] == '2')
			ft_putchar_fd(' ', STDERR_FILENO);
		else if (k == j && l == i)
		{
			ft_putstr("\033[1;31m", STDERR_FILENO);
			ft_putchar_fd(line[l], STDERR_FILENO);
			ft_putstr("\033[1;m", STDERR_FILENO);
		}
		else
			ft_putchar_fd(line[l], STDERR_FILENO);
		l++;
	}
}

int	print_charerror(char **line, int posline, int pos, t_map *data)
{
	int	k;

	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("Error\nwrong char or placement at line ", STDERR_FILENO);
	ft_putnbr_fd(posline + 1, STDERR_FILENO);
	ft_putstr_fd(" at position ", STDERR_FILENO);
	ft_putnbr_fd(pos + 1, STDERR_FILENO);
	ft_putstr_fd("\n\n", STDERR_FILENO);
	ft_putstr_fd(WHITE, STDERR_FILENO);
	k = -1;
	while (k++ < posline)
		error_pline(line[k], posline, pos, k);
	while (pos)
	{
		ft_putstr_fd(" ", STDERR_FILENO);
		pos--;
	}
	ft_putstr_fd("\033[1;31m^\n\033[1;m", STDERR_FILENO);
	free_struct(data);
	return (10);
}

int	verif_start_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

static int	verif_line(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
	{
		if (line[2] != ' ')
			return (1);
	}
	return (0);
}

void	print_error(char *line, t_map *data, t_tmp *map)
{
	int	index;

	ft_putstr_fd("\033[1;31mError\n", STDERR_FILENO);
	if (verif_start_line(line))
	{
		index = write(STDERR_FILENO, "repetition of the texture for ", 30);
		ft_putstr_fd(line, STDERR_FILENO);
	}
	else if (line[0] == '\n')
		index = write(STDERR_FILENO, "the map must not contain an"
				" empty line", 39) - 31;
	else if (verif_line(line))
	{
		index = write(STDERR_FILENO, "no information behind ", 22);
		write(STDERR_FILENO, line, ft_strlen(line));
	}
	else
		index = write(STDERR_FILENO, "the first lines must be tex"
				"ture or color", 41) - 32;
	ft_putstr_fd("\033[1;m\n", STDERR_FILENO);
	free(line);
	free_struct(data);
	ft_tmpclear(&map, free);
	exit(index);
}
