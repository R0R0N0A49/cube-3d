/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:43:18 by derey             #+#    #+#             */
/*   Updated: 2024/09/16 09:20:39 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_grid(t_map *data, int a, int b, uint32_t te)
{
	int	i;
	int	j;
	int	c;

	if (te != 0x00000000)
	{
		a = a - CUBE;
		b = b - CUBE;
		c = a;
		i = a + CUBE;
		j = b + CUBE;
		while (a <= i)
			mlx_put_pixel(data->minima, a++, b, COLOR_GRID);
		a = c;
		while (a <= i)
			mlx_put_pixel(data->minima, a++, j, COLOR_GRID);
		a = c;
		c = b;
		while (b <= j)
			mlx_put_pixel(data->minima, a, b++, COLOR_GRID);
		b = c;
		while (b <= j)
			mlx_put_pixel(data->minima, i, b++, COLOR_GRID);
	}
}

void	draw_cube(t_map *data, int i, int j, uint32_t te)
{
	int	a;
	int	b;
	int	c;

	a = i + CUBE;
	b = j + CUBE;
	c = j;
	(void) data;
	while (i < a)
	{
		j = c;
		while (j < b)
		{
			mlx_put_pixel(data->minima, i, j, te);
			j++;
		}
		i++;
	}
	draw_grid(data, a, b, te);
}

void	loop_top(t_map *data, int j, int i)
{
	int	save;

	save = i;
	while (data->map[j])
	{
		i = save;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1')
				draw_cube(data, i * CUBE, j * CUBE, 0xFA1);
			else if (data->map[j][i] == '0')
				draw_cube(data, i * CUBE, j * CUBE, 0xCCFF9999);
			else if ((data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W'))
				draw_cube(data, i * CUBE, j * CUBE, 0xCCFF9999);
			else
				draw_cube(data, i * CUBE, j * CUBE, 0x00000000);
			i++;
		}
		j++;
	}
}

void	clean_minimap(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			draw_cube(data, x * CUBE, y * CUBE, 0x00000000);
			x++;
		}
		y++;
	}
}

void	mini(t_map *data)
{
	int	i;
	int	j;

	clean_minimap(data);
	j = 0;
	i = 0;
	loop_top(data, j, i);
}
