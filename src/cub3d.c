/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 18:50:03 by derey            ###   ########.fr       */
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

static void	init_pos(t_map *data, int i, int j)
{
	data->game->plane_x = 0;
	data->game->plane_y = 0;
	data->game->dir_x = 0;
	data->game->dir_y = 0;
	if (data->map[j][i] == 'N')
	{
		data->game->plane_x = 0.66;
		data->game->dir_y = -1;
	}
	if (data->map[j][i] == 'S')
	{
		data->game->plane_x = -0.66;
		data->game->dir_y = 1;
	}
	if (data->map[j][i] == 'W')
	{
		data->game->plane_y = -0.66;
		data->game->dir_x = -1;
	}
	if (data->map[j][i] == 'E')
	{
		data->game->plane_y = 0.66;
		data->game->dir_x = 1;
	}
}

void	init_player(t_map *data)
{
	int	i;
	int	j;

	j = 0;
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
				data->m_map->pos_x = i;
				data->m_map->pos_y = j;
				init_pos(data, i, j);
				data->map[j][i] = '0';
				break ;
			}
			i++;
		}
		j++;
	}
}

void	verif_option(t_opt *option)
{
	option->valid->instances[0].enabled = option->play_music;
	option->unvalid->instances[0].enabled = !option->play_music;
	option->valid->instances[1].enabled = option->display_map;
	option->unvalid->instances[1].enabled = !option->display_map;
	option->valid->instances[2].enabled = option->display_fps;
	option->unvalid->instances[2].enabled = !option->display_fps;
	option->valid->instances[3].enabled = option->night_mode;
	option->unvalid->instances[3].enabled = !option->night_mode;
}

void	free_t_textures(t_textures *src, mlx_t *mlx)
{
	long unsigned int	i;

	i = 0;
	while (i < src->nb_textures)
	{
		mlx_delete_texture(src->textures[i]);
		mlx_delete_image(mlx, src->image[i]); // a modif pour ne plus avoir de leak
		free(src->textures_name[i]);
		i++;
	}
	free(src->textures_name);
	free(src->textures);
	free(src->image);
}

void	len_map(t_map *data)
{
	int	x;
	int	y;
	int	save;

	save = 0;
	x = 0;
	y = 0;
	data->h_map = 0;
	data->w_map = 0;
	data->h_map = (int)ft_strlen_w(data->map);
	while (y < data->h_map)
	{
		x = (int)ft_strlen(data->map[y]);
		if (x > save)
			save = x;
		y++;
	}
	data->w_map = save;
	printf("y = %d, x = %d\n", data->h_map, data->w_map);
}

void	option(t_map *data)
{
	button_rtn(data->menu_option);
	button_music(data->menu_option);
	button_map(data->menu_option);
	button_fps(data);
	button_night(data->menu_option);
}

void	cub3d(t_map *data)
{
	t_mini	map;
	t_ray	raycast;
	t_game	game;
	t_button	play;
	t_button	option_;
	t_button	exi;
	mlx_texture_t	*logo;
	t_button	rtn;
	t_button	music;
	t_button	fov;
	t_button	floor;
	t_button	roof;

	(void)data;
	data->mlx = mlx_init(WINDOWSW, WINDOWSH, "Cub3d", true);
	data->rayc = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->minima = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->mini_iso = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->menu = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);

	mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	logo = mlx_load_png("./tiles/logo.png"); // a free
	data->cubd = mlx_new_image(data->mlx, 400, 200);
	data->img_play = mlx_new_image(data->mlx, 400, 150);
	data->img_option = mlx_new_image(data->mlx, 400, 150);
	data->img_exit = mlx_new_image(data->mlx, 400, 150);
	data->floor = mlx_load_png("./tiles/textures/floor.png");
	data->cell = mlx_load_png("./tiles/textures/cell.png");
	data->cub = mlx_load_png ("./tiles/menu/cub3d.png"); // a free
	data->texplay = mlx_load_png ("./tiles/menu/play.png"); // a free
	data->texopt = mlx_load_png ("./tiles/menu/option.png"); // a free
	data->texexit = mlx_load_png ("./tiles/menu/exit.png"); // a free
	data->night = mlx_load_png("./tiles/textures/night.png"); // a free
	data->menufd = mlx_load_png("./tiles/menu/menufd1.png"); // a free
	data->menufd2 = mlx_load_png("./tiles/menu/menufd3.png"); // a free
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_DECORATED, false);
	mlx_set_icon(data->mlx, logo);
	data->menu_option->unvalid_txt = mlx_load_png("./tiles/menu/checkB.png"); // a free
	data->menu_option->valid_txt = mlx_load_png("./tiles/menu/checkG.png"); // a free
	data->menu_option->unvalid = mlx_texture_to_image(data->mlx, data->menu_option->unvalid_txt);
	data->menu_option->valid = mlx_texture_to_image(data->mlx, data->menu_option->valid_txt);
	data->menu_option->cub = mlx_texture_to_image(data->mlx, data->cub);
	data->menu_option->rtn_txt = mlx_load_png("./tiles/menu/return.png"); // a free
	data->menu_option->rtn = mlx_texture_to_image(data->mlx, data->menu_option->rtn_txt);
	data->menu_option->music_txt = mlx_load_png("./tiles/menu/music.png"); // a free
	data->menu_option->music = mlx_texture_to_image(data->mlx, data->menu_option->music_txt);
	data->menu_option->fps_txt = mlx_load_png("./tiles/menu/FPS.png"); // a free
	data->menu_option->roof_txt = mlx_load_png("./tiles/menu/roof.png"); // a free
	data->menu_option->mini_txt = mlx_load_png("./tiles/menu/mini.png"); // a free
	data->menu_option->fps = mlx_texture_to_image(data->mlx, data->menu_option->fps_txt);
	data->menu_option->roof = mlx_texture_to_image(data->mlx, data->menu_option->roof_txt);
	data->menu_option->mini = mlx_texture_to_image(data->mlx, data->menu_option->mini_txt);
	data->menu_option->fps->enabled = false;
	data->menu_option->roof->enabled = false;
	data->menu_option->mini->enabled = false;
	data->menu_option->music->enabled = false;
	data->menu_option->rtn->enabled = false;
	data->menu_option->unvalid->enabled = false;
	data->menu_option->valid->enabled = false;
	data->menu_option->but_rtn = &rtn;
	data->but_option = &option_;
	music.click = false;
	fov.click = false;
	floor.click = false;
	roof.click = false;
	data->fps = 0;
	data->menu_option->play_music = false; // a changer
	data->menu_option->display_map = true;
	data->menu_option->display_fps = true;
	data->menu_option->night_mode = false;
	data->menu_option->but_music = &music;
	data->menu_option->but_map = &fov;
	data->menu_option->but_fps = &floor;
	data->menu_option->but_night = &roof;
	data->menu_option->bottom = mlx_texture_to_image(data->mlx, data->menufd2);
	data->menu_option->bottom->enabled = false;
	data->menu_option->index = 0;
	data->menu_option->but_night->press_enter = false;
	data->menu_option->but_map->press_enter = false;
	data->menu_option->but_fps->press_enter = false;
	data->menu_option->but_music->press_enter = false;
	data->menu_option->cub->enabled = false;
	data->menu_option->but_rtn->click = false;
	option(data);
	data->time_fps = time(NULL);
	data->fog = true;
	data->pause = true;
	data->menu_option->visible = false;
	data->m_map = &map;
	data->game = &game;
	data->raycast = &raycast;
	data->speed = 2.0;
	data->rotspeed = 1.69;
	data->but_play = &play;
	data->but_exit = &exi;
	data->idx_menu = 0;
	data->press = false;
	data->ceiling = false;
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_w = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->game->cursor_y = 0;
	data->game->cursor_x = 0;
	data->press = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->but_play->click = false;
	data->but_option->click = false;
	data->but_exit->click = false;
	data->but_play->press_enter = false;
	data->but_option->press_enter = false;
	data->but_exit->press_enter = false;
	data->minima->enabled = true;
	data->mini_iso->enabled = false;
	data->game->moove_cur = false;
	init_player(data);
	data->cubd = mlx_texture_to_image(data->mlx, data->cub);
	data->img_play = mlx_texture_to_image(data->mlx, data->texplay);
	data->img_option = mlx_texture_to_image(data->mlx, data->texopt);
	data->img_exit = mlx_texture_to_image(data->mlx, data->texexit);
	data->menu = mlx_texture_to_image(data->mlx, data->menufd);
	mlx_image_to_window(data->mlx, data->rayc, 0, 0);
	mlx_image_to_window(data->mlx, data->minima, 0, 0);
	mlx_image_to_window(data->mlx, data->mini_iso, 0, 0);
	mlx_image_to_window(data->mlx, data->menu, 0, 0);
	mlx_image_to_window(data->mlx, data->cubd, (WINDOWSW * 0.5 - WINDOWSW / 9), 50);
	mlx_image_to_window(data->mlx, data->img_play, (WINDOWSW * 0.5 - WINDOWSW / 6 + 10), 490);
	mlx_image_to_window(data->mlx, data->img_option, (WINDOWSW * 0.5 - WINDOWSW / 6 + 10), 660);
	mlx_image_to_window(data->mlx, data->img_exit, (WINDOWSW * 0.5 - WINDOWSW / 6 + 10), 840);

	mlx_image_to_window(data->mlx, data->menu_option->bottom, 0, 0);
	mlx_image_to_window(data->mlx, data->menu_option->rtn, data->menu_option->but_rtn->but_x_min, data->menu_option->but_rtn->but_y_min + 5);
	mlx_image_to_window(data->mlx, data->menu_option->cub, (WINDOWSW * 0.5 - WINDOWSW / 9), 50);
	mlx_image_to_window(data->mlx, data->menu_option->music, data->menu_option->but_music->but_x_min + 4, data->menu_option->but_music->but_y_min + 15);
	mlx_image_to_window(data->mlx, data->menu_option->fps, data->menu_option->but_fps->but_x_min + 4, data->menu_option->but_fps->but_y_min + 10);
	mlx_image_to_window(data->mlx, data->menu_option->roof, data->menu_option->but_night->but_x_min + 4, data->menu_option->but_night->but_y_min + 15);
	mlx_image_to_window(data->mlx, data->menu_option->mini, data->menu_option->but_map->but_x_min + 4, data->menu_option->but_map->but_y_min + 15);

	mlx_image_to_window(data->mlx, data->menu_option->unvalid, data->menu_option->but_music->but_x_max - 75, data->menu_option->but_music->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->menu_option->unvalid, data->menu_option->but_map->but_x_max - 75, data->menu_option->but_map->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->menu_option->unvalid, data->menu_option->but_fps->but_x_max - 75, data->menu_option->but_fps->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->menu_option->unvalid, data->menu_option->but_night->but_x_max - 75, data->menu_option->but_night->but_y_max - 100);

	mlx_image_to_window(data->mlx, data->menu_option->valid, data->menu_option->but_music->but_x_max - 75, data->menu_option->but_music->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->menu_option->valid, data->menu_option->but_map->but_x_max - 75, data->menu_option->but_map->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->menu_option->valid, data->menu_option->but_fps->but_x_max - 75, data->menu_option->but_fps->but_y_max - 100);
	mlx_image_to_window(data->mlx, data->menu_option->valid, data->menu_option->but_night->but_x_max - 75, data->menu_option->but_night->but_y_max - 100);
	verif_option(data->menu_option);
	init_anim(data);
	set_textures_terrain(data);
	fonts_init(data);
	fonts_update(data);
	menu(data);
	len_map(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_scroll_hook(data->mlx, scroll, data);
	mlx_cursor_hook(data->mlx, cursor, data);
	mlx_mouse_hook(data->mlx, mouse, data);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
	free_t_textures(&data->font, data->mlx);
	//free_t_textures(&data->weapon.barrel.walk, data->mlx);
	//free_t_textures(&data->weapon.e11.walk, data->mlx);
	mlx_delete_texture(data->texplay);
	mlx_delete_image(data->mlx, data->img_play);
	mlx_delete_texture(data->texopt);
	mlx_delete_image(data->mlx, data->img_option);
	mlx_delete_texture(data->texexit);
	mlx_delete_image(data->mlx, data->img_exit);
	mlx_delete_texture(data->weapon.center_txt);
	mlx_delete_image(data->mlx, data->weapon.center);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_map	data;
	t_opt	option;
	int		i;

	data.menu_option = &option;
	data.nmb_door = 0;
	init_null(&data);
	main_parsing(argc, argv);
	init_struct(argv, &data);
	init_door(&data);
	i = 0;
	while (data.map && data.map[i])
	{
		check_space(data.map, i, '2', '1');
		ft_printf("%s", data.map[i]);
		i++;
	}
	cub3d(&data);
	free_struct(&data);
	// system("killall paplay");
	return (0);
}
