/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 16:42:22 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(t_map *data)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	free_at_end(data);
	exit(EXIT_FAILURE);
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

static void	init_txt(t_textures *weapon, char *path, t_map *data)
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
			ft_error(data);
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
			ft_error(data);
		mlx_image_to_window(data->mlx, weapon->image[i], (int32_t)(
				(float)(WINDOWSW - weapon->image[0]->width) / 2),
			WINDOWSH - weapon->image[0]->height);
		weapon->image[i]->enabled = false;
		i++;
	}
}

void	init_anim(t_map *data)
{
	init_item(&data->weapon.item, data);
	data->weapon.time = get_time();
	data->weapon.enable_anim = true;
	data->weapon.nb_availed_weapon = 1;
	data->weapon.barrel.index_walk = 0;
	data->weapon.e11.index_walk = 0;
	data->weapon.barrel.walk = init_txtr(4, data);
	data->weapon.e11.walk = init_txtr(4, data);
	data->weapon.center_txt = mlx_load_png("tiles/animation/center.png");
	data->weapon.center = mlx_texture_to_image(data->mlx,
			data->weapon.center_txt);
	data->weapon.center->enabled = false;
	mlx_image_to_window(data->mlx, data->weapon.center,
		(int)(WINDOWSW - data->weapon.center->width) / 2,
		(int)(WINDOWSH - data->weapon.center->height) / 2);
	init_name(&data->weapon.barrel.walk, 4);
	init_name(&data->weapon.e11.walk, 4);
	init_txt(&data->weapon.barrel.walk, "tiles/animation/DOUBLE BARREL/", data);
	init_img(data, &data->weapon.barrel.walk);
	init_txt(&data->weapon.e11.walk, "tiles/animation/E11/", data);
	init_img(data, &data->weapon.e11.walk);
}
