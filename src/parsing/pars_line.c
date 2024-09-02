/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:12 by trebours          #+#    #+#             */
/*   Updated: 2024/09/02 11:06:56 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	verif(char *line, t_map *data)
{
	(void)data;
	if (line[0] == '\n')
		return (0);
	line[ft_strlen(line) - 1] = 0;
	if (!data->no && !ft_strncmp(line, "NO ", 3))
		data->no = mlx_load_png(&line[3]);
	else if (!data->so && !ft_strncmp(line, "SO ", 3))
		data->so = mlx_load_png(&line[3]);
	else if (!data->we && !ft_strncmp(line, "WE ", 3))
		data->we = mlx_load_png(&line[3]);
	else if (!data->ea && !ft_strncmp(line, "EA ", 3))
		data->ea = mlx_load_png(&line[3]);
	else if (!data->down && !ft_strncmp(line, "F ", 2))
		data->down = ft_strdup(&line[2]);
	else if (!data->up && !ft_strncmp(line, "C ", 2))
		data->up = ft_strdup(&line[2]);
	else
	{
		free_struct(data);
		print_error(line);
		free(line);
		exit(1);
	}
	return (1);
}

void	check_map(char *line, t_test **map, t_map *data)
{
	t_test *tmp;

	if (verif_start_line(line))
	{
		print_error(line);
		free_struct(data);
		if (map)
			ft_testclear(map, free);
		exit(1);
	}
	if (!map[0] || !testlen(map[0]))
	{
		(*map)->line_map = ft_strdup(line);
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_testnew(line);
}

int	parsing_line(char *line, t_map *data, int i, t_test *map)
{
	if (line[0] == '\n')
		return (0);
	if (i < 6)
		return (verif(line, data));
	check_map(line, &map, data);
	return (0);
}
