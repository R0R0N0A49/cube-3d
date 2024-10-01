/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:45:36 by derey             #+#    #+#             */
/*   Updated: 2024/09/29 18:21:39 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fonts_disabled(t_map *data)
{
	int		i;
	size_t	x;

	x = 0;
	i = 0;
	while (i < 10)
	{
		while (x <= data->font.image[i]->count)
			data->font.image[i]->instances[x++].enabled = false;
		x = 0;
		i++;
	}
}

int	fonts_enabled(t_map *data, int cc, int i, char *str)
{
	while (str[cc] != '\0')
	{
		if (str[cc] == '0')
			data->font.image[0]->instances[i++].enabled = true;
		else if (str[cc] == '1')
			data->font.image[1]->instances[i++].enabled = true;
		else if (str[cc] == '2')
			data->font.image[2]->instances[i++].enabled = true;
		else if (str[cc] == '3')
			data->font.image[3]->instances[i++].enabled = true;
		else if (str[cc] == '4')
			data->font.image[4]->instances[i++].enabled = true;
		else if (str[cc] == '5')
			data->font.image[5]->instances[i++].enabled = true;
		else if (str[cc] == '6')
			data->font.image[6]->instances[i++].enabled = true;
		else if (str[cc] == '7')
			data->font.image[7]->instances[i++].enabled = true;
		else if (str[cc] == '8')
			data->font.image[8]->instances[i++].enabled = true;
		else if (str[cc] == '9')
			data->font.image[9]->instances[i++].enabled = true;
		cc++;
	}
	return (cc);
}

void	fonts_init(t_map *data)
{
	int		x;
	int		i;

	x = 0;
	while (x < 16)
	{
		i = 0;
		while (i < 10)
			mlx_image_to_window(data->mlx, data->font.image[i++], 16 + (x * 32), 0);
		x++;
	}
	fonts_disabled(data);
}

void	fonts_update(t_map *data)
{
	int		pp;

	pp = 0;
	if (data->menu_option->display_fps)
	{
		data->ifps = ft_itoa(data->fps);
		fonts_disabled(data);
		pp = fonts_enabled(data, pp, pp, data->ifps);
		free(data->ifps);
	}
}