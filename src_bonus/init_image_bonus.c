/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:57 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:09:23 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_txt_menu(t_map *data)
{
	data->floor = mlx_load_png("./tiles/textures/floor.png");
	data->cell = mlx_load_png("./tiles/textures/cell.png");
	data->cub = mlx_load_png ("./tiles/menu/cub3d.png");
	data->texplay = mlx_load_png ("./tiles/menu/play.png");
	data->texopt = mlx_load_png ("./tiles/menu/option.png");
	data->texexit = mlx_load_png ("./tiles/menu/exit.png");
	data->night = mlx_load_png("./tiles/textures/night.png");
	data->menufd = mlx_load_png("./tiles/menu/menufd1.png");
	data->menufd2 = mlx_load_png("./tiles/menu/menufd3.png");
}

void	init_txt_menu_option(t_map *data, t_opt *opt)
{
	opt->unvalid_txt = mlx_load_png("./tiles/menu/checkB.png");
	opt->valid_txt = mlx_load_png("./tiles/menu/checkG.png");
	opt->unvalid = mlx_texture_to_image(data->mlx, opt->unvalid_txt);
	opt->valid = mlx_texture_to_image(data->mlx, opt->valid_txt);
	opt->cub = mlx_texture_to_image(data->mlx, data->cub);
	opt->rtn_txt = mlx_load_png("./tiles/menu/return.png");
	opt->rtn = mlx_texture_to_image(data->mlx, opt->rtn_txt);
	opt->music_txt = mlx_load_png("./tiles/menu/music.png");
	opt->music = mlx_texture_to_image(data->mlx, opt->music_txt);
	opt->fps_txt = mlx_load_png("./tiles/menu/FPS.png");
	opt->roof_txt = mlx_load_png("./tiles/menu/roof.png");
	opt->mini_txt = mlx_load_png("./tiles/menu/mini.png");
	opt->fps = mlx_texture_to_image(data->mlx, opt->fps_txt);
	opt->roof = mlx_texture_to_image(data->mlx, opt->roof_txt);
	opt->mini = mlx_texture_to_image(data->mlx, opt->mini_txt);
}

static void	place_img_opt(t_map *data, t_opt *opt)
{
	mlx_image_to_window(data->mlx, opt->music, opt->but_music->x_min + 4, \
		opt->but_music->y_min + 15);
	mlx_image_to_window(data->mlx, opt->fps, opt->but_fps->x_min + 4, \
		opt->but_fps->y_min + 10);
	mlx_image_to_window(data->mlx, opt->roof, opt->but_night->x_min + 4, \
		opt->but_night->y_min + 15);
	mlx_image_to_window(data->mlx, opt->mini, opt->but_map->x_min + 4, \
		opt->but_map->y_min + 15);
	mlx_image_to_window(data->mlx, opt->unvalid, opt->but_music->x_max - 75, \
		opt->but_music->y_max - 100);
	mlx_image_to_window(data->mlx, opt->unvalid, opt->but_map->x_max - 75, \
		opt->but_map->y_max - 100);
	mlx_image_to_window(data->mlx, opt->unvalid, opt->but_fps->x_max - 75, \
		opt->but_fps->y_max - 100);
	mlx_image_to_window(data->mlx, opt->unvalid, opt->but_night->x_max - 75, \
		opt->but_night->y_max - 100);
	mlx_image_to_window(data->mlx, opt->valid, opt->but_music->x_max - 75, \
	opt->but_music->y_max - 100);
	mlx_image_to_window(data->mlx, opt->valid, opt->but_map->x_max - 75, \
	opt->but_map->y_max - 100);
	mlx_image_to_window(data->mlx, opt->valid, opt->but_fps->x_max - 75, \
	opt->but_fps->y_max - 100);
	mlx_image_to_window(data->mlx, opt->valid, opt->but_night->x_max - 75, \
	opt->but_night->y_max - 100);
}

void	place_img(t_map *data, t_opt *opt)
{
	mlx_image_to_window(data->mlx, data->rayc, 0, 0);
	mlx_image_to_window(data->mlx, data->minima, 0, 0);
	mlx_image_to_window(data->mlx, data->mini_iso, 0, 0);
	mlx_image_to_window(data->mlx, data->menu, 0, 0);
	mlx_image_to_window(data->mlx, data->cubd, (WINDOWSW * 0.5 - WINDOWSW \
		/ 9), 50);
	mlx_image_to_window(data->mlx, data->img_play, (WINDOWSW * 0.5 - WINDOWSW \
		/ 6 + 10), 490);
	mlx_image_to_window(data->mlx, data->img_option, (WINDOWSW * 0.5 - WINDOWSW \
		/ 6 + 10), 660);
	mlx_image_to_window(data->mlx, data->img_exit, (WINDOWSW * 0.5 - WINDOWSW \
		/ 6 + 10), 840);
	mlx_image_to_window(data->mlx, opt->bottom, 0, 0);
	mlx_image_to_window(data->mlx, opt->rtn, opt->but_rtn->x_min, \
		opt->but_rtn->y_min + 5);
	mlx_image_to_window(data->mlx, opt->cub, (WINDOWSW * 0.5 - WINDOWSW / 9), \
		50);
	place_img_opt(data, opt);
}

void	init_mlx_and_new_image(t_map *data)
{
	mlx_texture_t	*logo;

	data->mlx = mlx_init(WINDOWSW, WINDOWSH, "Cub3d", true);
	data->rayc = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->minima = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->mini_iso = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->menu = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	logo = mlx_load_png("./tiles/logo.png");
	mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	data->cubd = mlx_new_image(data->mlx, 400, 200);
	data->img_play = mlx_new_image(data->mlx, 400, 150);
	data->img_option = mlx_new_image(data->mlx, 400, 150);
	data->img_exit = mlx_new_image(data->mlx, 400, 150);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_DECORATED, false);
	mlx_set_icon(data->mlx, logo);
	mlx_delete_texture(logo);
}
