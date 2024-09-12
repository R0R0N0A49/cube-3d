/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:43:18 by derey             #+#    #+#             */
/*   Updated: 2024/09/12 13:40:21 by derey            ###   ########.fr       */
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

void loop_bot(t_map *data, int j, int i)
{
    int save;
    int istat;
    int jstat;
    int test;
    int test2;

    jstat = 0;
    test = data->mini_map->pos_y;
    test2 = data->mini_map->pos_x;
    save = i;
    if (j == 0)
        test = data->len_col - ARROUND;
    if (i == 0)
        test2 = data->len_line - ARROUND;
    while (data->map[j])
    {
        i = save;
        istat = 0;
        while (data->map[j][i])
        {
            if (data->map[j][i] == '1' && i <= test2 + ARROUND && j <= test + ARROUND)
                draw_cube(data, istat++ * H_CUBE , jstat * W_CUBE , 0xFA1);
            else if (data->map[j][i] == '0' && i <= test2 + ARROUND && j <= test + ARROUND)
                draw_cube(data, istat++ * H_CUBE , jstat * W_CUBE , 0xCCFF9999);
            else if ((data->map[j][i] == 'N' || data->map[j][i] == 'S' || data->map[j][i] == 'E' || data->map[j][i] == 'W') && i <= test2 + ARROUND && j <= test + ARROUND)
                draw_cube(data, istat++ * H_CUBE, jstat * W_CUBE, 0xCCFF9999);
            else
                draw_cube(data, istat++ * H_CUBE , jstat * W_CUBE, 0x00000000);
            i++;
        }
        jstat++;
        j++;
    }
}

void loop_top(t_map *data, int j, int i)
{
    int save;
    int istat;
    int jstat;
    int test;
    int test2;

    jstat = 0;
    test = data->mini_map->pos_y;
    test2 = data->mini_map->pos_x;
    save = i;
    if (j == 0)
        test = ARROUND;
    if (i == 0)
        test2 = ARROUND;
    while (data->map[j])
    {
        i = save;
        istat = 0;
        while (data->map[j][i])
        {
            if (data->map[j][i] == '1' && i <= test2 + ARROUND && j <= test + ARROUND)
                draw_cube(data, istat++ * H_CUBE , jstat * W_CUBE , 0xFA1);
            else if (data->map[j][i] == '0' && i <= test2 + ARROUND && j <= test + ARROUND)
                draw_cube(data, istat++ * H_CUBE , jstat * W_CUBE , 0xCCFF9999);
            else if ((data->map[j][i] == 'N' || data->map[j][i] == 'S' || data->map[j][i] == 'E' || data->map[j][i] == 'W') && i <= test2 + ARROUND && j <= test + ARROUND)
                draw_cube(data, istat++ * H_CUBE, jstat * W_CUBE, 0xCCFF9999);
            else
                draw_cube(data, istat++ * H_CUBE , jstat * W_CUBE, 0x00000000);
            i++;
        }
        jstat++;
        j++;
    }
}

void	mini(t_map *data, mlx_t *mlx)
{
    int i;
    int j;
    int save;
    int istat;
    int jstat;
    
    data->mini_map->end_map = 0;
    data->len_col = data->len_map - 1;
    data->len_line = ft_strlen(data->map[data->mini_map->pos_y]) - 1;
    i = -6;
    j = -6;
    system("clear");
    usleep(1);
    printf("<pos Y = %d, pos X = %d, case = %c>\n", ((data->game->triangle_y - 5) / 20), ((data->game->triangle_x - 10) / 20), data->map[((data->game->triangle_y - 5) / 20)][((data->game->triangle_x - 10) / 20)]);
    printf("<map Y = %d, map X = %d, case = %c>\n", data->mini_map->pos_y, data->mini_map->pos_x, data->map[data->mini_map->pos_y][data->mini_map->pos_x]);
    printf("longueur line = %d, longueur colone = %d\n", data->len_line, data->len_col);
   /* if (data->mini_map->pos_y + ARROUND >= data->len_col && ((data->game->triangle_y - 5) / 20) < 7)
    {
        j = data->len_col - ARROUND * 2;
        if (data->game->moove == 2 && data->mini_map->pos_y + ARROUND > data->len_col && data->map[((data->game->triangle_y - 5) / 20) + 1][data->mini_map->pos_x] != '1')
        {
            ft_printf("down\n");
            data->game->moove = 0;
            data->game->triangle_y += H_CUBE;
        }
    }
    else*/ if (data->mini_map->pos_y < ARROUND && ((data->game->triangle_y - 5) / 20) > 1 && data->map[((data->game->triangle_y - 5) / 20) - 1][data->mini_map->pos_x] != '1')
    {
        j = 0;
        ft_printf("1\n");
        if (data->game->moove == 1)
        {
            ft_printf("up\n");
            data->game->triangle_y -= H_CUBE;
            data->game->moove = 0;
        }
    }
    else if (data->game->triangle_y <= (H_CUBE * ARROUND))
    {
        j = 0;
        ft_printf("2\n");
        if (data->game->moove == 2 && data->map[data->mini_map->pos_y + 1][data->mini_map->pos_x] != '1')
        {
            ft_printf("down\n");
            data->game->moove = 0;
            data->game->triangle_y += H_CUBE;
        }
    }
    else if (data->mini_map->pos_x <= ARROUND && ((data->game->triangle_x - 10) / 20) > 1 && data->map[data->mini_map->pos_y][((data->game->triangle_y - 10) / 20) - 1] != '1')
    {
        i = 0;
        ft_printf("3\n");
        if (data->game->moove == 3)
        {
            data->game->triangle_x -= H_CUBE;
            data->game->moove = 0;
        }
    }
    else if (data->game->triangle_x  <= (H_CUBE * ARROUND))
    {
        i = 0;
        ft_printf("4\n");
        if (data->game->moove == 4 && data->map[data->mini_map->pos_y][data->mini_map->pos_x + 1] != '1')
        {
            data->game->moove = 0;
            data->game->triangle_x += H_CUBE;
        }
    }
    else
    {
        if (i == -6)
            i = data->mini_map->pos_x - ARROUND;
        if (j == -6)
            j = data->mini_map->pos_y - ARROUND;
    }
    if (((data->game->triangle_y - 5) / 20) <= 1 || j <= 0)
        j = 0;
    if (((data->game->triangle_x - 10) / 20) <= 1 || i <= 0)
        i = 0;
    jstat = 0;
	(void)mlx;
    save = i;
    while (data->map[jstat])
    {
        istat = 0;
        while (data->map[jstat][istat])
        {
            draw_cube(data, istat * H_CUBE , jstat * W_CUBE, 0x00000000);
            istat++;
        }
        jstat++;
    }
    jstat = 0;
    if ((j == 0 || i == 0) && data->mini_map->end_map == 0)
        loop_top(data, j, i);
    else if (data->mini_map->end_map == 1)
        loop_bot(data, j, i);
    else
    {
        ft_printf("test2\n");
        while (data->map[j])
        {
            i = save;
            istat = 0;
            while (data->map[j][i])
            {
                if (istat == ((data->game->triangle_x - 10) / 20) && jstat == ((data->game->triangle_y - 5) / 20))
                    ft_printf("\033[0;32m^\033[0m");
                if (data->map[j][i] == '1' && i <= data->mini_map->pos_x + ARROUND && j <= data->mini_map->pos_y + ARROUND)
                {
                    ft_printf("1");
                    draw_cube(data, istat * H_CUBE , jstat * W_CUBE , 0xFA1);
                    istat++;
                }
                else if (data->map[j][i] == '0' && i <= data->mini_map->pos_x + ARROUND && j <= data->mini_map->pos_y + ARROUND)
                {
                    if (istat != ((data->game->triangle_x - 10) / 20) || jstat != ((data->game->triangle_y - 5) / 20))
                        ft_printf("0");
                    draw_cube(data, istat * H_CUBE , jstat * W_CUBE , 0xCCFF9999);
                    istat++;
                }
                else if ((data->map[j][i] == 'N' || data->map[j][i] == 'S' ||  data->map[j][i] == 'E' || data->map[j][i] == 'W') && i <= data->mini_map->pos_x + ARROUND && j <= data->mini_map->pos_y + ARROUND)
                {
                    if (istat != 3 || jstat != 3)
                        ft_printf("S");
                    draw_cube(data, istat * H_CUBE, jstat * W_CUBE, 0xCCFF9999);
                    istat++;
                }
                else
                {
                    ft_printf(" ");
                    draw_cube(data, istat * H_CUBE , jstat * W_CUBE, 0x00000000);
                    istat++;
                }
                i++;
            }
            ft_printf("\n");
            jstat++;
            j++;
        }
    }
	
}
