/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:37 by trebours          #+#    #+#             */
/*   Updated: 2024/08/27 16:24:04 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_error(char *line)
{
	if (!ft_strncmp(line, "NO ", 3)) // a remplacer par une fonction qui test nord sud est oest up down
		ft_printf("Error\nrepetition de la ligne : %s", line);
	else
		ft_printf("Error\nles premiere ligne doivent etre les texture et "
		 		"les couleur\n", line);
}
