/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/10/16 14:12:56 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE); // ajouter tout les free avant de quitter
}

static void	init_name_barel_walk_2(t_textures *barel)
{
	barel->textures_name[23] = ft_strdup("24.png");
	barel->textures_name[24] = ft_strdup("25.png");
	barel->textures_name[25] = ft_strdup("26.png");
	barel->textures_name[26] = ft_strdup("27.png");
	barel->textures_name[27] = ft_strdup("28.png");
	barel->textures_name[28] = ft_strdup("29.png");
	barel->textures_name[29] = ft_strdup("30.png");
}

static void	init_name_barel_walk(t_textures *barel)
{
	barel->textures_name[0] = ft_strdup("01.png");
	barel->textures_name[1] = ft_strdup("02.png");
	barel->textures_name[2] = ft_strdup("03.png");
	barel->textures_name[3] = ft_strdup("04.png");
	barel->textures_name[4] = ft_strdup("05.png");
	barel->textures_name[5] = ft_strdup("06.png");
	barel->textures_name[6] = ft_strdup("07.png");
	barel->textures_name[7] = ft_strdup("08.png");
	barel->textures_name[8] = ft_strdup("09.png");
	barel->textures_name[9] = ft_strdup("10.png");
	barel->textures_name[10] = ft_strdup("11.png");
	barel->textures_name[11] = ft_strdup("12.png");
	barel->textures_name[12] = ft_strdup("13.png");
	barel->textures_name[13] = ft_strdup("14.png");
	barel->textures_name[14] = ft_strdup("15.png");
	barel->textures_name[15] = ft_strdup("16.png");
	barel->textures_name[16] = ft_strdup("17.png");
	barel->textures_name[17] = ft_strdup("18.png");
	barel->textures_name[18] = ft_strdup("19.png");
	barel->textures_name[19] = ft_strdup("20.png");
	barel->textures_name[20] = ft_strdup("21.png");
	barel->textures_name[21] = ft_strdup("22.png");
	barel->textures_name[22] = ft_strdup("23.png");
	init_name_barel_walk_2(barel);
}

static void	init_name_barel_fire(t_textures *barel)
{
	barel->textures_name[0] = ft_strdup("1.png");
	barel->textures_name[1] = ft_strdup("2.png");
	barel->textures_name[2] = ft_strdup("3.png");
	barel->textures_name[3] = ft_strdup("4.png");
	barel->textures_name[4] = ft_strdup("5.png");
	barel->textures_name[5] = ft_strdup("6.png");
	barel->textures_name[6] = ft_strdup("7.png");
	barel->textures_name[7] = ft_strdup("8.png");
	barel->textures_name[8] = ft_strdup("9.png");
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
		mlx_image_to_window(data->mlx, weapon->image[i],((WINDOWSW - weapon->image[0]->width) / 2),
			WINDOWSH - weapon->image[0]->height);
		weapon->image[i]->enabled = false;
		i++;
	}
}

void	init_anim(t_map *data)
{
	data->weapon.enable_anim = true;
	data->weapon.enable_knife = true;
	data->weapon.fire = false;
	data->weapon.time_anime = get_time();
	data->weapon.index_barel_walk = 0;
	data->weapon.barel_walk = init_txtr(30);
	data->weapon.barel_fire = init_txtr(9);
	data->weapon.center_txt = mlx_load_png("tiles/animation/center.png");
	data->weapon.center = mlx_texture_to_image(data->mlx,
			data->weapon.center_txt);
	data->weapon.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapon.center,
		(int)(WINDOWSW - data->weapon.center->width) / 2,
		(int)(WINDOWSH - data->weapon.center->height) / 2);
	init_name_barel_walk(&data->weapon.barel_walk);
	init_name_barel_fire(&data->weapon.barel_fire);
	init_txt(&data->weapon.barel_walk, "tiles/animation"
		"/DOUBLE BARREL/WALKING/");
	init_img(data, &data->weapon.barel_walk);
	init_txt(&data->weapon.barel_fire, "tiles/animation"
		"/DOUBLE BARREL/FIREING/");
	init_img(data, &data->weapon.barel_fire);
}
