/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/25 15:17:48 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	time_fps(t_map	*data)
{
	int save;
	save = (int)(1 / data->mlx->delta_time);
	mlx_put_string(data->mlx, ft_itoa(save), 0, 0);
	//printf("%d\n", save);
}

void	pause_game(t_map *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	data->pause = true;
	data->menu->enabled = true;
	data->cubd->enabled = true;
	data->img_play->enabled = true;
	data->img_option->enabled = true;
	data->img_edit->enabled = true;
	data->img_exit->enabled = true;
	data->game->move_w = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
}

void	exit_cub3d(t_map *data)
{
	mlx_close_window(data->mlx);
}

void	check_but_play(t_map *data)
{
	if (data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max)
	{
		data->idx_menu = 0;
		data->but_play->click = true;
	}
	if (data->game->cursor_x < data->but_play->but_x_min || data->game->cursor_x > data->but_play->but_x_max || data->game->cursor_y < data->but_play->but_y_min || data->game->cursor_y > data->but_play->but_y_max)
		data->but_play->good = false;
	if ((data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max && data->but_play->good == true ) || data->but_play->press_enter == true)
	{
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
		data->pause = false;
		data->idx_menu = 0;
		data->but_play->press_enter = false;
		data->but_play->good = false;
		data->menu->enabled = false;
		data->cubd->enabled = false;
		data->img_play->enabled = false;
		data->img_option->enabled = false;
		data->img_edit->enabled = false;
		data->img_exit->enabled = false;
		data->game->move_w = false;
		data->game->rotate_left = false;
		data->game->rotate_right = false;
		data->game->move_s = false;
		data->game->move_a = false;
		data->game->move_d = false;
	}
}

void	check_but_option(t_map *data)
{
	if (data->game->cursor_x > data->but_option->but_x_min && data->game->cursor_x < data->but_option->but_x_max && data->game->cursor_y > data->but_option->but_y_min && data->game->cursor_y < data->but_option->but_y_max)
	{
		data->idx_menu = 0;
		data->but_option->click = true;
	}	
	if (data->game->cursor_x < data->but_option->but_x_min || data->game->cursor_x > data->but_option->but_x_max || data->game->cursor_y < data->but_option->but_y_min || data->game->cursor_y > data->but_option->but_y_max)
		data->but_option->good = false;
}

void	check_but_edit(t_map *data)
{
	if (data->game->cursor_x > data->but_edit->but_x_min && data->game->cursor_x < data->but_edit->but_x_max && data->game->cursor_y > data->but_edit->but_y_min && data->game->cursor_y < data->but_edit->but_y_max)
	{
		data->idx_menu = 0;
		data->but_edit->click = true;
	}
	if (data->game->cursor_x < data->but_edit->but_x_min || data->game->cursor_x > data->but_edit->but_x_max || data->game->cursor_y < data->but_edit->but_y_min || data->game->cursor_y > data->but_edit->but_y_max)
		data->but_edit->good = false;
}

void	check_but_exit(t_map *data)
{
	if (data->game->cursor_x > data->but_exit->but_x_min && data->game->cursor_x < data->but_exit->but_x_max && data->game->cursor_y > data->but_exit->but_y_min && data->game->cursor_y < data->but_exit->but_y_max)
	{
		data->idx_menu = 0;
		data->but_exit->click = true;
	}
	if (data->game->cursor_x < data->but_exit->but_x_min || data->game->cursor_x > data->but_exit->but_x_max || data->game->cursor_y < data->but_exit->but_y_min || data->game->cursor_y > data->but_exit->but_y_max)
		data->but_exit->good = false;
	if ((data->game->cursor_x > data->but_exit->but_x_min && data->game->cursor_x < data->but_exit->but_x_max && data->game->cursor_y > data->but_exit->but_y_min && data->game->cursor_y < data->but_exit->but_y_max && data->but_exit->good == true) || data->but_exit->press_enter == true)
		exit_cub3d(data);
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (data->pause != true)
		raycasting(data);
	//time_fps(data);
	//mini(data);
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
	check_but_play(data);
	check_but_option(data);
	check_but_edit(data);
	check_but_exit(data);
	button_play(data);
	button_option(data);
	button_edit(data);
	button_exit(data);
}

void	move_w(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_x * data->speed;
	testy += data->game->dir_y * data->speed;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
	
}

void	move_s(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx -= data->game->dir_x * data->speed;
	testy -= data->game->dir_y * data->speed;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
}

void	move_a(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_y * data->speed;
	testy -= data->game->dir_x * data->speed;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
}

void	move_d(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx -= data->game->dir_y * data->speed;
	testy += data->game->dir_x * data->speed;
	if (data->map[(int)testy][(int)data->game->player_x] == '1')
	{
		if (data->map[(int)data->game->player_y][(int)testx] == '1')
			return;
		data->game->player_x = testx;
		return ;
	}
	data->game->player_y = testy;
	if (data->map[(int)data->game->player_y][(int)testx] == '1')
		return;
	data->game->player_x = testx;
}

void	rotate_left(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;

	olddri_x = map->game->dir_x;
	map->game->dir_x = map->game->dir_x * cos(-map->rotspeed) - map->game->dir_y * sin(-map->rotspeed);
	map->game->dir_y = olddri_x * sin(-map->rotspeed) + map->game->dir_y* cos(-map->rotspeed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x =  map->game->plane_x * cos(-map->rotspeed) -  map->game->plane_y * sin(-map->rotspeed);
	map->game->plane_y =  oldplane_x * sin(-map->rotspeed) +  map->game->plane_y * cos(-map->rotspeed);
}

void	rotate_right(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;

	olddri_x = map->game->dir_x;
	map->game->dir_x = map->game->dir_x * cos(map->rotspeed) - map->game->dir_y * sin(map->rotspeed);
	map->game->dir_y = olddri_x * sin(map->rotspeed) + map->game->dir_y * cos(map->rotspeed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x =  map->game->plane_x * cos(map->rotspeed) -  map->game->plane_y * sin(map->rotspeed);
	map->game->plane_y =  oldplane_x * sin(map->rotspeed) +  map->game->plane_y * cos(map->rotspeed);
}

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
		data->but_play->good = true;
		data->but_option->good = true;
		data->but_edit->good = true;
		data->but_exit->good = true;
	}
}

void	cursor(double xpos, double ypos, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (data->game->cursor_x < WINDOWSW / 2 - 5 && data->pause == false)
	{
		data->game->rotate_left = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2,  WINDOWSH /2);
	}
	else
		data->game->rotate_left = false;
	if (data->game->cursor_x > WINDOWSW / 2 + 5 && data->pause == false)
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
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			if (data->pause == true)
				mlx_close_window(data->mlx);
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
		}
		if (keydata.key == MLX_KEY_P && data->pause == false)
				data->plafond = !data->plafond;
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
