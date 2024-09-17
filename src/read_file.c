/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:49 by trebours          #+#    #+#             */
/*   Updated: 2024/09/17 12:21:16 by trebours         ###   ########.fr       */
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
	int		fd;
	int		i;
	t_tmp	*map;

	map = malloc(1 * sizeof(t_tmp));
	map->line_map = NULL;
	map->next = NULL;
	fd = open(src[1],  O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("error\nFile can't open\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i += parsing_line(line, data, i, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (ft_verif_first(data))
	{
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
