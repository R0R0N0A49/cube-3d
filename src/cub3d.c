/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/09/16 09:16:11 by derey            ###   ########.fr       */
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
	if (data->down)
		free(data->down);
	if (data->up)
		free(data->up);
	if (data->map)
		ft_free_stringtab(data->map);
	return (1);
}

void	close_wind(mlx_key_data_t keycode, void *param)
{
	(void)keycode;
	mlx_t *mlx = (mlx_t *)param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(mlx, MLX_KEY_Q))
	{
		mlx_close_window(mlx);
	}
}

void	mini_map(t_map *data, mlx_t *mlx)
{
	int	i;
	int	j = 0;

	(void)mlx;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				||  data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				data->mini_map->pos_x = i;
				data->mini_map->pos_y = j;
				break;
			}
			i++;
		}
		j++;
	}
}

void	cub3d(t_map *data)
{
	(void)data;
	t_mini	map;
	t_ray	raycast;

	data->mlx = mlx_init(WINDOWSW,WINDOWSH, "cub3d", true);
	data->rayc = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->minima = mlx_new_image(data->mlx, WINDOWSW, WINDOWSH);
	data->mini_map = &map;
	data->raycast = &raycast;
	data->raycast->wallH = 500;
	data->raycast->wallW = WINDOWSW;
	mini_map(data, data->mlx);
	mlx_image_to_window(data->mlx, data->rayc, 0, 0);
	mlx_image_to_window(data->mlx, data->minima, 0, 0);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	data;

	init_null(&data);
	main_parsing(argc, argv);
	init_struct(argv, &data);
	i = 0;
	while (data.map && data.map[i])
	{
		ft_printf("%s", data.map[i]);
		i++;
	}
	cub3d(&data);
	free_struct(&data);
	return (0);
}
