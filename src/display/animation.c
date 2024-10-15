/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:43:15 by trebours          #+#    #+#             */
/*   Updated: 2024/10/08 15:03:09 by trebours         ###   ########.fr       */
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
		return ;
	if (data->weapone.enable_knife && is_move(data->game) && get_time() - data->weapone.time_anime >= 250)
		anime_knife(&data->weapone);
	if (!data->weapone.enable_knife || !is_move(data->game))
	{
		data->weapone.knife.image[0]->enabled = true;
		data->weapone.knife.image[1]->enabled = false;
		data->weapone.knife.image[2]->enabled = false;
		data->weapone.index_knife = 1;
	}
}

void	anime_knife(t_anim *weapone)
{
	if (!weapone->enable_anim || !weapone->enable_knife)
		return ;
	if (weapone->index_knife == 4)
		weapone->index_knife = 0;
	if (weapone->index_knife == 0)
	{
		weapone->knife.image[2]->enabled = false;
		weapone->knife.image[0]->enabled = true;
	}
	else if (weapone->index_knife == 2)
	{
		weapone->knife.image[1]->enabled = false;
		weapone->knife.image[0]->enabled = true;
	}
	else if (weapone->index_knife == 3)
	{
		weapone->knife.image[0]->enabled = false;
		weapone->knife.image[2]->enabled = true;
	}
	else
	{
		weapone->knife.image[0]->enabled = false;
		weapone->knife.image[1]->enabled = true;
	}
	weapone->index_knife++;
	weapone->time_anime = get_time();
}