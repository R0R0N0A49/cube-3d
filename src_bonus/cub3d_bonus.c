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

void	option(t_map *data)
{
	button_rtn(data->menu_option);
	button_music(data->menu_option);
	button_map(data->menu_option);
	button_fps(data);
	button_night(data->menu_option);
}

void	init_game(t_map *data)
{
	init_bool(data);
	init_player(data);
	data->cubd = mlx_texture_to_image(data->mlx, data->cub);
	data->img_play = mlx_texture_to_image(data->mlx, data->texplay);
	data->img_option = mlx_texture_to_image(data->mlx, data->texopt);
	data->img_exit = mlx_texture_to_image(data->mlx, data->texexit);
	data->menu = mlx_texture_to_image(data->mlx, data->menufd);
	place_img(data, data->menu_option);
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
	free_at_end(data);
}

void	cub3d(t_map *data)
{
	t_mini	map;
	t_ray	raycast;
	t_game	game;

	init_mlx_and_new_image(data);
	init_txt_menu(data);
	init_txt_menu_option(data, data->menu_option);
	data->fps = 0;
	data->menu_option->but_rtn = init_button();
	data->but_option = init_button();
	init_menu_option(data);
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
	data->but_play = init_button();
	data->but_exit = init_button();
	init_game(data);
}

void	print_map(t_map *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
	{
		check_space(data->map, i, '2', '1');
		ft_printf("%s", data->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	data;
	t_opt	option;

	data.menu_option = &option;
	data.nmb_door = 0;
	init_null(&data);
	main_parsing(argc, argv);
	init_struct(argv, &data);
	init_door(&data);
	data.weapon.barrel.walk.nb_textures = 0;
	data.weapon.e11.walk.nb_textures = 0;
	data.weapon.item.textures = NULL;
	data.weapon.selected = NULL;
	data.weapon.center_txt = NULL;
	data.weapon.center = NULL;
	data.font.nb_textures = 0;
	print_map(&data);
	cub3d(&data);
	if (data.menu_option->play_music)
		system("killall paplay");
	return (0);
}
