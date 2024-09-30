/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/30 15:21:33 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define COLOR_PLAYER 0xFF5000FF

void	time_fps(t_map	*data)
{
	double	time_dif;

	time_dif = difftime(time(NULL), data->time_fps);
	if (time_dif >= 1)
	{
		data->fps =(int)(1 / data->mlx->delta_time);
		data->time_fps = time(NULL);
	}
}

int	get_pourcent(int value, int size, int max) // a renomer
{
	return ((size * value) / max);
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

void	play_game(t_map *data)
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

void	check_but_play(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->but_play->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->but_play->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->but_play->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->but_play->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->but_play->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->but_play->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->but_play->good == true ) || data->but_play->press_enter == true)
		play_game(data);
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
	int x_min = get_pourcent(data->mlx->width, data->but_option->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->but_option->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->but_option->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->but_option->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->but_option->click = true;
	}	
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->but_option->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y >= y_min && data->game->cursor_y < y_max && data->but_option->good == true) || data->but_option->press_enter == true )
	{
		data->pause = true;
		data->idx_menu = 0;
		data->opt->index = 0;
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
		data->opt->fps->enabled = true;
		data->opt->roof->enabled = true;
		data->opt->mini->enabled = true;
		verif_option(data->opt);
	}
}

void	check_but_edit(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->but_edit->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->but_edit->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->but_edit->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->but_edit->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->but_edit->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->but_edit->good = false;
}

void	check_but_exit(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->but_exit->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->but_exit->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->but_exit->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->but_exit->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->but_exit->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->but_exit->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->but_exit->good == true) || data->but_exit->press_enter == true)
		exit_cub3d(data);
}

void	check_but_rtn(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->opt->but_rtn->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->opt->but_rtn->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->opt->but_rtn->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->opt->but_rtn->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->idx_menu = 0;
		data->opt->but_rtn->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->opt->but_rtn->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->opt->but_rtn->good) || data->opt->but_rtn->press_enter)
	{
		data->pause = true;
		data->idx_menu = 0;
		data->opt->index = 0;
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
		data->opt->fps->enabled = false;
		data->opt->roof->enabled = false;
		data->opt->mini->enabled = false;
	}
}

void	check_but_music(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->opt->but_music->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->opt->but_music->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->opt->but_music->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->opt->but_music->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->opt->index = 0;
		data->opt->but_music->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->opt->but_music->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->opt->but_music->good) || data->opt->but_music->press_enter)
	{
		data->opt->but_music->good = false;
		data->opt->but_music->press_enter = false;
		data->opt->play_music = !data->opt->play_music;
		verif_option(data->opt);
	}
}

void	check_but_map(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->opt->but_map->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->opt->but_map->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->opt->but_map->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->opt->but_map->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->opt->index = 0;
		data->opt->but_map->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->opt->but_map->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->opt->but_map->good) || data->opt->but_map->press_enter)
	{
		data->opt->but_map->good = false;
		data->opt->but_map->press_enter = false;
		data->opt->show_fov = !data->opt->show_fov;
		verif_option(data->opt);
	}
}

void	check_but_fps(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->opt->but_fps->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->opt->but_fps->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->opt->but_fps->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->opt->but_fps->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->opt->index = 0;
		data->opt->but_fps->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->opt->but_fps->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->opt->but_fps->good) || data->opt->but_fps->press_enter)
	{
		data->opt->but_fps->good = false;
		data->opt->but_fps->press_enter = false;
		data->opt->txt_floor = !data->opt->txt_floor;
		fonts_disabled(data);
		verif_option(data->opt);
	}
}

void	check_but_night(t_map *data)
{
	int x_min = get_pourcent(data->mlx->width, data->opt->but_night->but_x_min, WINDOWSW);
	int x_max = get_pourcent(data->mlx->width, data->opt->but_night->but_x_max, WINDOWSW);
	int y_min = get_pourcent(data->mlx->height, data->opt->but_night->but_y_min, WINDOWSH);
	int y_max = get_pourcent(data->mlx->height, data->opt->but_night->but_y_max, WINDOWSH);
	if (data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max)
	{
		data->opt->index = 0;
		data->opt->but_night->click = true;
	}
	if (data->game->cursor_x < x_min || data->game->cursor_x > x_max || data->game->cursor_y < y_min || data->game->cursor_y > y_max)
		data->opt->but_night->good = false;
	if ((data->game->cursor_x > x_min && data->game->cursor_x < x_max && data->game->cursor_y > y_min && data->game->cursor_y < y_max && data->opt->but_night->good) || data->opt->but_night->press_enter)
	{
		data->opt->but_night->good = false;
		data->opt->but_night->press_enter = false;
		data->opt->txt_roof = !data->opt->txt_roof;
		data->fog = !data->fog;
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
		is_play = 2;
	}
	else if ((!is_play || is_play == 2) && data->opt->play_music && !data->pause)
	{
		if (is_play)
			system("killall paplay");
		system("paplay ./Music/InGame.wav &");
		is_play = 1;
	}
	else if (is_play && !data->opt->play_music)
	{
		system("killall paplay &");
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
	time_fps(data);
	if (data->opt->show_fov)
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
	check_but_play(data);
	check_but_option(data);
	check_but_edit(data);
	check_but_exit(data);
	check_but_rtn(data);
	check_but_music(data);
	check_but_map(data);
	check_but_fps(data);
	check_but_night(data);
	button_play(data);
	button_option(data);
	button_edit(data);
	button_exit(data);
	button_rtn(data->opt);
	button_music(data->opt);
	button_map(data->opt);
	button_fps(data);
	button_night(data->opt);
	check_music(data);
	fonts_update(data);
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
			data->opt->but_map->good = true;
			data->opt->but_fps->good = true;
			data->opt->but_night->good = true;
		}
	}
}

void	cursor(double xpos, double ypos, void* param)
{
	t_map	*data;
	
	data = (t_map *)param;
	if (WINDOWSW / 2 == data->game->cursor_x && WINDOWSH /2 == data->game->cursor_y)
	{
		data->game->rotate_left = false;
		data->game->rotate_right = false;
	}
	data->game->cursor_x = xpos;
	data->game->cursor_y = ypos;
	if (xpos < WINDOWSW / 2 - 5 && data->pause == false)
	{
		data->game->rotate_left = true;
		mlx_set_mouse_pos(data->mlx, WINDOWSW / 2,  WINDOWSH /2);
		data->game->cursor_x = WINDOWSW / 2;
		data->game->cursor_y = WINDOWSH / 2;
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
		fonts_update(data);
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			if (data->pause == true && !data->opt->option)
				play_game(data);
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
		if (keydata.key == MLX_KEY_LEFT && (data->pause == false || data->opt->option))
		{
			if (!data->pause)
				data->game->rotate_left = true;
			else
			{
				if (data->opt->index > 1)
					data->opt->index = data->opt->index - 1;
				else
					data->opt->index = 4;
			}
		}
		if (keydata.key == MLX_KEY_RIGHT && (data->pause == false || data->opt->option))
		{
			if (!data->opt->option)
				data->game->rotate_right = true;
			else
			{
				if (data->opt->index >= 4)
					data->opt->index = 1;
				else
					data->opt->index++;
			}
		}
		if (keydata.key == MLX_KEY_DOWN && (data->pause == true || data->opt->option))
		{
			if (!data->opt->option)
			{
				if (data->idx_menu >= 4)
					data->idx_menu = 1;
				else
					data->idx_menu++;
			}
			else
			{
				if (data->opt->index == 3)
					data->opt->index--;
				else if (data->opt->index > 0)
					data->opt->index = (data->opt->index + 2) % 5;
				else
					data->opt->index = 1;
			}
		}
		if (keydata.key == MLX_KEY_UP && data->pause == true)
		{
			if (data->menu->enabled)
			{
				if (data->idx_menu > 1)
					data->idx_menu--;
				else
					data->idx_menu = 4;
			}
			else if (data->opt->option)
			{
				if (data->opt->index == 1)
					data->opt->index = 4;
				else if (data->opt->index == 2)
					data->opt->index = 3;
				else if (data->opt->index > 0)
					data->opt->index = (data->opt->index - 2) % 5;
				else
					data->opt->index = 1;
			}
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
			if (data->opt->index == 1)
				data->opt->but_music->press_enter = true;
			if (data->opt->index == 2)
				data->opt->but_map->press_enter = true;
			if (data->opt->index == 3)
				data->opt->but_fps->press_enter = true;
			if (data->opt->index == 4)
				data->opt->but_night->press_enter = true;
		}
		if (keydata.key == MLX_KEY_P && data->pause == false)
		{
			data->opt->txt_roof = !data->opt->txt_roof;
			data->plafond = !data->plafond;
		}
		if (keydata.key == MLX_KEY_F && data->pause == false)
				data->fog = !data->fog;
		if (keydata.key == MLX_KEY_K)
			mlx_close_window(data->mlx);
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
