/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/08/30 14:37:12 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
//int get_ten()
//{
//
//}

//void	key_press(mlx_key_data_t keydata, void *param)
//{
//	t_map	*data;
//
//	(void)keydata;
//	data = param;
//	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
//		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
//		mlx_close_window(data->mlx);
//	if ((mlx_is_key_down(data->mlx, MLX_KEY_W)
//		 || mlx_is_key_down(data->mlx, MLX_KEY_UP)))
//		high(data);
//	if ((mlx_is_key_down(data->mlx, MLX_KEY_S)
//		 || mlx_is_key_down(data->mlx, MLX_KEY_DOWN)))
//		botom(data);
//	if ((mlx_is_key_down(data->mlx, MLX_KEY_D)
//		 || mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)))
//		right(data);
//	if ((mlx_is_key_down(data->mlx, MLX_KEY_A)
//		 || mlx_is_key_down(data->mlx, MLX_KEY_LEFT)))
//		left(data);
//}

void	mini_map(t_map *data, mlx_t *mlx)
{
	int i;
	int j = 0;
	int len = 15;

	(void)mlx;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1')
				mlx_image_to_window(data->mlx, data->mini_map->red, i * len, j * len);
			if (data->map[j][i] == '0')
				mlx_image_to_window(data->mlx, data->mini_map->white, i * len, j * len);
			if (data->map[j][i] == 'N') {
				mlx_image_to_window(data->mlx, data->mini_map->white, i * len, j * len);
				data->game->triangle_x = (i * len) + (len / 2 + len % 2);
				data->game->triangle_y = j * len;
			}
			i++;
		}
		j++;
	}
}
