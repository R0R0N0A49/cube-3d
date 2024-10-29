/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:43:15 by trebours          #+#    #+#             */
/*   Updated: 2024/10/16 14:20:32 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	ft_anim(t_map *data)
{
	if (!data->weapon.enable_anim)
	{
		data->weapon.barel_walk.image[0]->enabled = false;
		return ;
	}
	if (data->weapon.fire && data->weapon.enable_knife) // une fonction par if
	{
		if (data->weapon.index_barel_walk != 0)
			data->weapon.barel_walk.image[
				data->weapon.index_barel_walk - 1]->enabled = false;
		else
			data->weapon.barel_walk.image[29]->enabled = false;
		if (data->weapon.index_barel_fire == (int)
			data->weapon.barel_fire.nb_textures - 1)
			data->weapon.fire = false;
		anime_txt(&data->weapon.barel_fire, &data->weapon.index_barel_fire);
		data->weapon.barel_fire.image[8]->enabled = false;
		if (!data->weapon.fire)
		{
			data->weapon.barel_walk.image[0]->enabled = true;
			data->weapon.index_barel_walk = 0;
		}
	}
	else if (data->weapon.enable_knife && is_move(data->game) && get_time()
		- data->weapon.time_anime >= 250)
		anime_txt(&data->weapon.barel_walk, &data->weapon.index_barel_walk);
	else if (!data->weapon.enable_knife || !is_move(data->game))
	{
		if (data->weapon.index_barel_walk != 0)
			data->weapon.barel_walk.image[data->weapon.index_barel_walk
				- 1]->enabled = false;
		else
			data->weapon.barel_walk.image[29]->enabled = false;
		data->weapon.barel_walk.image[0]->enabled = true;
		data->weapon.index_barel_walk = 1;
	}
}

void	anime_txt(t_textures *weapon, int *index)
{
	if (*index == 0)
	{
		weapon->image[*index]->enabled = true;
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
