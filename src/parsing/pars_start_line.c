/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_start_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/08 11:33:27 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	verif(char *line, t_map *data, t_tmp *tmp)
{
	(void)data;
	if (line[0] == '\n')
		return (0);
	line[ft_strlen(line) - 1] = 0;
	if (!data->no && !ft_strncmp(line, "NO ", 3))
		data->no = verif_png(&line[3]);
	else if (!data->so && !ft_strncmp(line, "SO ", 3))
		data->so = verif_png(&line[3]);
	else if (!data->we && !ft_strncmp(line, "WE ", 3))
		data->we = verif_png(&line[3]);
	else if (!data->ea && !ft_strncmp(line, "EA ", 3))
		data->ea = verif_png(&line[3]);
	else if (!data->down && !ft_strncmp(line, "F ", 2))
		data->down = pasthexa(line, data, tmp);
	else if (!data->up && !ft_strncmp(line, "C ", 2))
		data->up = pasthexa(line, data, tmp);
	else
		print_error(line, data, tmp);
	return (1);
}

void	check_map(char *line, t_tmp **map, t_map *data)
{
	if (verif_start_line(line) || line[0] == '\n')
		print_error(line, data, *map);
	if (!(*map)->next && !ft_tmplen(*map))
	{
		(*map)->line_map = ft_strdup(line);
		(*map)->next = NULL;
		return ;
	}
	ft_tmpadd_back(map, ft_tmpnew(line));
}

int	parsing_line(char *line, t_map *data, int i, t_tmp *map)
{
	if (line == NULL)
		return (-1);
	if (i < 6)
		return (verif(line, data, map));
	if (i == 6 && line[0] == '\n')
		return (0);
	check_map(line, &map, data);
	return (1);
}
