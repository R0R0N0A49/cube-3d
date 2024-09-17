/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/09/17 17:10:30 by derey            ###   ########.fr       */
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
	data->map = NULL;
}

static void	ft_free_stringtab(char **src)
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
	// if (data->down)
		// free(data->down);
	// if (data->up)
		// free(data->up);
	if (data->map)
		ft_free_stringtab(data->map);
	return (1);
}

void	close_wind(mlx_key_data_t keycode, void *param)
{
	mlx_t	*mlx;

	(void)keycode;
	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(mlx, MLX_KEY_Q))
	{
		mlx_close_window(mlx);
	}
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

	(void)data;
	data->mlx = mlx_init(WINDOWSW, WINDOWSH, "cub3d", true);
	data->rayc = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->minima = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	mlx_set_mouse_pos(data->mlx, WINDOWSW / 2, WINDOWSH / 2);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	data->mini_map = &map;
	data->game = &game;
	data->raycast = &raycast;
	data->speed = 0.069;
	data->rotspeed = 0.035;
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_w = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	mini_map(data, data->mlx);
	mlx_image_to_window(data->mlx, data->rayc, 0, 0);
	mlx_image_to_window(data->mlx, data->minima, 0, 0);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_cursor_hook(data->mlx, cursor, data);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_map	data;

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
	return (0);
}
