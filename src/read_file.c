/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:49 by trebours          #+#    #+#             */
/*   Updated: 2024/08/28 15:50:20 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(char **src, t_map *data)
{
	char	*line;
	int		fd;
	int		i;
	t_test	*map;

	map = malloc(1 * sizeof(t_test));
	map->line_map = NULL;
	fd = open(src[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error\n");
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
	data->map = ft_test_to_tab(map);
	ft_testclear(&map, free);
	close(fd);
}
