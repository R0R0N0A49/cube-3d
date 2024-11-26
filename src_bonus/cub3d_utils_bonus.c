/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:59:34 by trebours          #+#    #+#             */
/*   Updated: 2024/11/26 09:29:20 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_null(t_map *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->down = 0;
	data->up = 0;
	data->file = -1;
	data->map = NULL;
}

void	ft_free_stringtab(char **src)
{
	int	i;

	i = 0;
	if (!src[0] || !src[0][0])
		return ;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

int	free_struct(t_map *data)
{
	if (data->no)
		mlx_delete_texture(data->no);
	if (data->so)
		mlx_delete_texture(data->so);
	if (data->ea)
		mlx_delete_texture(data->ea);
	if (data->we)
		mlx_delete_texture(data->we);
	if (data->map)
		ft_free_stringtab(data->map);
	if (data->file != -1)
	{
		close(data->file);
		data->file = -1;
	}
	return (1);
}

void	verif_option(t_opt *option)
{
	option->valid->instances[0].enabled = option->play_music;
	option->unvalid->instances[0].enabled = !option->play_music;
	option->valid->instances[1].enabled = option->display_map;
	option->unvalid->instances[1].enabled = !option->display_map;
	option->valid->instances[2].enabled = option->display_fps;
	option->unvalid->instances[2].enabled = !option->display_fps;
	option->valid->instances[3].enabled = option->night_mode;
	option->unvalid->instances[3].enabled = !option->night_mode;
}

void	len_map(t_map *data)
{
	int	x;
	int	y;
	int	save;

	save = 0;
	x = 0;
	y = 0;
	data->h_map = 0;
	data->w_map = 0;
	data->h_map = (int)ft_strlen_w(data->map);
	while (y < data->h_map)
	{
		x = (int)ft_strlen(data->map[y]);
		if (x > save)
			save = x;
		y++;
	}
	data->w_map = save;
}
