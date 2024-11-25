/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/11/19 12:57:58 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static void	loop(void *param)
{
	t_map	*data;

	data = (t_map *)param;
	raycasting(data);
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
}

void	cub3d(t_map *data)
{
	t_ray			raycast;
	t_game			game;
	mlx_texture_t	*logo;

	data->mlx = mlx_init(WINDOWSW, WINDOWSH, "Cub3d", true);
	data->rayc = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	mlx_set_mouse_pos(data->mlx, WINDOWSW * 0.5, WINDOWSH * 0.5);
	logo = mlx_load_png("./tiles/logo.png");
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_DECORATED, false);
	mlx_set_icon(data->mlx, logo);
	mlx_delete_texture(logo);
	data->game = &game;
	data->raycast = &raycast;
	data->speed = 2.0;
	data->rotspeed = 1.69;
	init_game(data);
	init_player(data);
	mlx_image_to_window(data->mlx, data->rayc, 0, 0);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_map	data;
	int		i;

	init_null(&data);
	main_parsing(argc, argv);
	init_struct(argv, &data);
	i = 0;
	while (data.map && data.map[i])
	{
		check_space(data.map, i, '2', '1');
		ft_printf("%s", data.map[i]);
		i++;
	}
	cub3d(&data);
	free_struct(&data);
	return (0);
}
