/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/08/29 15:48:49 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_null(t_map *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->down = NULL;
	data->up = NULL;
}

void	init_mini_null(t_mini *map, mlx_t *mlx)
{
	map->red_t = mlx_load_png("tiles/red.png");
	map->white_t = mlx_load_png("tiles/white.png");
//	map->player_t = mlx_load_png("tiles/player.png");
	map->red = mlx_texture_to_image(mlx, map->red_t);
	map->white = mlx_texture_to_image(mlx, map->white_t);
//	map->player = mlx_texture_to_image(mlx, map->player_t);
	map->player = mlx_new_image(mlx, 10, 10);
}

void	destroy_mini(t_mini *map, mlx_t *mlx)
{
	mlx_delete_image(mlx, map->player);
	mlx_delete_image(mlx, map->red);
	mlx_delete_image(mlx, map->white);
	mlx_delete_texture(map->player_t);
	mlx_delete_texture(map->red_t);
	mlx_delete_texture(map->white_t);
}

void	cub3d(t_map *data)
{
	(void)data;
//	mlx_t *mlx;
	t_mini	map;

	data->mlx = mlx_init(1920,1080, "cub3d", true);
	init_mini_null(&map, data->mlx);
	data->mini_map = &map;
	mini_map(data, data->mlx);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
	destroy_mini(&map, data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_map	data;

	init_null(&data);
	main_parsing(argc, argv);
	init_struct(argv, &data);
	cub3d(&data);
	free_struct(&data);
	return (0);
}
