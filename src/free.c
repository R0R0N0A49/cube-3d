/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/08/29 09:52:52 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_free_stringtab(char **src)
{
	int i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

void	free_struct(t_map *data)
{
	if (data->no)
		mlx_delete_texture(data->no);
	if (data->so)
		mlx_delete_texture(data->so);
	if (data->ea)
		mlx_delete_texture(data->ea);
	if (data->we)
		mlx_delete_texture(data->we);
	if (data->down)
		free(data->down);
	if (data->up)
		free(data->up);
	if (data->map)
		ft_free_stringtab(data->map);
}
