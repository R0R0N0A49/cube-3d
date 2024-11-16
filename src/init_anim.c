/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/11/08 10:03:29 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE); // ajouter tout les free avant de quitter
}

static void	init_name(t_textures *weapon, int nmb)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i <= nmb)
	{
		tmp = ft_itoa(i);
		weapon->textures_name[i - 1] = ft_strjoin(tmp, ".png");
		free(tmp);
		i++;
	}
}

static void	init_txt(t_textures *weapon, char *path)
{
	long unsigned int	i;
	char				*path_final;

	i = 0;
	while (i < weapon->nb_textures)
	{
		path_final = ft_strjoin(path, weapon->textures_name[i]);
		weapon->textures[i] = mlx_load_png(path_final);
		free(path_final);
		if (!weapon->textures[i])
			ft_error();
		i++;
	}
}

static void	init_img(t_map *data, t_textures *weapon)
{
	long unsigned int	i;

	i = 0;
	while (i < weapon->nb_textures)
	{
		weapon->image[i] = mlx_texture_to_image(data->mlx,
				weapon->textures[i]);
		mlx_resize_image(weapon->image[i], weapon->image[i]->width * 1.7,
			weapon->image[i]->height * 1.7);
		if (!weapon->image[i])
			ft_error();
		mlx_image_to_window(data->mlx, weapon->image[i], (int32_t)(
				(float)(WINDOWSW - weapon->image[0]->width) / 2),
			WINDOWSH - weapon->image[0]->height);
		weapon->image[i]->enabled = false;
		i++;
	}
}

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
	item->dist = 0.0;
	item->posx = 31.5;
	item->posy = 2.5;
//	creat_pos_item(item, data);
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
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("tiles/animation/item/pm_item.png");
	info_item(tmp, data, 1);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("tiles/animation/item/ammo.png");
	info_item(tmp, data, 2);
	mlx_delete_texture(tmp);
}

void	init_anim(t_map *data)
{
	data->weapon.time = get_time();
	data->weapon.enable_anim = true;
	data->weapon.nb_availed_weapon = 1;
	data->weapon.barrel.index_walk = 0;
	data->weapon.e11.index_walk = 0;
	data->weapon.barrel.walk = init_txtr(4);
	data->weapon.e11.walk = init_txtr(4);
	data->weapon.center_txt = mlx_load_png("tiles/animation/center.png");
	data->weapon.center = mlx_texture_to_image(data->mlx,
			data->weapon.center_txt);
	data->weapon.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapon.center,
		(int)(WINDOWSW - data->weapon.center->width) / 2,
		(int)(WINDOWSH - data->weapon.center->height) / 2);
	init_name(&data->weapon.barrel.walk, 4);
	init_name(&data->weapon.e11.walk, 4);
	init_txt(&data->weapon.barrel.walk, "tiles/animation/DOUBLE BARREL/");
	init_img(data, &data->weapon.barrel.walk);
	init_txt(&data->weapon.e11.walk, "tiles/animation/E11/");
	init_img(data, &data->weapon.e11.walk);
	init_item(&data->weapon.item, data);
}
