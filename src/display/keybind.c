/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:04 by derey             #+#    #+#             */
/*   Updated: 2024/09/28 17:20:23 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	(void)mods;

	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		data->idx_menu = 0;
		data->press = true;
	}
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE)
	{
		data->press = false;
		if (data->menu->enabled)
		{
			data->but_play->good = true;
			data->but_option->good = true;
			data->but_edit->good = true;
			data->but_exit->good = true;
		}
		if (data->opt->option)
		{
			data->opt->but_rtn->good = true;
			data->opt->but_music->good = true;
			data->opt->but_fov->good = true;
			data->opt->but_floor->good = true;
			data->opt->but_roof->good = true;
		}
		if (data->edit->enabled)
		{
			data->opt->but_rtn->good = true;
		}
	}
}

void	cursor(double xpos, double ypos, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (xpos < WINDOWSW / 2 - 5 && data->pause == false)
	{
		data->game->rotate_left = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2,  WINDOWSH /2);
	}
	else
		data->game->rotate_left = false;
	if (xpos > WINDOWSW / 2 + 5 && data->pause == false)
	{
		data->game->rotate_right = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2,  WINDOWSH /2);
	}
	else
		data->game->rotate_right = false;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (data->edit->enabled == true && keydata.action == MLX_RELEASE && data->editor->good == true)
	{
		recup_str(data, keydata);
	}
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			if (data->pause == true && !data->opt->option && !data->editor->edit)
				play(data);
			else if (data->opt->option)
				data->opt->but_rtn->press_enter = true;
			else
				pause_game(data);
		}
		if (keydata.key == MLX_KEY_W && data->pause == false)
			data->game->move_w = true;
		if (keydata.key == MLX_KEY_S && data->pause == false)
			data->game->move_s = true;
		if (keydata.key == MLX_KEY_A && data->pause == false)
			data->game->move_a = true;
		if (keydata.key == MLX_KEY_D && data->pause == false)
			data->game->move_d = true;
		if (keydata.key == MLX_KEY_K)
			mlx_close_window(data->mlx);
		if (keydata.key == MLX_KEY_LEFT && data->pause == false)
			data->game->rotate_left = true;
		if (keydata.key == MLX_KEY_RIGHT && data->pause == false)
			data->game->rotate_right = true;
		if (keydata.key == MLX_KEY_DOWN && data->pause == true)
		{
			if (data->idx_menu >= 4)
				data->idx_menu = 1;
			else
				data->idx_menu++;
		}
		if (keydata.key == MLX_KEY_UP && data->pause == true)
		{
			if (data->idx_menu > 1)
				data->idx_menu--;
			else
				data->idx_menu = 4;
		}
		if (keydata.key == MLX_KEY_ENTER && data->pause == true)
		{
			if (data->idx_menu == 1)
				data->but_play->press_enter = true;
			if (data->idx_menu == 2)
				data->but_option->press_enter = true;
			if (data->idx_menu == 3)
				data->but_edit->press_enter = true;
			if (data->idx_menu == 4)
				data->but_exit->press_enter = true;
			printf("%s\n", data->editor->name);
		}
		if (keydata.key == MLX_KEY_P && data->pause == false)
				data->plafond = !data->plafond;
		if (keydata.key == MLX_KEY_F && data->pause == false)
				data->fog = !data->fog;
	}
	if (keydata.action == MLX_RELEASE)
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
}