/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:30:28 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:09:10 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	free_t_textures(t_textures *src, mlx_t *mlx)
{
	long unsigned int	i;

	i = 0;
	while (i < src->nb_textures && src->textures[i])
		mlx_delete_texture(src->textures[i++]);
	i = 0;
	while (i < src->nb_textures && src->image[i])
		mlx_delete_image(mlx, src->image[i++]);
	i = 0;
	while (i < src->nb_textures && src->textures_name[i])
		free(src->textures_name[i++]);
	free(src->textures_name);
	free(src->textures);
	free(src->image);
}

static void	delete_text(t_map *data)
{
	if (data->font.nb_textures)
		free_t_textures(&data->font, data->mlx);
	if (data->weapon.barrel.walk.nb_textures)
		free_t_textures(&data->weapon.barrel.walk, data->mlx);
	if (data->weapon.barrel.walk.nb_textures)
		free_t_textures(&data->weapon.e11.walk, data->mlx);
	mlx_delete_texture(data->cub);
	mlx_delete_texture(data->cell);
	mlx_delete_texture(data->floor);
	mlx_delete_texture(data->night);
	mlx_delete_texture(data->texopt);
	mlx_delete_texture(data->menufd);
	mlx_delete_texture(data->texplay);
	mlx_delete_texture(data->texexit);
	mlx_delete_texture(data->menufd2);
	mlx_delete_texture(data->menu_option->unvalid_txt);
	mlx_delete_texture(data->menu_option->valid_txt);
	mlx_delete_texture(data->menu_option->rtn_txt);
	mlx_delete_texture(data->menu_option->music_txt);
	mlx_delete_texture(data->menu_option->fps_txt);
	mlx_delete_texture(data->menu_option->roof_txt);
	mlx_delete_texture(data->menu_option->mini_txt);
}

static void	delete_item_door(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->weapon.item.textures)
	{
		while (i < 2 && data->weapon.item.textures[i])
		{
			mlx_delete_texture(data->weapon.item.textures[i]);
			i++;
		}
		free(data->weapon.item.textures);
	}
	i = 0;
	while (i < data->nmb_door)
	{
		j = 0;
		while (j < 14 && data->door[i].door[j])
		{
			mlx_delete_texture(data->door[i].door[j]);
			j++;
		}
		free(data->door[i++].door);
	}
}

static void	free_button(t_map *data)
{
	free(data->menu_option->but_music);
	free(data->menu_option->but_map);
	free(data->menu_option->but_night);
	free(data->menu_option->but_fps);
	free(data->menu_option->but_rtn);
	free(data->but_exit);
	free(data->but_option);
	free(data->but_play);
}

void	free_at_end(t_map *data)
{
	delete_text(data);
	delete_item_door(data);
	mlx_delete_image(data->mlx, data->img_play);
	mlx_delete_image(data->mlx, data->img_exit);
	mlx_delete_image(data->mlx, data->img_option);
	if (data->door)
		free(data->door);
	if (data->weapon.center_txt)
		mlx_delete_texture(data->weapon.center_txt);
	if (data->weapon.center)
		mlx_delete_image(data->mlx, data->weapon.center);
	if (data->weapon.selected)
	{
		mlx_delete_image(data->mlx, data->weapon.selected[0]);
		mlx_delete_image(data->mlx, data->weapon.selected[1]);
		mlx_delete_image(data->mlx, data->weapon.selected[2]);
		free(data->weapon.selected);
	}
	free_button(data);
	mlx_terminate(data->mlx);
	free_struct(data);
}
