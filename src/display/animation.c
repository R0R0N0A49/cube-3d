/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:43:15 by trebours          #+#    #+#             */
/*   Updated: 2024/10/29 13:23:15 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	choose_weapon(t_map *data)
{
	if (data->weapon.index_weapon == 0)
		ft_anim(data, &data->weapon.barrel, &data->weapon.e11);
	if (data->weapon.index_weapon == 1)
		ft_anim(data, &data->weapon.e11, &data->weapon.barrel);
}

long	get_time(void)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

int	is_move(t_game *game)
{
	if (game->move_a)
		return (1);
	if (game->move_d)
		return (1);
	if (game->move_s)
		return (1);
	if (game->move_w)
		return (1);
	return (0);
}

void	verif_img(t_weapon *weapon)
{
	if (weapon->index_walk != 0)
	{
		weapon->walk.image[weapon->index_walk - 1]->enabled = false;
		weapon->index_walk = 0;
	}
	else
		weapon->walk.image[weapon->walk.nb_textures - 1]->enabled = false;
}

void	ft_anim(t_map *data, t_weapon *current, t_weapon *nodisplay)
{
	verif_img(nodisplay);
	if (!data->weapon.enable_anim)
	{
		verif_img(current);
		data->weapon.selected[data->weapon.index_weapon]->enabled = false;
		data->weapon.selected[2]->enabled = false;
		return ;
	}
	else if (is_move(data->game) && get_time() - data->weapon.time >= 300)
	{
		anime_txt(&current->walk, &current->index_walk);
		data->weapon.time = get_time();
	}
	else if (!is_move(data->game))
	{
		if (current->index_walk != 0)
			current->walk.image[current->index_walk - 1]->enabled = false;
		else
			current->walk.image[current->walk.nb_textures - 1]->enabled = false;
		current->walk.image[0]->enabled = true;
		current->index_walk = 1;
	}
}

void	anime_txt(t_textures *weapon, int *index)
{
	if (*index == 0)
	{
		weapon->image[index[0]]->enabled = true;
		weapon->image[weapon->nb_textures - 1]->enabled = false;
	}
	else
	{
		weapon->image[*index]->enabled = true;
		weapon->image[*index - 1]->enabled = false;
	}
	index[0]++;
	if (*index == (int)weapon->nb_textures)
		*index = 0;
}
