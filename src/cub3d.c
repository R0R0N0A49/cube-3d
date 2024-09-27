/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/09/27 13:30:54 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_null(t_map *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->down = 0;
	data->up = 0;
	data->file = -1;
	data->map = NULL;
}

void	ft_free_stringtab(char **src)
{
	int	i;

	i = 0;
	if (!src[0] || !src[0][0])
		return ;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

int	free_struct(t_map *data)
{
	if (data->no)
		mlx_delete_texture(data->no);
	if (data->so)
		mlx_delete_texture(data->so);
	if (data->ea)
		mlx_delete_texture(data->ea);
	if (data->we)
		mlx_delete_texture(data->we);
	if (data->map)
		ft_free_stringtab(data->map);
	if (data->file != -1)
	{
		close(data->file);
		data->file = -1;
	}
	return (1);
}

void	mini_map(t_map *data, mlx_t *mlx)
{
	int	i;
	int	j;

	j = 0;
	(void)mlx;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				data->game->player_x = (double)i + 0.5;
				data->game->player_y = (double)j + 0.5;
				data->mini_map->pos_x = i;
				data->mini_map->pos_y = j;
				if (data->map[j][i] == 'N')
				{
					data->game->plane_x = 0.66;
					data->game->plane_y = 0;
					data->game->dir_x = 0;
					data->game->dir_y = -1;
				}
				if (data->map[j][i] == 'S')
				{
					data->game->plane_x = -0.66;
					data->game->plane_y = 0;
					data->game->dir_x = 0;
					data->game->dir_y = 1;
				}
				if (data->map[j][i] == 'W')
				{
					data->game->plane_x = 0;
					data->game->plane_y = -0.66;
					data->game->dir_x = -1;
					data->game->dir_y = 0;
				}
				if (data->map[j][i] == 'E')
				{
					data->game->plane_x = 0;
					data->game->plane_y = 0.66;
					data->game->dir_x = 1;
					data->game->dir_y = 0;
				}
				data->map[j][i] = '0';
				break ;
			}
			i++;
		}
		j++;
	}
}

void	cub3d(t_map *data)
{
	t_mini	map;
	t_ray	raycast;
	t_game	game;
	t_button play;
	t_button option_;
	t_button edit;
	t_button exi;
	mlx_texture_t *logo;

	t_button rtn;
	t_button music;
	t_button fov;
	t_button floor;
	t_button roof;

	(void)data;
	data->mlx = mlx_init(WINDOWSW, WINDOWSH, "cub3d", true);
	data->rayc = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->minima = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->menu = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);

	data->opt->bottom = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);

	mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, WINDOWSH / 2);
	logo = mlx_load_png("./tiles/logo.png");
	data->cubd = mlx_new_image(data->mlx, 400, 200);
	data->img_play = mlx_new_image(data->mlx, 400, 150);
	data->img_option = mlx_new_image(data->mlx, 400, 150);
	data->img_edit = mlx_new_image(data->mlx, 400, 150);
	data->img_exit = mlx_new_image(data->mlx, 400, 150);
	data->cub = mlx_load_png ("./tiles/cub3d.png");
	data->texplay = mlx_load_png ("./tiles/play.png");
	data->texopt = mlx_load_png ("./tiles/option.png");
	data->texedi = mlx_load_png ("./tiles/edit.png");
	data->texexit = mlx_load_png ("./tiles/exit.png");
	data->nuit = mlx_load_png("./tiles/nuit.png");
	data->herbe = mlx_load_png("./tiles/herbe.png");
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_icon(data->mlx, logo);

	data->opt->unvalid_txt = mlx_load_png("./tiles/checkB.png");
	data->opt->valid_txt = mlx_load_png("./tiles/checkG.png");
	data->opt->m_unvalid = mlx_texture_to_image(data->mlx, data->opt->unvalid_txt);
	data->opt->f_unvalid = mlx_texture_to_image(data->mlx, data->opt->unvalid_txt);
	data->opt->fl_unvalid = mlx_texture_to_image(data->mlx, data->opt->unvalid_txt);
	data->opt->r_unvalid = mlx_texture_to_image(data->mlx, data->opt->unvalid_txt);
	data->opt->m_valid = mlx_texture_to_image(data->mlx, data->opt->valid_txt);
	data->opt->f_valid = mlx_texture_to_image(data->mlx, data->opt->valid_txt);
	data->opt->fl_valid = mlx_texture_to_image(data->mlx, data->opt->valid_txt);
	data->opt->r_valid = mlx_texture_to_image(data->mlx, data->opt->valid_txt);
	data->opt->cub = mlx_texture_to_image(data->mlx, data->cub);
	data->opt->rtn_txt = mlx_load_png("./tiles/return.png");
	data->opt->rtn = mlx_texture_to_image(data->mlx, data->opt->rtn_txt);
	data->opt->music_txt = mlx_load_png("./tiles/music.png");
	data->opt->music = mlx_texture_to_image(data->mlx, data->opt->music_txt);
	data->opt->music->enabled = false;
	data->opt->rtn->enabled = false;
	data->opt->bottom->enabled = false;
	data->opt->cub->enabled = false;
	data->opt->m_unvalid->enabled = false;
	data->opt->f_unvalid->enabled = false;
	data->opt->fl_unvalid->enabled = false;
	data->opt->r_unvalid->enabled = false;
	data->opt->m_valid->enabled = false;
	data->opt->f_valid->enabled = false;
	data->opt->fl_valid->enabled = false;
	data->opt->r_valid->enabled = false;
	data->opt->but_rtn = &rtn;
	data->but_option = &option_;
	music.click = false;
	fov.click = false;
	floor.click = false;
	roof.click = false;
	data->opt->play_music = true;
	data->opt->show_fov = false;
	data->opt->txt_floor = false;
	data->opt->txt_roof = false;
	data->opt->but_music = &music;
	data->opt->but_fov = &fov;
	data->opt->but_floor = &floor;
	data->opt->but_roof = &roof;
	option(data);

	data->pause = true;
	data->opt->option = false;
	data->mini_map = &map;
	data->game = &game;
	data->raycast = &raycast;
	data->speed = 0.069;
	data->rotspeed = 0.035;
	data->but_play = &play;
	data->but_edit = &edit;
	data->but_exit = &exi;
	data->idx_menu = 0;
	data->plafond = false;
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_w = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->press = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->but_play->click = false;
	data->but_play->press_enter = false;
	data->but_option->press_enter = false;
	data->but_edit->press_enter = false;
	data->but_exit->press_enter = false;
	mini_map(data, data->mlx);
	data->cubd = mlx_texture_to_image(data->mlx, data->cub);
	data->img_play = mlx_texture_to_image(data->mlx, data->texplay);
	data->img_option = mlx_texture_to_image(data->mlx, data->texopt);
	data->img_edit = mlx_texture_to_image(data->mlx, data->texedi);
	data->img_exit = mlx_texture_to_image(data->mlx, data->texexit);
	mlx_image_to_window(data->mlx, data->rayc, 0, 0);
	mlx_image_to_window(data->mlx, data->minima, 0, 0);
	mlx_image_to_window(data->mlx, data->menu, 0, 0);
	mlx_image_to_window(data->mlx, data->cubd, (WINDOWSW / 2 - WINDOWSW / 9), 50);
	mlx_image_to_window(data->mlx, data->img_play, (WINDOWSW / 2 - WINDOWSW / 6 + 10), 310);
	mlx_image_to_window(data->mlx, data->img_option, (WINDOWSW / 2 - WINDOWSW / 6 + 10), 480);
	mlx_image_to_window(data->mlx, data->img_edit, (WINDOWSW / 2 - WINDOWSW / 6 + 10), 660);
	mlx_image_to_window(data->mlx, data->img_exit, (WINDOWSW / 2 - WINDOWSW / 6 + 10), 840);

	mlx_image_to_window(data->mlx, data->opt->bottom, 0, 0);
	mlx_image_to_window(data->mlx, data->opt->rtn, data->opt->but_rtn->but_x_min, data->opt->but_rtn->but_y_min + 5);
	mlx_image_to_window(data->mlx, data->opt->cub, (WINDOWSW / 2 - WINDOWSW / 9), 50);
	mlx_image_to_window(data->mlx, data->opt->music, data->opt->but_music->but_x_min + 4, data->opt->but_music->but_y_min + 15);

	mlx_image_to_window(data->mlx, data->opt->m_unvalid, data->opt->but_music->but_x_max - 75, data->opt->but_music->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->opt->f_unvalid, data->opt->but_fov->but_x_max - 75, data->opt->but_fov->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->opt->fl_unvalid, data->opt->but_floor->but_x_max - 75, data->opt->but_floor->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->opt->r_unvalid, data->opt->but_roof->but_x_max - 75, data->opt->but_roof->but_y_max - 100);

	mlx_image_to_window(data->mlx, data->opt->m_valid, data->opt->but_music->but_x_max - 75, data->opt->but_music->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->opt->f_valid, data->opt->but_fov->but_x_max - 75, data->opt->but_fov->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->opt->fl_valid, data->opt->but_floor->but_x_max - 75, data->opt->but_floor->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->opt->r_valid, data->opt->but_roof->but_x_max - 75, data->opt->but_roof->but_y_max - 100);

	menu(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_cursor_hook(data->mlx, cursor, data);
	mlx_mouse_hook(data->mlx, mouse, data);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_map	data;
	t_opt	option;

	data.opt = &option;
	init_null(&data);
	main_parsing(argc, argv);
	init_struct(argv, &data);
	int i = 0;
	while (data.map && data.map[i])
	{
		check_space(data.map, i, '2', '1');
		ft_printf("%s", data.map[i]);
		i++;
	}
	cub3d(&data);
	free_struct(&data);
	system("killall paplay");
	return (0);
}
