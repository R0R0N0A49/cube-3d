/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:43:15 by trebours          #+#    #+#             */
/*   Updated: 2024/10/15 14:24:06 by trebours         ###   ########.fr       */
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
	if (!data->weapone.enable_anim)
	{
		data->weapone.barel_walk.image[0]->enabled = false;
		return ;
	}
	if (data->weapone.fire && data->weapone.enable_knife) // une fonction par if
	{
		if (data->weapone.index_barel_walk != 0)
			data->weapone.barel_walk.image[
				data->weapone.index_barel_walk - 1]->enabled = false;
		else
			data->weapone.barel_walk.image[29]->enabled = false;
		if (data->weapone.index_barel_fire == (int)
			data->weapone.barel_fire.nb_textures - 1)
			data->weapone.fire = false;
		anime_txt(&data->weapone.barel_fire, &data->weapone.index_barel_fire);
		data->weapone.barel_fire.image[8]->enabled = false;
		if (!data->weapone.fire)
		{
			data->weapone.barel_walk.image[0]->enabled = true;
			data->weapone.index_barel_walk = 0;
		}
	}
	else if (data->weapone.enable_knife && is_move(data->game) && get_time()
		- data->weapone.time_anime >= 250)
		anime_txt(&data->weapone.barel_walk, &data->weapone.index_barel_walk);
	else if (!data->weapone.enable_knife || !is_move(data->game))
	{
		if (data->weapone.index_barel_walk != 0)
			data->weapone.barel_walk.image[data->weapone.index_barel_walk
				- 1]->enabled = false;
		else
			data->weapone.barel_walk.image[29]->enabled = false;
		data->weapone.barel_walk.image[0]->enabled = true;
		data->weapone.index_barel_walk = 1;
	}
}

void	anime_txt(t_textures *weapone, int *index)
{
	if (*index == 0)
	{
		weapone->image[*index]->enabled = true;
		weapone->image[weapone->nb_textures - 1]->enabled = false;
	}
	else
	{
		weapone->image[*index]->enabled = true;
		weapone->image[*index - 1]->enabled = false;
	}
	index[0]++;
	if (*index == (int)weapone->nb_textures)
		*index = 0;
}
