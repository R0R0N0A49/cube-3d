/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:37 by trebours          #+#    #+#             */
/*   Updated: 2024/08/28 10:58:03 by trebours         ###   ########.fr       */
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

void	print_error(char *line)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (verif_start_line(line))
	{
		ft_putstr_fd("repetition of the texture for ", STDERR_FILENO);
		write(STDERR_FILENO, line, 2);
	}
	else
		ft_putstr_fd("the first line should be texture and color",
			STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}
