/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:04 by derey             #+#    #+#             */
/*   Updated: 2024/09/28 17:35:18 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	recup_str(t_map *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A)
		data->editor->name = ft_strjoin(data->editor->name, "a");
	if (keydata.key == MLX_KEY_B)
		data->editor->name = ft_strjoin(data->editor->name, "b");
	if (keydata.key == MLX_KEY_C)
		data->editor->name = ft_strjoin(data->editor->name, "c");
	if (keydata.key == MLX_KEY_D)
		data->editor->name = ft_strjoin(data->editor->name, "d");
	if (keydata.key == MLX_KEY_E)
		data->editor->name = ft_strjoin(data->editor->name, "e");
	if (keydata.key == MLX_KEY_F)
		data->editor->name = ft_strjoin(data->editor->name, "f");
	if (keydata.key == MLX_KEY_G)
		data->editor->name = ft_strjoin(data->editor->name, "g");
	if (keydata.key == MLX_KEY_H)
		data->editor->name = ft_strjoin(data->editor->name, "h");
	if (keydata.key == MLX_KEY_I)
		data->editor->name = ft_strjoin(data->editor->name, "i");
	if (keydata.key == MLX_KEY_J)
		data->editor->name = ft_strjoin(data->editor->name, "j");
	if (keydata.key == MLX_KEY_K)
		data->editor->name = ft_strjoin(data->editor->name, "k");
	if (keydata.key == MLX_KEY_L)
		data->editor->name = ft_strjoin(data->editor->name, "l");
	if (keydata.key == MLX_KEY_M)
		data->editor->name = ft_strjoin(data->editor->name, "m");
	if (keydata.key == MLX_KEY_N)
		data->editor->name = ft_strjoin(data->editor->name, "n");
	if (keydata.key == MLX_KEY_O)
		data->editor->name = ft_strjoin(data->editor->name, "o");
	if (keydata.key == MLX_KEY_P)
		data->editor->name = ft_strjoin(data->editor->name, "p");
	if (keydata.key == MLX_KEY_Q)
		data->editor->name = ft_strjoin(data->editor->name, "q");
	if (keydata.key == MLX_KEY_R)
		data->editor->name = ft_strjoin(data->editor->name, "r");
	if (keydata.key == MLX_KEY_S)
		data->editor->name = ft_strjoin(data->editor->name, "s");
	if (keydata.key == MLX_KEY_T)
		data->editor->name = ft_strjoin(data->editor->name, "t");
	if (keydata.key == MLX_KEY_U)
		data->editor->name = ft_strjoin(data->editor->name, "u");
	if (keydata.key == MLX_KEY_V)
		data->editor->name = ft_strjoin(data->editor->name, "v");
	if (keydata.key == MLX_KEY_W)
		data->editor->name = ft_strjoin(data->editor->name, "w");
	if (keydata.key == MLX_KEY_X)
		data->editor->name = ft_strjoin(data->editor->name, "x");
	if (keydata.key == MLX_KEY_Y)
		data->editor->name = ft_strjoin(data->editor->name, "y");
	if (keydata.key == MLX_KEY_Z)
		data->editor->name = ft_strjoin(data->editor->name, "y");
}

void	editeur(t_map *data)
{
	(void)data;
	//recup_str(data);
	//button_rtn(data->opt);
}