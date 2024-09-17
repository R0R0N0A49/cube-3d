/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/17 11:22:11 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	clean_frame(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WINDOWSW)
	{
		while (x < WINDOWSH)
		{
			mlx_put_pixel(data->rayc, y, x, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	clean_frame(data);
	raycasting(data);
	clean_frame(data);
	mini(data);
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
	printf("pos_y = %f, pos_x = %f\n", data->game->player_y, data->game->player_x);
}

void	move_w(t_map *data)
{
	int testx;
	int testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_x * speed;
	testy += data->game->dir_y * speed;
	if (data->map[testy][testx] == '1')
		return;
	data->game->player_x += data->game->dir_x * speed;
	data->game->player_y += data->game->dir_y * speed;
}

void	move_s(t_map *data)
{
	int testx;
	int testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx -= data->game->dir_x * speed;
	testy -= data->game->dir_y * speed;
	if (data->map[testy][testx] == '1')
		return;
	data->game->player_x -= data->game->dir_x * speed;
	data->game->player_y -= data->game->dir_y * speed;
}

void	move_a(t_map *data)
{
	int testx;
	int testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_y * speed;
	testy -= data->game->dir_x * speed;
	if (data->map[testy][testx] == '1')
		return;
	data->game->player_x += data->game->dir_y * speed;
	data->game->player_y -= data->game->dir_x * speed;
}

void	move_d(t_map *data)
{
	int testx;
	int testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx -= data->game->dir_y * speed;
	testy += data->game->dir_x * speed;
	if (data->map[testy][testx] == '1')
		return;
	data->game->player_x -= data->game->dir_y * speed;
	data->game->player_y += data->game->dir_x * speed;
}

void	rotate_left(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;

	olddri_x = map->game->dir_x;
	map->game->dir_x = map->game->dir_x * cos(-rotspeed) - map->game->dir_y * sin(-rotspeed);
	map->game->dir_y = olddri_x * sin(-rotspeed) + map->game->dir_y* cos(-rotspeed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x =  map->game->plane_x * cos(-rotspeed) -  map->game->plane_y * sin(-rotspeed);
	map->game->plane_y =  oldplane_x * sin(-rotspeed) +  map->game->plane_y * cos(-rotspeed);
}

void	rotate_right(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;

	olddri_x = map->game->dir_x;
	map->game->dir_x = map->game->dir_x * cos(rotspeed) - map->game->dir_y * sin(rotspeed);
	map->game->dir_y = olddri_x * sin(rotspeed) + map->game->dir_y * cos(rotspeed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x =  map->game->plane_x * cos(rotspeed) -  map->game->plane_y * sin(rotspeed);
	map->game->plane_y =  oldplane_x * sin(rotspeed) +  map->game->plane_y * cos(rotspeed);
}

void	cursor(double xpos, double ypos, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (data->game->cursor_x < WINDOWSW / 2 - 100)
	{
		data->game->rotate_left = true;
		if (data->game->cursor_x < WINDOWSW / 2 - 65)
			mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, ypos);
	}
	else
		data->game->rotate_left = false;
	if (data->game->cursor_x > WINDOWSW / 2 + 100)
	{
		data->game->rotate_right = true;
		if (data->game->cursor_x > WINDOWSW / 2 + 65)
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
