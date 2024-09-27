/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/27 14:22:58 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	time_fps(t_map	*data)
{
	int save;
	save = (int)(1 / data->mlx->delta_time);
	//mlx_put_string(data->mlx, ft_itoa(save), 0, 0);
	printf("%d\n", save);
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
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, WINDOWSH / 2);
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

		data->but_play->good = false;
		data->but_option->good = false;
		data->but_edit->good = false;
		data->but_exit->good = false;
		data->opt->but_rtn->good = false;

	}
}

void	verif_option(t_opt *opt)
{
	if (opt->play_music)
	{
		opt->m_valid->enabled = true;
		opt->m_unvalid->enabled = false;
	}
	else if (!opt->play_music)
	{
		opt->m_valid->enabled = false;
		opt->m_unvalid->enabled = true;
	}
	if (opt->show_fov)
	{
		opt->f_valid->enabled = true;
		opt->f_unvalid->enabled = false;
	}
	else
	{
		opt->f_valid->enabled = false;
		opt->f_unvalid->enabled = true;
	}
	if (opt->txt_floor)
	{
		opt->fl_valid->enabled = true;
		opt->fl_unvalid->enabled = false;
	}
	else
	{
		opt->fl_unvalid->enabled = true;
		opt->fl_valid->enabled = false;

	}
	if (opt->txt_roof)
	{
		opt->r_valid->enabled = true;
		opt->r_unvalid->enabled = false;
	}
	else
	{
		opt->r_unvalid->enabled = true;
		opt->r_valid->enabled = false;
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
	if ((data->game->cursor_x > data->but_option->but_x_min && data->game->cursor_x < data->but_option->but_x_max && data->game->cursor_y >= data->but_option->but_y_min && data->game->cursor_y < data->but_option->but_y_max && data->but_option->good == true) || data->but_option->press_enter == true )
	{
		data->pause = true;
		data->idx_menu = 0;
		data->but_option->press_enter = false;
		data->but_option->good = false;
		data->menu->enabled = false;
		data->opt->option = true;
		data->cubd->enabled = false;
		data->img_play->enabled = false;
		data->img_option->enabled = false;
		data->img_edit->enabled = false;
		data->img_exit->enabled = false;
		data->opt->bottom->enabled = true;
		data->opt->rtn->enabled = true;
		data->opt->cub->enabled = true;
		data->opt->music->enabled = true;
		verif_option(data->opt);
	}
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

void	check_but_rtn(t_opt *option, t_map *data)
{
	if (data->game->cursor_x > option->but_rtn->but_x_min && data->game->cursor_x < option->but_rtn->but_x_max && data->game->cursor_y > option->but_rtn->but_y_min && data->game->cursor_y < option->but_rtn->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_rtn->click = true;
	}
	if (data->game->cursor_x < option->but_rtn->but_x_min || data->game->cursor_x > option->but_rtn->but_x_max || data->game->cursor_y < option->but_rtn->but_y_min || data->game->cursor_y > option->but_rtn->but_y_max)
		data->opt->but_rtn->good = false;
	if ((data->game->cursor_x > option->but_rtn->but_x_min && data->game->cursor_x < option->but_rtn->but_x_max && data->game->cursor_y > option->but_rtn->but_y_min && data->game->cursor_y < option->but_rtn->but_y_max && data->opt->but_rtn->good) || data->opt->but_rtn->press_enter)
	{
		data->pause = true;
		data->idx_menu = 0;
		data->menu->enabled = true;
		data->opt->option = false;
		data->cubd->enabled = true;
		data->img_play->enabled = true;
		data->img_option->enabled = true;
		data->img_edit->enabled = true;
		data->img_exit->enabled = true;
		data->opt->bottom->enabled = false;
		data->opt->rtn->enabled = false;
		data->opt->cub->enabled = false;
		data->opt->but_rtn->press_enter = false;

		data->opt->m_unvalid->enabled = false;
		data->opt->f_unvalid->enabled = false;
		data->opt->fl_unvalid->enabled = false;
		data->opt->r_unvalid->enabled = false;
		data->opt->m_valid->enabled = false;
		data->opt->f_valid->enabled = false;
		data->opt->fl_valid->enabled = false;
		data->opt->r_valid->enabled = false;
		data->opt->music->enabled = false;
	}
}

void	check_but_music(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_music->but_x_min && data->game->cursor_x < data->opt->but_music->but_x_max && data->game->cursor_y > data->opt->but_music->but_y_min && data->game->cursor_y < data->opt->but_music->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_music->click = true;
	}
	if (data->game->cursor_x < data->opt->but_music->but_x_min || data->game->cursor_x > data->opt->but_music->but_x_max || data->game->cursor_y < data->opt->but_music->but_y_min || data->game->cursor_y > data->opt->but_music->but_y_max)
		data->opt->but_music->good = false;
	if (data->game->cursor_x > data->opt->but_music->but_x_min && data->game->cursor_x < data->opt->but_music->but_x_max && data->game->cursor_y > data->opt->but_music->but_y_min && data->game->cursor_y < data->opt->but_music->but_y_max && data->opt->but_music->good)
	{
		data->opt->but_music->good = false;
		data->opt->play_music = !data->opt->play_music;
		verif_option(data->opt);
	}
}

void	check_but_fov(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_fov->but_x_min && data->game->cursor_x < data->opt->but_fov->but_x_max && data->game->cursor_y > data->opt->but_fov->but_y_min && data->game->cursor_y < data->opt->but_fov->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_fov->click = true;
	}
	if (data->game->cursor_x < data->opt->but_fov->but_x_min || data->game->cursor_x > data->opt->but_fov->but_x_max || data->game->cursor_y < data->opt->but_fov->but_y_min || data->game->cursor_y > data->opt->but_fov->but_y_max)
		data->opt->but_fov->good = false;
	if (data->game->cursor_x > data->opt->but_fov->but_x_min && data->game->cursor_x < data->opt->but_fov->but_x_max && data->game->cursor_y > data->opt->but_fov->but_y_min && data->game->cursor_y < data->opt->but_fov->but_y_max && data->opt->but_fov->good)
	{
		data->opt->but_fov->good = false;
		data->opt->show_fov = !data->opt->show_fov;
		verif_option(data->opt);
	}
}

void	check_but_floor(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_floor->but_x_min && data->game->cursor_x < data->opt->but_floor->but_x_max && data->game->cursor_y > data->opt->but_floor->but_y_min && data->game->cursor_y < data->opt->but_floor->but_y_max)
	{
		data->idx_menu = 0;
		data->opt->but_floor->click = true;
	}
	if (data->game->cursor_x < data->opt->but_floor->but_x_min || data->game->cursor_x > data->opt->but_floor->but_x_max || data->game->cursor_y < data->opt->but_floor->but_y_min || data->game->cursor_y > data->opt->but_floor->but_y_max)
		data->opt->but_floor->good = false;
	if (data->game->cursor_x > data->opt->but_floor->but_x_min && data->game->cursor_x < data->opt->but_floor->but_x_max && data->game->cursor_y > data->opt->but_floor->but_y_min && data->game->cursor_y < data->opt->but_floor->but_y_max && data->opt->but_floor->good)
	{
		data->opt->but_floor->good = false;
		data->opt->txt_floor = !data->opt->txt_floor;
		verif_option(data->opt);
	}
}

void	check_but_roof(t_map *data)
{
	if (data->game->cursor_x > data->opt->but_roof->but_x_min && data->game->cursor_x < data->opt->but_roof->but_x_max && data->game->cursor_y > data->opt->but_roof->but_y_min - 43 && data->game->cursor_y < data->opt->but_roof->but_y_max - 49)
	{
		data->idx_menu = 0;
		data->opt->but_roof->click = true;
	}
	if (data->game->cursor_x < data->opt->but_roof->but_x_min || data->game->cursor_x > data->opt->but_roof->but_x_max || data->game->cursor_y < data->opt->but_roof->but_y_min || data->game->cursor_y > data->opt->but_roof->but_y_max)
		data->opt->but_roof->good = false;
	if (data->game->cursor_x > data->opt->but_roof->but_x_min && data->game->cursor_x < data->opt->but_roof->but_x_max && data->game->cursor_y > data->opt->but_roof->but_y_min && data->game->cursor_y < data->opt->but_roof->but_y_max && data->opt->but_roof->good)
	{
		data->opt->but_roof->good = false;
		data->opt->txt_roof = !data->opt->txt_roof;
		data->plafond = !data->plafond;
		verif_option(data->opt);
	}
}

void	check_music(t_map *data)
{
	static int is_play = 0;

	if ((!is_play || is_play == 1) && data->opt->play_music && data->pause)
	{
		if (is_play)
			system("killall paplay");
		system("paplay Music/Menu.wav &");
		printf("2\n");
		is_play = 2;
	}
	else if ((!is_play || is_play == 2) && data->opt->play_music && !data->pause)
	{
		if (is_play)
			system("killall paplay");
		system("paplay ./Music/InGame.wav &");
		printf("1\n");
		is_play = 1;
	}
	else if (is_play && !data->opt->play_music)
	{
		system("killall paplay &");
		printf("%d 0\n", is_play);
		is_play = 0;
	}
}

void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	if (data->pause != true)
		raycasting(data);
//	mlx_resize_hook()
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
	check_but_rtn(data->opt, data);
	check_but_music(data);
	check_but_fov(data);
	check_but_floor(data);
	check_but_roof(data);
	button_play(data);
	button_option(data);
	button_edit(data);
	button_exit(data);
	button_rtn(data->opt);
	button_music(data->opt);
	button_fov(data->opt);
	button_floor(data->opt);
	button_roof(data->opt);
	check_music(data);
}

void	move_w(t_map *data)
{
	double testx;
	double testy;

	testx = data->game->player_x;
	testy = data->game->player_y;

	testx += data->game->dir_x * data->speed * data->mlx->delta_time;
	testy += data->game->dir_y * data->speed * data->mlx->delta_time;
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

	testx -= data->game->dir_x * data->speed * data->mlx->delta_time;
	testy -= data->game->dir_y * data->speed * data->mlx->delta_time;
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

	testx += data->game->dir_y * data->speed * data->mlx->delta_time;
	testy -= data->game->dir_x * data->speed * data->mlx->delta_time;
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

	testx -= data->game->dir_y * data->speed * data->mlx->delta_time;
	testy += data->game->dir_x * data->speed * data->mlx->delta_time;
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
	double	speed;

	olddri_x = map->game->dir_x;
	speed = map->rotspeed * map->mlx->delta_time;
	map->game->dir_x = map->game->dir_x * cos(-speed) - map->game->dir_y * sin(-speed);
	map->game->dir_y = olddri_x * sin(-speed) + map->game->dir_y* cos(-speed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x =  map->game->plane_x * cos(-speed) -  map->game->plane_y * sin(-speed);
	map->game->plane_y =  oldplane_x * sin(-speed) +  map->game->plane_y * cos(-speed);
}

void	rotate_right(t_map *map)
{
	double	olddri_x;
	double	oldplane_x;
	double	speed;

	olddri_x = map->game->dir_x;
	speed = map->rotspeed * map->mlx->delta_time;
	map->game->dir_x = map->game->dir_x * cos(speed) - map->game->dir_y * sin(speed);
	map->game->dir_y = olddri_x * sin(speed) + map->game->dir_y * cos(speed);
	oldplane_x = map->game->plane_x;
	map->game->plane_x =  map->game->plane_x * cos(speed) -  map->game->plane_y * sin(speed);
	map->game->plane_y =  oldplane_x * sin(speed) +  map->game->plane_y * cos(speed);
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
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			if (data->pause == true && !data->opt->option)
				mlx_close_window(data->mlx);
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
