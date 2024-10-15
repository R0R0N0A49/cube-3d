/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/10/15 13:15:09 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE); // ajouter tout les free avant de quitter
}

static void	init_name_barel_walk(t_map *data)
{
	data->weapone.barel_walk.textures_name[0] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/01.png");
	data->weapone.barel_walk.textures_name[1] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/02.png");
	data->weapone.barel_walk.textures_name[2] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/03.png");
	data->weapone.barel_walk.textures_name[3] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/04.png");
	data->weapone.barel_walk.textures_name[4] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/05.png");
	data->weapone.barel_walk.textures_name[5] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/06.png");
	data->weapone.barel_walk.textures_name[6] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/07.png");
	data->weapone.barel_walk.textures_name[7] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/08.png");
	data->weapone.barel_walk.textures_name[8] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/09.png");
	data->weapone.barel_walk.textures_name[9] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/10.png");
	data->weapone.barel_walk.textures_name[10] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/11.png");
	data->weapone.barel_walk.textures_name[11] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/12.png");
	data->weapone.barel_walk.textures_name[12] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/13.png");
	data->weapone.barel_walk.textures_name[13] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/14.png");
	data->weapone.barel_walk.textures_name[14] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/15.png");
	data->weapone.barel_walk.textures_name[15] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/16.png");
	data->weapone.barel_walk.textures_name[16] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/17.png");
	data->weapone.barel_walk.textures_name[17] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/18.png");
	data->weapone.barel_walk.textures_name[18] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/19.png");
	data->weapone.barel_walk.textures_name[19] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/20.png");
	data->weapone.barel_walk.textures_name[20] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/21.png");
	data->weapone.barel_walk.textures_name[21] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/22.png");
	data->weapone.barel_walk.textures_name[22] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/23.png");
	data->weapone.barel_walk.textures_name[23] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/24.png");
	data->weapone.barel_walk.textures_name[24] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/25.png");
	data->weapone.barel_walk.textures_name[25] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/26.png");
	data->weapone.barel_walk.textures_name[26] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/27.png");
	data->weapone.barel_walk.textures_name[27] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/28.png");
	data->weapone.barel_walk.textures_name[28] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/29.png");
	data->weapone.barel_walk.textures_name[29] = ft_strdup("tiles/animation/DOUBLE BARREL/WALKING/30.png");
}

void init_name_barel_fire(t_map *data)
{
	data->weapone.barel_fire.textures_name[0] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/1.png");
	data->weapone.barel_fire.textures_name[1] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/2.png");
	data->weapone.barel_fire.textures_name[2] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/3.png");
	data->weapone.barel_fire.textures_name[3] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/4.png");
	data->weapone.barel_fire.textures_name[4] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/5.png");
	data->weapone.barel_fire.textures_name[5] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/6.png");
	data->weapone.barel_fire.textures_name[6] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/7.png");
	data->weapone.barel_fire.textures_name[7] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/8.png");
	data->weapone.barel_fire.textures_name[8] = ft_strdup("tiles/animation/DOUBLE BARREL/FIREING/9.png");
}

static void init_txt(t_textures *weapone)
{
	long unsigned int	i;

	i = 0;
	while (i < weapone->nb_textures)
	{
		weapone->textures[i] = mlx_load_png(weapone->textures_name[i]);
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
		weapone->image[i] = mlx_texture_to_image(data->mlx, weapone->textures[i]);
		mlx_resize_image(weapone->image[i], weapone->image[i]->width * 1.7, weapone->image[i]->height * 1.7);
		if (!weapone->image[i])
			ft_error();
		mlx_image_to_window(data->mlx, weapone->image[i], (int32_t)((float)(WINDOWSW - weapone->image[0]->width) / 2), WINDOWSH - weapone->image[0]->height);
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
	data->weapone.center = mlx_texture_to_image(data->mlx, data->weapone.center_txt);
	data->weapone.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapone.center, (int)(WINDOWSW - data->weapone.center->width) / 2,(int)(WINDOWSH - data->weapone.center->height) / 2 );
	init_name_barel_walk(data);
	init_name_barel_fire(data);
	init_txt(&data->weapone.barel_walk);
	init_img(data, &data->weapone.barel_walk);
	init_txt(&data->weapone.barel_fire);
	init_img(data, &data->weapone.barel_fire);
}

