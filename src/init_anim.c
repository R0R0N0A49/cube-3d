/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/10/15 14:10:56 by trebours         ###   ########.fr       */
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

static void	init_txt(t_textures *weapone, char *path)
{
	long unsigned int	i;
	char				*path_final;

	i = 0;
	while (i < weapone->nb_textures)
	{
		path_final = ft_strjoin(path, weapone->textures_name[i]);
		weapone->textures[i] = mlx_load_png(path_final);
		free(path_final);
		if (!weapone->textures[i])
			ft_error();
		i++;
	}
}

static void	init_img(t_map *data, t_textures *weapone)
{
	long unsigned int	i;

	i = 0;
	while (i < weapone->nb_textures)
	{
		weapone->image[i] = mlx_texture_to_image(data->mlx,
				weapone->textures[i]);
		mlx_resize_image(weapone->image[i], weapone->image[i]->width * 1.7,
			weapone->image[i]->height * 1.7);
		if (!weapone->image[i])
			ft_error();
		mlx_image_to_window(data->mlx, weapone->image[i], (int32_t)(
				(float)(WINDOWSW - weapone->image[0]->width) / 2),
			WINDOWSH - weapone->image[0]->height);
		weapone->image[i]->enabled = false;
		i++;
	}
}

void	init_anim(t_map *data)
{
	data->weapone.enable_anim = true;
	data->weapone.enable_knife = true;
	data->weapone.fire = false;
	data->weapone.time_anime = get_time();
	data->weapone.index_barel_walk = 0;
	data->weapone.barel_walk = init_txtr(30);
	data->weapone.barel_fire = init_txtr(9);
	data->weapone.center_txt = mlx_load_png("tiles/animation/center.png");
	data->weapone.center = mlx_texture_to_image(data->mlx,
			data->weapone.center_txt);
	data->weapone.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapone.center,
		(int)(WINDOWSW - data->weapone.center->width) / 2,
		(int)(WINDOWSH - data->weapone.center->height) / 2);
	init_name_barel_walk(&data->weapone.barel_walk);
	init_name_barel_fire(&data->weapone.barel_fire);
	init_txt(&data->weapone.barel_walk, "tiles/animation"
		"/DOUBLE BARREL/WALKING/");
	init_img(data, &data->weapone.barel_walk);
	init_txt(&data->weapone.barel_fire, "tiles/animation"
		"/DOUBLE BARREL/FIREING/");
	init_img(data, &data->weapone.barel_fire);
}
