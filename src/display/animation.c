/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:43:15 by trebours          #+#    #+#             */
/*   Updated: 2024/10/16 15:26:18 by trebours         ###   ########.fr       */
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

void	verif_img(t_weapon *weapon)
{
	if (weapon->index_walk != 0)
	{
		weapon->walk.image[weapon->index_walk - 1]->enabled = false;
		weapon->index_walk = 0;
	}
	else
		weapon->walk.image[weapon->walk.nb_textures - 1]->enabled = false;
	if (weapon->index_fire != 0)
	{
		weapon->fired.image[weapon->index_fire - 1]->enabled = false;
		weapon->index_fire = 0;
	}
	else
		weapon->fired.image[weapon->fired.nb_textures - 1]->enabled = false;
}

void	anime_fire(t_map *data, t_weapon *current)
{
	if (current->index_walk != 0)
	{
		current->walk.image[current->index_walk - 1]->enabled = false;
		current->index_walk = 0;
	}
	else
		current->walk.image[current->walk.nb_textures - 1]->enabled = false;
	if (current->index_fire == (int)current->fired.nb_textures - 1)
		data->weapone.fire = false;
	anime_txt(&current->fired, &current->index_fire);
	current->fired.image[current->fired.nb_textures - 1]->enabled = false;
	if (!data->weapone.fire)
	{
		current->walk.image[0]->enabled = true;
		current->index_fire = 0;
		current->ammo--;
	}
}

void	ft_anim(t_map *data, t_weapon *current)
{
	if (!data->weapone.enable_anim)
	{
		data->weapone.fire = false;
		verif_img(current);
		return ;
	}
	if (current->ammo <= 0 && get_time() - data->weapone.time >= 500)
	{
		data->weapone.fire = false;
		current->walk.image[0]->enabled = false;
		current->walk.image[0]->enabled = false;
		if (current->index_reload == (int)current->reload.nb_textures - 1)
			current->ammo = current->ammo_max;
		anime_txt(&current->reload, &current->index_reload);
		if (current->ammo == current->ammo_max)
		{
			current->reload.image[current->reload.nb_textures - 1]->enabled = false;
			current->walk.image[0]->enabled = false;
			current->index_reload = 0;
		}
		data->weapone.time = get_time();
	}
	else if (current->ammo > 0 && data->weapone.fire && get_time() - data->weapone.time >= 200) // une fonction par if
	{
		anime_fire(data, current);
		data->weapone.time = get_time();
	}
	else if (is_move(data->game) && get_time() - data->weapone.time >= 300)
	{
		anime_txt(&current->walk, &current->index_walk);
		data->weapone.time = get_time();
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

void	anime_txt(t_textures *weapone, int *index)
{
	if (*index == 0)
	{
		weapone->image[index[0]]->enabled = true;
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
