/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:37 by trebours          #+#    #+#             */
/*   Updated: 2024/09/02 16:12:10 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	print_charerror(char *line, int pos, int posline)
{
	ft_putstr_fd("Error\nwrong char at line ", STDERR_FILENO);
	ft_putnbr_fd(posline + 1, STDERR_FILENO);
	ft_putstr_fd(" at position ", STDERR_FILENO);
	ft_putnbr_fd(pos + 1, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	while (pos)
	{
		write (STDERR_FILENO, " ", 1);
		pos--;
	}
	write (STDERR_FILENO, "^\n", 2);
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
