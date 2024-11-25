/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:08:14 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:08:19 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

static void	key_first_part(t_map *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		key_esc(data);
	if (keydata.key == MLX_KEY_W && data->pause == false)
		data->game->move_w = true;
	if (keydata.key == MLX_KEY_S && data->pause == false)
		data->game->move_s = true;
	if (keydata.key == MLX_KEY_A && data->pause == false)
		data->game->move_a = true;
	if (keydata.key == MLX_KEY_D && data->pause == false)
		data->game->move_d = true;
	if (keydata.key == MLX_KEY_LEFT && (data->pause == false || \
				data->menu_option->visible))
		key_left_right(data, 1);
	if (keydata.key == MLX_KEY_RIGHT && (data->pause == false || \
				data->menu_option->visible))
		key_left_right(data, 0);
	if (keydata.key == MLX_KEY_DOWN && (data->pause == true || \
				data->menu_option->visible))
		key_down(data);
	if (keydata.key == MLX_KEY_UP && data->pause == true)
		key_up(data);
	if (keydata.key == MLX_KEY_ENTER && data->pause == true)
		key_enter(data);
}

static void	key_second_part(t_map *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_TAB && data->pause == false && \
				data->w_map <= 35 && data->h_map <= 25)
	{
		data->mini_iso->enabled ^= 1;
		data->weapon.center->enabled ^= 1;
		data->weapon.enable_anim ^= 1;
	}
	if (keydata.key == MLX_KEY_P && data->pause == false)
	{
		data->menu_option->night_mode ^= 1;
		data->ceiling = !data->ceiling;
	}
	if (keydata.key == MLX_KEY_F && data->pause == false)
		data->fog = !data->fog;
	if (keydata.key == MLX_KEY_K)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_Q)
	{
		data->weapon.enable_anim ^= 1;
		data->weapon.center->enabled ^= 1;
		data->weapon.selected[2]->enabled ^= 1;
		data->weapon.selected[data->weapon.index_weapon]->enabled ^= 1;
	}
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (keydata.action == MLX_PRESS)
	{
		fonts_update(data);
		key_first_part(data, keydata);
		key_second_part(data, keydata);
	}
	if (keydata.action == MLX_RELEASE)
		key_release(data, keydata);
}
