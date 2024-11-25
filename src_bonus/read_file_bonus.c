/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:49 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 16:44:27 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_verif_first(t_map *data)
{
	if (!data->ea)
		return (true);
	if (!data->we)
		return (true);
	if (!data->no)
		return (true);
	if (!data->so)
		return (true);
	if (!data->down)
		return (true);
	if (!data->up)
		return (true);
	return (false);
}

static void	error(t_map *data, t_tmp *tmp, char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(WHITE, 2);
	if (tmp != NULL)
		ft_tmpclear(&tmp, free);
	if (data != NULL)
		free_struct(data);
	exit (1);
}

static void	init_tmp(t_map *data, t_tmp **map, char *src)
{
	map[0] = malloc(1 * sizeof(t_tmp));
	map[0]->line_map = NULL;
	map[0]->next = NULL;
	data->file = open(src, O_RDONLY);
	if (data->file < 0)
		error(NULL, NULL, "File can't open\n");
}

void	init_struct(char **src, t_map *data)
{
	char	*line;
	int		i;
	t_tmp	*map;

	map = NULL;
	init_tmp(data, &map, src[1]);
	line = get_next_line(data->file);
	i = 0;
	while (line)
	{
		i += parsing_line(line, data, i, map);
		free(line);
		line = get_next_line(data->file);
	}
	close(data->file);
	data->file = -1;
	if (ft_verif_first(data))
		error(data, map, "empty file or image cannot be opened\n");
	data->map = ft_tmp_to_tab(map);
	data->len_map = ft_tmplen(map);
	ft_tmpclear(&map, free);
	i = verif_char(data);
	if (i)
		error(data, NULL, "An error occurred while retrieving the file's " \
		" content\n");
}
