/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:40:12 by derey             #+#    #+#             */
/*   Updated: 2024/11/17 16:42:13 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	creat_pos_item(t_item *item, t_map *data)
{
	int	y;
	int	x;

	srand(time(NULL));
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '0')
			{
				if (rand() % 101 == 99)
				{
					item->posx = x + 0.5;
					item->posy = y + 0.5;
					return ;
				}
			}
			x++;
		}
		y++;
	}
	creat_pos_item(item, data);
}

void	info_item(TXT *tmp, t_map *data, int i)
{
	data->weapon.selected[i] = mlx_texture_to_image(data->mlx, tmp);
	data->weapon.selected[i]->enabled = false;
	if (i < 2)
		mlx_image_to_window(data->mlx, data->weapon.selected[i],
			WINDOWSW - 256, WINDOWSH - 256);
	else
		mlx_image_to_window(data->mlx, data->weapon.selected[i],
			WINDOWSW - 175, WINDOWSH - 128);
	mlx_delete_texture(tmp);
}

void	txt_item(char *src, t_item *item)
{
	int		i;
	char	*tmp;
	char	*link;

	i = 0;
	while (i < 2)
	{
		if (i == 0)
			tmp = ft_strjoin(src, ".png");
		else
			tmp = ft_strjoin(src, "_1.png");
		link = ft_strjoin("tiles/animation/item/", tmp);
		free(tmp);
		item->textures[i] = mlx_load_png(link);
		free(link);
		i++;
	}
}

void	init_item(t_item *item, t_map *data)
{
	TXT	*tmp;

	item->enabled = true;
	creat_pos_item(item, data);
	data->weapon.index_weapon = rand() % 2;
	printf("pos_x = %f / pos_y = %f\n", item->posx, item->posy);
	data->weapon.item.x = -1;
	item->isvisible = false;
	item->index = 0;
	item->textures = calloc(2, sizeof(TXT *));
	if (data->weapon.index_weapon == 0)
		txt_item("pm", item);
	else
		txt_item("db", item);
	data->weapon.selected = ft_calloc(3, sizeof(IMG *));
	tmp = mlx_load_png("tiles/animation/item/db_item.png");
	info_item(tmp, data, 0);
//	mlx_delete_texture(tmp);
	tmp = mlx_load_png("tiles/animation/item/pm_item.png");
	info_item(tmp, data, 1);
//	mlx_delete_texture(tmp);
	tmp = mlx_load_png("tiles/animation/item/ammo.png");
	info_item(tmp, data, 2);
//	mlx_delete_texture(tmp);
}
