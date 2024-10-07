/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:53 by trebours          #+#    #+#             */
/*   Updated: 2024/10/07 16:43:59 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE); // ajouter tout les free avant de quitter
}

static void	init_name(t_map *data)
{
	data->weapone.knife.textures_name[0] = ft_strdup("tiles/animation/knife_pos_0.png");
	data->weapone.knife.textures_name[1] = ft_strdup("tiles/animation/knife_pos_1.png");
	data->weapone.knife.textures_name[2] = ft_strdup("tiles/animation/knife_pos_2.png");
}

static void init_txt(t_textures *knife)
{
	long unsigned int	i;

	i = 0;
	while (i < knife->nb_textures)
	{
		knife->textures[i] = mlx_load_png(knife->textures_name[i]);
		if (!knife->textures[i])
			ft_error();
		i++;
	}
}

static void	init_img(t_map *data, t_textures *knife)
{
	long unsigned int	i;

	i = 0;
	while (i < knife->nb_textures)
	{
		knife->image[i] = mlx_texture_to_image(data->mlx, knife->textures[i]);
		if (!knife->image[i])
			ft_error();
		mlx_image_to_window(data->mlx, knife->image[i], 255, 255);
		i++;
	}
}

void	init_anim(t_map *data)
{
	data->weapone.enable_anim = false;
	data->weapone.enable_knife = false;
	data->weapone.knife = init_txtr(3);
	init_name(data);
	init_txt(&data->weapone.knife);
	init_img(data, &data->weapone.knife);
}

