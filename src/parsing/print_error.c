/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:37 by trebours          #+#    #+#             */
/*   Updated: 2024/09/18 15:17:06 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

	ft_putstr_fd("Error\nwrong char at line ", STDERR_FILENO);
	ft_putnbr_fd(posline + 1, STDERR_FILENO);
	ft_putstr_fd(" at position ", STDERR_FILENO);
	ft_putnbr_fd(pos + 1, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
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

void	print_error(char *line, t_map *data, t_tmp *map)
{
	int index;

	ft_putstr_fd(RED, STDERR_FILENO);
	write(STDERR_FILENO, "Error\n", 6);
	if (verif_start_line(line))
	{
		ft_putstr_fd("repetition of the texture for ", STDERR_FILENO);
		write(STDERR_FILENO, line, 2);
		index = 7;
	}
	else if (line[0] == '\n')
		index = write(STDERR_FILENO, "the map must not contain an empty line", 38) - 30;
	else
		index = write(STDERR_FILENO, "the first lines must be texture or color", 40) - 31;
	write(STDERR_FILENO, "\n", 1);
	ft_putstr_fd(WHITE, STDERR_FILENO);
	free(line);
	free_struct(data);
	ft_tmpclear(&map, free);
	exit(index);
}
