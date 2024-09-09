/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:43:18 by derey             #+#    #+#             */
/*   Updated: 2024/09/09 09:41:30 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_cube(t_map *data, int i, int j, uint32_t te)
{
	int	a;
	int	b;
	int c;

	a = i + H_CUBE;
	b = j + W_CUBE;
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
    if (te != 0x00000000)
    {
        a = a - H_CUBE;
        b = b - W_CUBE;
        c = a;
        i = a + H_CUBE;
        j = b + W_CUBE;
        /*while (a <= i)
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
            mlx_put_pixel(data->minima, i, b++, COLOR_GRID);*/
    }
	
	
}

void	mini(t_map *data, mlx_t *mlx)
{
    int i;
    int j;
    int istat;
    int jstat;

    if (data->mini_map->pos_y < ARROUND)
    {
        data->mini_map->pos_y = ARROUND;
        if (data->game->moove == 1)
        {
            data->game->triangle_y -= H_CUBE;
            data->game->moove = 0;
        }
    }
    if (data->mini_map->pos_x < ARROUND)
    {
        data->mini_map->pos_x = ARROUND;
        if (data->game->moove == 3)
        {
            data->game->triangle_x -= H_CUBE;
            data->game->moove = 0;
        }
    }
    if (data->game->triangle_y <= (H_CUBE * ARROUND))
    {
        data->mini_map->pos_y = ARROUND;
        if (data->game->moove == 2)
        {
            data->game->moove = 0;
            data->game->triangle_y += H_CUBE;
        }
    }
    if (data->game->triangle_x  <= (H_CUBE * ARROUND))
    {
        data->mini_map->pos_x = ARROUND;
        if (data->game->moove == 4)
        {
            data->game->moove = 0;
            data->game->triangle_x += H_CUBE;
        }
    }
    j = data->mini_map->pos_y - ARROUND;
    if (j < 0)
        j = 0;
    jstat = 0;
	(void)mlx;
	while (data->map[j])
	{
		i = data->mini_map->pos_x  - ARROUND;
        if (i < 0)
            i = 0;
        istat = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1' && i <= data->mini_map->pos_x + ARROUND && j <= data->mini_map->pos_y + ARROUND)
			{
            	draw_cube(data, istat * H_CUBE , jstat * W_CUBE , 0xFA1);
                istat++;
            }
			else if (data->map[j][i] == '0' && i <= data->mini_map->pos_x + ARROUND && j <= data->mini_map->pos_y + ARROUND)
			{
            	draw_cube(data, istat * H_CUBE , jstat * W_CUBE , 0xCCFF9999);
                istat++;
            }
            else if ((data->map[j][i] == 'N' || data->map[j][i] == 'S' ||  data->map[j][i] == 'E' || data->map[j][i] == 'W') && i <= data->mini_map->pos_x + ARROUND && j <= data->mini_map->pos_y + ARROUND)
            {
                draw_cube(data, istat * H_CUBE, jstat * W_CUBE, 0xCCFF9999);
                istat++;
            }
            else
            {
                draw_cube(data, istat * H_CUBE , jstat * W_CUBE, 0x00000000);
                istat++;
            }
			i++;
		}
        jstat++;
		j++;
	}
}
