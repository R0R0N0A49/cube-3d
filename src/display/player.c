/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:44 by derey             #+#    #+#             */
/*   Updated: 2024/09/28 17:50:00 by derey            ###   ########.fr       */
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
	data->edit->enabled = false;
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

void	play(t_map *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, WINDOWSH / 2);
	data->pause = false;
	data->idx_menu = 0;
	data->editor->edit = false;
	data->but_play->press_enter = false;
	data->but_play->good = false;
	data->edit->enabled = false;
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

void	check_but_rtn_edit(t_opt *option, t_map *data)
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
		data->opt->index = 0;
		data->menu->enabled = true;
		data->edit->enabled = false;
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



void	check_music(t_map *data)
{
	static int is_play = 0;

	if ((!is_play || is_play == 1) && data->opt->play_music && data->pause)
	{
		if (is_play)
			system("killall paplay");
		//system("paplay Music/Menu.wav &");
		printf("2\n");
		is_play = 2;
	}
	else if ((!is_play || is_play == 2) && data->opt->play_music && !data->pause)
	{
		if (is_play)
			system("killall paplay");
		//system("paplay ./Music/InGame.wav &");
		printf("1\n");
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
	init_button_len(data);
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
	button_play(data);
	button_option(data);
	button_edit(data);
	button_exit(data);
	check_but_play(data);
	check_but_option(data);
	check_but_edit(data);
	check_but_exit(data);

	button_rtn(data->opt);
	button_music(data->opt);
	button_fov(data->opt);
	button_floor(data->opt);
	button_roof(data->opt);
	check_music(data);
	check_but_rtn(data->opt, data);
	check_but_music(data);
	check_but_fov(data);
	check_but_floor(data);
	check_but_roof(data);
	editeur(data);
}
