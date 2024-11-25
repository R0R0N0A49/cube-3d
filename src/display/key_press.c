/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:08:14 by trebours          #+#    #+#             */
/*   Updated: 2024/11/19 11:16:21 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	key_release(t_map *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W)
		data->game->move_w = false;
	if (keydata.key == MLX_KEY_LEFT)
		data->game->rotate_left = false;
	if (keydata.key == MLX_KEY_RIGHT)
		data->game->rotate_right = false;
	if (keydata.key == MLX_KEY_S)
		data->game->move_s = false;
	if (keydata.key == MLX_KEY_A)
		data->game->move_a = false;
	if (keydata.key == MLX_KEY_D)
		data->game->move_d = false;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		if (keydata.key == MLX_KEY_W)
			data->game->move_w = true;
		if (keydata.key == MLX_KEY_S)
			data->game->move_s = true;
		if (keydata.key == MLX_KEY_A)
			data->game->move_a = true;
		if (keydata.key == MLX_KEY_D)
			data->game->move_d = true;
		if (keydata.key == MLX_KEY_LEFT)
			data->game->rotate_left = true;
		if (keydata.key == MLX_KEY_RIGHT)
			data->game->rotate_right = true;
	}
	if (keydata.action == MLX_RELEASE)
		key_release(data, keydata);
}
