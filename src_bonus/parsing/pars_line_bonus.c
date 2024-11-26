/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:12 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:10:01 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	int		i;

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
	i = loop_hexa(tmp, &r, &g, &b);
	ft_free_stringtab(tmp);
	if (i)
		error_colors(line, 0, data, map);
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
		return (NULL);
	tmp = mlx_load_png(&png[i]);
	if (!tmp)
		return (NULL);
	return (tmp);
}
