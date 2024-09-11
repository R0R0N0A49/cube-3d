/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:12 by trebours          #+#    #+#             */
/*   Updated: 2024/09/11 12:16:43 by trebours         ###   ########.fr       */
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

char *gethexa(char **src)
{
	char	*rsl;
	int		nmb;
	char	*base = "0123456789ABCDEF";

	nmb = ft_atoi(*src);
	if (nmb > 255 || nmb < 0)
		return (NULL);
	rsl = ft_calloc(3, sizeof(char));
	rsl[0] = base[(nmb / 16) % 16];
	rsl[1] = base[nmb % 16];
	free(*src);
	*src = ft_strdup(rsl);
	free(rsl);
	return (*src);
}

char *pasthexa(char *line)
{
	char	*rsl;
	char	*tmprsl;
	char	**tmp;
	int		i;

	if (!line)
		return (NULL);
	tmp = ft_split(&line[2], ',');
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && stringisdigit(tmp[i]))
		i++;
	if (tmp[i] != NULL)
		exit(1);
	i = 0;
	rsl = ft_strdup("0x");
	while (tmp[i])
	{
		tmprsl = ft_strdup(rsl);
		free(rsl);
		rsl = ft_strjoin(tmprsl, gethexa(&tmp[i]));
		free(tmp[i]);
		free(tmprsl);
		i++;
	}
	tmprsl = ft_strdup(rsl);
	free(rsl);
	rsl = ft_strjoin(tmprsl, "FF");
	free(tmprsl);
	if (ft_strlen(rsl) > 10)
		return (NULL);
	free(tmp);
	return (rsl);

}

TXT	*verif_png(char *png)
{
	int	i;
	TXT	*tmp;

	i = 0;
	while (png[i] == ' ')
		i++;
	if (png[i] == '\0')
		return (NULL);
	tmp = mlx_load_png(&png[i]);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static int	verif(char *line, t_map *data)
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
		data->down = pasthexa(line);
	else if (!data->up && !ft_strncmp(line, "C ", 2))
		data->up = pasthexa(line);
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
	if (verif_start_line(line) || line[0] == '\n')
	{
		print_error(line);
		free_struct(data);
		free(line);
		if (map)
			ft_testclear(map, free);
		exit(1);
	}
	if (!(*map)->next && !testlen(*map))
	{
		(*map)->line_map = ft_strdup(line);
		(*map)->next = NULL;
		return ;
	}
	ft_lstadd_back(map, ft_testnew(line));
}

int	parsing_line(char *line, t_map *data, int i, t_test *map)
{
	if (line == NULL)
		return (-1);
	if (i < 6)
		return (verif(line, data));
	if (i == 6 && line[0] == '\n')
		return (0);
	check_map(line, &map, data);
	return (1);
}
