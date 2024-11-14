/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/11/08 14:34:17 by derey            ###   ########.fr       */
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
									(float)(WINDOWSW - weapon->image[0]->width) * 0.5),
							WINDOWSH - weapon->image[0]->height);
		weapon->image[i]->enabled = false;
		i++;
	}
}

void	creat_pos_item(t_item *item, t_map *data)
{
	int y;
	int x;

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

void	init_item(t_item *item, t_map *data)
{
	TXT *tmp;

	item->enabled = true;
	item->posy = data->game->player_y - 5;
//	item->posx = 3.5;
	item->posx = data->game->player_x;
//	item->posy = 1.5;
//	creat_pos_item(item, data);
//	data->weapon.index_weapon = 1;
	data->weapon.index_weapon = rand() % 2;
	printf("pos_x = %f / pos_y = %f\n", item->posx, item->posy);
	data->weapon.item.x = -1;
	item->isvisible = false;
	item->index = 0;
	item->textures = calloc(2, sizeof(TXT *));
	if (data->weapon.index_weapon == 0) {
		item->textures[0] = mlx_load_png("tiles/animation/pm.png"); // a free
		item->textures[1] = mlx_load_png("tiles/animation/pm_2.png"); // a free
	}
	else
	{
		item->textures[0] = mlx_load_png("tiles/animation/db.png"); // a free
		item->textures[1] = mlx_load_png("tiles/animation/db_1.png"); // a free
	}
	data->weapon.selected = calloc(3, sizeof(IMG *));
	tmp = mlx_load_png("tiles/animation/db_item.png");
	data->weapon.selected[0] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("tiles/animation/pm_item.png");
	data->weapon.selected[1] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("tiles/animation/ammo.png");
	data->weapon.selected[2] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	data->weapon.selected[0]->enabled = false;
	data->weapon.selected[1]->enabled = false;
	data->weapon.selected[2]->enabled = false;
	mlx_image_to_window(data->mlx, data->weapon.selected[0], WINDOWSW - 256, WINDOWSH - 256);
	mlx_image_to_window(data->mlx, data->weapon.selected[1], WINDOWSW - 256, WINDOWSH - 256);
	mlx_image_to_window(data->mlx, data->weapon.selected[2], WINDOWSW - 175, WINDOWSH - 128);
}

void	init_anim(t_map *data)
{
	data->weapon.time = get_time();
	data->weapon.enable_anim = true;
	data->weapon.nb_availed_weapon = 1;
	data->weapon.fire = false;
	data->weapon.barrel.enable = true;
	data->weapon.e11.enable = false;
	data->weapon.barrel.index_walk = 0;
	data->weapon.e11.index_walk = 0;
	data->weapon.barrel.walk = init_txtr(4);
	data->weapon.e11.walk = init_txtr(4);
	data->weapon.center_txt = mlx_load_png("tiles/animation/center.png");
	data->weapon.center = mlx_texture_to_image(data->mlx,
			data->weapon.center_txt);
	data->weapon.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapon.center,
		(int)(WINDOWSW - data->weapon.center->width) * 0.5,
		(int)(WINDOWSH - data->weapon.center->height) * 0.5);
	init_name(&data->weapon.barrel.walk, 4);
	init_name(&data->weapon.e11.walk, 4);
	init_txt(&data->weapon.barrel.walk, "tiles/animation/DOUBLE BARREL/");
	init_img(data, &data->weapon.barrel.walk);
	init_txt(&data->weapon.e11.walk, "tiles/animation/E11/");
	init_img(data, &data->weapon.e11.walk);
	init_item(&data->weapon.item, data);
}
