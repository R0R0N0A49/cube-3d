/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:12 by trebours          #+#    #+#             */
/*   Updated: 2024/08/22 13:11:33 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	verif(char *line, t_map *data)
{
	(void)data;
	if (line[0] == '\n')
		return (0);
	if (!data->nord && !ft_strncmp(line, "NO ", 3))
		data->nord = ft_strdup(line);
	else if (!data->sud && !ft_strncmp(line, "SO ", 3))
		data->sud = ft_strdup(line);
	else if (!data->oest && !ft_strncmp(line, "WE ", 3))
		data->oest = ft_strdup(line);
	else if (!data->est && !ft_strncmp(line, "EA ", 3))
		data->est = ft_strdup(line);
	else if (!data->down && !ft_strncmp(line, "F ", 2))
		data->down = ft_strdup(line);
	else if (!data->up && !ft_strncmp(line, "C ", 2))
		data->up = ft_strdup(line);
	else
	{
		free_struct(data);
		print_error(line);
		free(line);
		exit(1);
	}
	return (1);
}

void	parsing_line(char *line, t_map *data)
{
	static int	i = 0;

	if (i < 6)
		i += verif(line, data);
}
