/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:12 by trebours          #+#    #+#             */
/*   Updated: 2024/11/05 12:03:12 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	stringisdigit(char *src)
{
	int	i;

	if (!src)
		return (false);
	i = 0;
	while (src[i])
	{
		if (!ft_isdigit(src[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_stringtab_len(char **src)
{
	int	i;
	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	loop_hexa(char **tmp, int *r, int *g, int *b)
{
	if (stringisdigit(tmp[0]))
		*r = ft_atoi(tmp[0]);
	if (stringisdigit(tmp[1]))
		*g = ft_atoi(tmp[1]);
	if (stringisdigit(tmp[2]))
		*b = ft_atoi(tmp[2]);
	if (*r == -1 || *g == -1 || *b == -1)
		return (1);
	if (*r > 255 || *g > 255 || *b > 255)
		return (1);
	return (0);
}

uint32_t	pasthexa(char *line, t_map *data, t_tmp *map)
{
	char	**tmp;
	int		r;
	int		g;
	int		b;

	if (!line)
		return (0);
	tmp = ft_split(&line[2], ',');
	if (!tmp || ft_stringtab_len(tmp) != 3)
	{
		if (!tmp)
			error_colors(line, 4, data, map);
		ft_free_stringtab(tmp);
		error_colors(line, 5, data, map);
	}
	r = -1;
	g = -1;
	b = -1;
	if (loop_hexa(tmp, &r, &g, &b))
		error_colors(line, 0, data, map);
	ft_free_stringtab(tmp);
	return ((r << 24) + ((g) << 16) + ((b << 8)) + 255);
}

TXT	*verif_png(char *png)
{
	int	i;
	TXT	*tmp;

	i = 0;
	while (png[i] == ' ')
		i++;
	if (png[i] == '\0')
		return (NULL); // messqge error
	tmp = mlx_load_png(&png[i]);
	if (!tmp)
		return (NULL); // messqge error
	return (tmp);
}

// a metre dans un autre fichier

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
