/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/10/16 15:20:56 by trebours         ###   ########.fr       */
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
	data->weapone.enable_anim = false;
	data->weapone.barrel.enable = true;
	data->weapone.nb_availed_weapon = 1;
	data->weapone.index_weapon = 1;
	data->weapone.fire = false;
	data->weapone.time = get_time();
	data->weapone.barrel.index_fire = 0;
	data->weapone.barrel.index_walk = 0;
	data->weapone.barrel.index_reload = 0;
	data->weapone.barrel.ammo_max = 2;
	data->weapone.barrel.ammo = 2;
	data->weapone.barrel.walk = init_txtr(4);
	data->weapone.barrel.fired = init_txtr(4);
	data->weapone.barrel.reload = init_txtr(5);
	data->weapone.center_txt = mlx_load_png("tiles/animation/center.png");
	data->weapone.center = mlx_texture_to_image(data->mlx,
			data->weapone.center_txt);
	data->weapone.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapone.center,
		(int)(WINDOWSW - data->weapone.center->width) / 2,
		(int)(WINDOWSH - data->weapone.center->height) / 2);
	init_name(&data->weapone.barrel.walk, 4);
	init_name(&data->weapone.barrel.fired, 4);
	init_name(&data->weapone.barrel.reload, 5);
	init_txt(&data->weapone.barrel.walk, "tiles/animation"
		"/DOUBLE BARREL/WALKING/");
	init_img(data, &data->weapone.barrel.walk);
	init_txt(&data->weapone.barrel.fired, "tiles/animation"
		"/DOUBLE BARREL/FIREING/");
	init_img(data, &data->weapone.barrel.fired);
	init_txt(&data->weapone.barrel.reload, "tiles/animation"
		"/DOUBLE BARREL/RELOADING/");
	init_img(data, &data->weapone.barrel.reload);
}
