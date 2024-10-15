/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerrorpars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:19:55 by trebours          #+#    #+#             */
/*   Updated: 2024/09/18 12:18:38 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_file(char *file, int index)
{
	ft_putstr_fd(RED, 2);
	write(2, "Error\n", 6);
	if (index == 1)
	{
		write(STDERR_FILENO, "the file \"", 10);
		write(STDERR_FILENO, file, ft_strlen(file));
		write(STDERR_FILENO, "\" have a wrong format\n", 22);
	}
	if (index == 2)
		ft_putstr_fd("CUB3D must have file as argument\n", 2);
	ft_putstr_fd(WHITE, 2);
	exit(index);
}

void	error_player(int player, t_map *data)
{
	ft_putstr_fd(RED, 2);
	write(2, "Error\n", 6);
	ft_putstr_fd("There are ", 2);
	ft_putnbr_fd(player, 2);
	if (player > 1)
		ft_putstr_fd(" players but you only need one\n", 2);
	else
		ft_putstr_fd(" player but you need one\n", 2);
	ft_putstr_fd(WHITE, 2);
	free_struct(data);
	exit(3);
}

void	error_colors(char *line, int index, t_map *data, t_tmp *map)
{
	ft_putstr_fd(RED, 2);
	if (index == 4)
		ft_putstr_fd("Error\nError initialisation malloc\n", 2);
	else
	{
		ft_putstr_fd("Error\nThe line \"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\" is not valid\n", 2);
	}
	ft_putstr_fd(WHITE, 2);
	ft_tmpclear(&map, free);
	free_struct(data);
	free(line);
	exit(index);
}