/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:37 by trebours          #+#    #+#             */
/*   Updated: 2024/09/05 16:29:56 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	print_charerror(char **line, int posline, int pos)
{
	int k;

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
	return (1);
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

void	print_error(char *line)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (verif_start_line(line))
	{
		ft_putstr_fd("repetition of the texture for ", STDERR_FILENO);
		write(STDERR_FILENO, line, 2);
	}
	else if (line[0] == '\n')
		ft_putstr_fd("the map must not contain an empty line", STDERR_FILENO);
	else
		ft_putstr_fd("the first line should be texture and color",
			STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}
