/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/20 16:51:02 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	time_fps(t_map	*data)
{
	printf("%d\n", (int)(1 / data->mlx->delta_time));
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	//time_fps(data);
	raycasting(data);
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
	/*if (data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max)
		data->pause = false;*/
	if (data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max && data->press == true)
		data->but_play->click = true;
	if (data->game->cursor_x > data->but_play->but_x_min && data->game->cursor_x < data->but_play->but_x_max && data->game->cursor_y > data->but_play->but_y_min && data->game->cursor_y < data->but_play->but_y_max && data->good == true)
	{
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
		data->pause = false;
		data->good = false;
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
	button_play(data);
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
		data->press = true;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE)
	{
		data->press = false;
		data->good = true;
	}
}

void	cursor(double xpos, double ypos, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (data->game->cursor_x < WINDOWSW / 2 - 200 && data->pause == false)
	{
		data->game->rotate_left = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, ypos);
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, WINDOWSH /2);
	}
	else
		data->game->rotate_left = false;
	if (data->game->cursor_x > WINDOWSW / 2 + 200 && data->pause == false)
	{
		data->game->rotate_right = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, ypos);
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, WINDOWSH /2);
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
			mlx_close_window(data->mlx);
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
		if (keydata.key == MLX_KEY_P)
		{
			if (data->menu->enabled == true)
			{
				mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
				data->pause = false;
				data->menu->enabled = false;
				data->cubd->enabled = false;
				data->img_play->enabled = false;
				data->img_option->enabled = false;
				data->img_edit->enabled = false;
				data->img_exit->enabled = false;
			}
			else if (data->menu->enabled == false)
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
		}
	}
	if (keydata.action == MLX_RELEASE && data->pause == false)
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
