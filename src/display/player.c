/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 18:51:11 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	time_fps(t_map	*data)
{
	double	time_dif;

	time_dif = difftime(time(NULL), data->time_fps);
	if (time_dif >= 1)
	{
		data->fps = (int)(1 / data->mlx->delta_time);
		data->time_fps = time(NULL);
	}
}

int	get_pc(int value, int size, int max)
{
	return ((size * value) / max);
}

void	pause_game(t_map *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	data->weapon.selected[2]->enabled = false;
	data->weapon.selected[data->weapon.index_weapon]->enabled = false;
	data->pause = true;
	data->menu->enabled = true;
	data->cubd->enabled = true;
	data->img_play->enabled = true;
	data->img_option->enabled = true;
	data->img_exit->enabled = true;
	data->game->move_w = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->weapon.enable_anim = false;
	choose_weapon(data);
	data->weapon.center->enabled = false;
}

void	exit_cub3d(t_map *data)
{
	mlx_close_window(data->mlx);
}

void	play_game(t_map *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	data->weapon.selected[2]->enabled = true;
	data->weapon.selected[data->weapon.index_weapon]->enabled = true;
	data->pause = false;
	data->idx_menu = 0;
	data->but_play->press_enter = false;
	data->but_play->good = false;
	data->menu->enabled = false;
	data->cubd->enabled = false;
	data->img_play->enabled = false;
	data->img_option->enabled = false;
	data->img_exit->enabled = false;
	data->game->move_w = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->but_play->good = false;
	data->but_option->good = false;
	data->but_exit->good = false;
	data->menu_option->but_rtn->good = false;
	data->weapon.enable_anim = true;
	data->weapon.center->enabled = true;
}


void	check_music(t_map *data)
{
	static int is_play = 0;
	int i;

	if ((!is_play || is_play == 1) && data->menu_option->play_music && data->pause)
	{
		if (is_play)
			i = system("killall paplay");
		i = system("paplay Music/Menu.wav &");
		is_play = 2;
	}
	else if ((!is_play || is_play == 2) && data->menu_option->play_music && !data->pause)
	{
		if (is_play)
			i = system("killall paplay");
		i = system("paplay ./Music/InGame.wav &");
		is_play = 1;
	}
	else if (is_play && !data->menu_option->play_music)
	{
		i = system("killall paplay &");
		is_play = 0;
	}
	(void)i;
}

void	check_door_open(t_map	*data)
{
	int	i;

	i = 0;
	while (i < data->nmb_door)
	{
		if (data->door[i].isopen)
		{
			if (ft_abs(data->door[i].map_x - (int)data->game->player_x) > 2)
			{
				data->door[i].isopen = false;
				data->door[i].index = 0;
			}
			if (ft_abs(data->door[i].map_y - (int)data->game->player_y) > 2)
			{
				data->door[i].isopen = false;
				data->door[i].index = 0;
			}
		}
		i++;
	}
	
}

void	loop_button(t_map *data)
{
	if (data->menu->enabled)
	{
		check_but_play(data);
		check_but_option(data);
		check_but_exit(data);
		button_play(data);
		button_option(data);
		button_exit(data);
	}
	if (data->menu_option->visible)
	{
		check_but_rtn(data);
		check_but_music(data);
		check_but_map(data);
		check_but_fps(data);
		check_but_night(data);
		button_rtn(data->menu_option);
		button_music(data->menu_option);
		button_map(data->menu_option);
		button_fps(data);
		button_night(data->menu_option);
	}
}

void	loop_moove(t_map *data)
{
	if (data->game->move_w)
		move_w(data);
	if (data->game->move_s)
		move_s(data);
	if (data->game->move_a)
		move_a(data);
	if (data->game->move_d)
		move_d(data);
	if (data->game->rotate_left)
		rotate_left(data);
	if (data->game->rotate_right)
		rotate_right(data);
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (data->pause != true)
	{
		raycasting(data);
		choose_weapon(data);
	}
	time_fps(data);
	if (data->menu_option->display_map)
		mini(data);
	loop_moove(data);
	loop_button(data);
	check_music(data);
	fonts_update(data);
	check_door_open(data);
}

int check_open(t_map *data, int x, int y)
{
	if (data->map[y][x] == 'D')
	{
		if (data->door[index_door(data->door, data->nmb_door, x, y)].isopen)
			return (0);
		return (1);
	}
	return (0);
}

void	mouse_left_r(t_map	*data)
{
	data->press = false;
	if (data->menu->enabled)
	{
		data->but_play->good = true;
		data->but_option->good = true;
		data->but_exit->good = true;
	}
	if (data->menu_option->visible)
	{
		data->menu_option->but_rtn->good = true;
		data->menu_option->but_music->good = true;
		data->menu_option->but_map->good = true;
		data->menu_option->but_fps->good = true;
		data->menu_option->but_night->good = true;
	}
}

void	mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		if (data->pause)
		{
			data->idx_menu = 0;
			data->press = true;
		}
	}
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE)
		mouse_left_r(data);
}

void	cursor(double xpos, double ypos, void *param)
{
	t_map	*data;

	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;

	if (data->pause == false)
	{
		
		mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	}
}


void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*data;
	

	data = (t_map *)param;
	if (keydata.action == MLX_PRESS)
	{
		fonts_update(data);
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			if (data->pause == true && !data->menu_option->visible)
				play_game(data);
			else if (data->menu_option->visible)
				data->menu_option->but_rtn->press_enter = true;
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
		if (keydata.key == MLX_KEY_LEFT && (data->pause == false || data->menu_option->visible))
		{
			if (!data->pause)
				data->game->rotate_left = true;
			else
			{
				if (data->menu_option->index > 1)
					data->menu_option->index = data->menu_option->index - 1;
				else
					data->menu_option->index = 4;
			}
		}
		if (keydata.key == MLX_KEY_RIGHT && (data->pause == false || data->menu_option->visible))
		{
			if (!data->menu_option->visible)
				data->game->rotate_right = true;
			else
			{
				if (data->menu_option->index >= 4)
					data->menu_option->index = 1;
				else
					data->menu_option->index++;
			}
		}
		if (keydata.key == MLX_KEY_DOWN && (data->pause == true || data->menu_option->visible))
		{
			if (!data->menu_option->visible)
			{
				if (data->idx_menu >= 3)
					data->idx_menu = 1;
				else
					data->idx_menu++;
			}
			else
			{
				if (data->menu_option->index == 3)
					data->menu_option->index--;
				else if (data->menu_option->index > 0)
					data->menu_option->index = (data->menu_option->index + 2) % 5;
				else
					data->menu_option->index = 1;
			}
		}
		if (keydata.key == MLX_KEY_UP && data->pause == true)
		{
			if (data->menu->enabled)
			{
				if (data->idx_menu > 1)
					data->idx_menu--;
				else
					data->idx_menu = 3;
			}
			else if (data->menu_option->visible)
			{
				if (data->menu_option->index == 1)
					data->menu_option->index = 4;
				else if (data->menu_option->index == 2)
					data->menu_option->index = 3;
				else if (data->menu_option->index > 0)
					data->menu_option->index = (data->menu_option->index - 2) % 5;
				else
					data->menu_option->index = 1;
			}
		}
		if (keydata.key == MLX_KEY_ENTER && data->pause == true)
		{
			if (data->idx_menu == 1)
				data->but_play->press_enter = true;
			if (data->idx_menu == 2)
				data->but_option->press_enter = true;
			if (data->idx_menu == 3)
				data->but_exit->press_enter = true;
			if (data->menu_option->index == 1)
				data->menu_option->but_music->press_enter = true;
			if (data->menu_option->index == 2)
				data->menu_option->but_map->press_enter = true;
			if (data->menu_option->index == 3)
				data->menu_option->but_fps->press_enter = true;
			if (data->menu_option->index == 4)
				data->menu_option->but_night->press_enter = true;
		}
		if (keydata.key == MLX_KEY_TAB && data->pause == false && data->w_map <= 35 && data->h_map <= 25)
			{
				data->mini_iso->enabled = !data->mini_iso->enabled;
				data->weapon.center->enabled = !data->weapon.center->enabled;
				data->weapon.enable_anim = !data->weapon.enable_anim;
			}
		if (keydata.key == MLX_KEY_P && data->pause == false)
		{
			data->menu_option->night_mode = !data->menu_option->night_mode;
			data->ceiling = !data->ceiling;
		}
		if (keydata.key == MLX_KEY_F && data->pause == false)
				data->fog = !data->fog;
		if (keydata.key == MLX_KEY_K)
			mlx_close_window(data->mlx);
		if (keydata.key == MLX_KEY_Q) {
			data->weapon.enable_anim = !data->weapon.enable_anim;
			data->weapon.center->enabled = !data->weapon.center->enabled;
			data->weapon.selected[2]->enabled = !data->weapon.selected[2]->enabled;
			data->weapon.selected[data->weapon.index_weapon]->enabled = !data->weapon.selected[data->weapon.index_weapon]->enabled;
		}
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

void	scroll(double i, double y, void *param)
{
	t_map *data;

	(void)i;
	(void)y;
	data = (t_map *)param;
	if (!data->pause && data->weapon.nb_availed_weapon == 2)
	{
		data->weapon.selected[data->weapon.index_weapon]->enabled = false;
		data->weapon.index_weapon = !data->weapon.index_weapon;
		data->weapon.selected[data->weapon.index_weapon]->enabled = true;
	}
}