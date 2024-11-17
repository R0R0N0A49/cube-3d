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

void	init_struct(char **src, t_map *data)
{
	char	*line;
	int		i;
	t_tmp	*map;

	map = malloc(1 * sizeof(t_tmp));
	map->line_map = NULL;
	map->next = NULL;
	data->file = open(src[1], O_RDONLY);
	if (data->file < 0)
	{
		ft_putstr_fd("error\nFile can't open\n", 2);
		exit(1);
	}
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
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("error\nfile empty\n", 2);
		ft_tmpclear(&map, free);
		exit (free_struct(data));
	}
	data->map = ft_tmp_to_tab(map);
	data->len_map = ft_tmplen(map);
	ft_tmpclear(&map, free);
	i = verif_char(data);
	if (i)
	{
		free_struct(data);
		exit(1);
	// printf msg error
	// fonction pour free et exit
	}
}
