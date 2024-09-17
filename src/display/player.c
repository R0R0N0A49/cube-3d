/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/17 16:50:42 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	time_fps(t_map	*data)
{
	//mlx_put_string(data->mlx, ft_itoa((int)(1 / data->mlx->delta_time)), 0, 0);
	printf("%d\n", (int)(1 / data->mlx->delta_time));
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	time_fps(data);
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
	//printf("pos_y = %f, pos_x = %f\n", data->game->player_y, data->game->player_x);
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
		return;
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
		return;
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
		return;
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
		return;
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

void	cursor(double xpos, double ypos, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (data->game->cursor_x < WINDOWSW / 2)
	{
		data->game->rotate_left = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, ypos);
	}
	else
		data->game->rotate_left = false;
	if (data->game->cursor_x > WINDOWSW / 2)
	{
		data->game->rotate_right = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, ypos);
	}
	else
		data->game->rotate_right = false;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	

	map = (t_map *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(map->mlx);
		if (keydata.key == MLX_KEY_W)
			map->game->move_w = true;
		if (keydata.key == MLX_KEY_S)
			map->game->move_s = true;
		if (keydata.key == MLX_KEY_A)
			map->game->move_a = true;
		if (keydata.key == MLX_KEY_D)
			map->game->move_d = true;
		if (keydata.key == MLX_KEY_LEFT)
			map->game->rotate_left = true;
		if (keydata.key == MLX_KEY_RIGHT)
			map->game->rotate_right = true;
		
	}
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			map->game->move_w = false;
		if (keydata.key == MLX_KEY_LEFT)
			map->game->rotate_left = false;
		if (keydata.key == MLX_KEY_RIGHT)
			map->game->rotate_right = false;
		if (keydata.key == MLX_KEY_S)
			map->game->move_s = false;
		if (keydata.key == MLX_KEY_A)
			map->game->move_a = false;
		if (keydata.key == MLX_KEY_D)
			map->game->move_d = false;
	}
}
