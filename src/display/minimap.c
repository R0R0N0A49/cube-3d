/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:43:18 by derey             #+#    #+#             */
/*   Updated: 2024/10/21 10:12:50 by derey            ###   ########.fr       */
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

void	draw_player(t_map *data, double i, double j, uint32_t te)
{
	double	a;
	double	b;
	double	c;

	a = i + 4;
	b = j + 4;
	c = j;
	(void) data;
	while (i <= a)
	{
		j = c;
		while (j <= b)
		{
			mlx_put_pixel(data->minima, i, j, te);
			j++;
		}
		i++;
	}
	//draw_grid(data, a, b, te);
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
	//draw_grid(data, a, b, te);
}

void	draw_circle(t_map *data, int yc, int xc, int radius)
{
	int x = radius;
    int y = 0;
    int p = 1 - radius;

    // Dessiner les points initiaux pour les 8 octants
    mlx_put_pixel(data->minima, xc + radius, yc, 0xFFFF);  // A droite
    mlx_put_pixel(data->minima, xc - radius, yc, 0xFFFF);  // A gauche
    mlx_put_pixel(data->minima, xc, yc + radius, 0xFFFF);  // En haut
    mlx_put_pixel(data->minima, xc, yc - radius, 0xFFFF);  // En bas

    while (x > y) {
        y++;

        // Vérifier si on doit incrémenter ou décrémenter x
        if (p <= 0) {
            p = p + 2*y + 1;
        } else {
            x--;
            p = p + 2*y - 2*x + 1;
        }

        // Dessiner les points symétriques dans les 8 octants
        mlx_put_pixel(data->minima, xc + x, yc + y, 0xFFFF);
        mlx_put_pixel(data->minima, xc - x, yc + y, 0xFFFF);
        mlx_put_pixel(data->minima, xc + x, yc - y, 0xFFFF);
        mlx_put_pixel(data->minima, xc - x, yc - y, 0xFFFF);
        mlx_put_pixel(data->minima, xc + y, yc + x, 0xFFFF);
        mlx_put_pixel(data->minima, xc - y, yc + x, 0xFFFF);
        mlx_put_pixel(data->minima, xc + y, yc - x, 0xFFFF);
        mlx_put_pixel(data->minima, xc - y, yc - x, 0xFFFF);
    }
	
}

void draw_circle_with_thickness(t_map *data, int xc, int yc, int radius, int thickness) {
    for (int r = radius; r >= radius - thickness + 1; r--) {
        draw_circle(data ,xc, yc, r);
    }
}

void	loop_top(t_map *data, int j, int i)
{
//	int	save;

//	save = i;
	(void)j;
	(void)i;
	draw_circle_with_thickness(data, 150, 150, 100, 2);
	draw_player(data, 150, 150, 0xFFFF);
	/*while (data->map[j])
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
				draw_cube(data, i * CUBE, j * CUBE, 0xFFFFFF);
			else
				draw_cube(data, i * CUBE, j * CUBE, 0x00000000);
			i++;
		}
		j++;
	}*/
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
	//draw_player(data, data->game->player_x * CUBE, data->game->player_y * CUBE, 0xFFFF);
}
