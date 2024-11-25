/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:40:01 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 10:40:01 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_pos(t_map *data, int i, int j)
{
	data->game->plane_x = 0;
	data->game->plane_y = 0;
	data->game->dir_x = 0;
	data->game->dir_y = 0;
	if (data->map[j][i] == 'N')
	{
		data->game->plane_x = 0.66;
		data->game->dir_y = -1;
	}
	if (data->map[j][i] == 'S')
	{
		data->game->plane_x = -0.66;
		data->game->dir_y = 1;
	}
	if (data->map[j][i] == 'W')
	{
		data->game->plane_y = -0.66;
		data->game->dir_x = -1;
	}
	if (data->map[j][i] == 'E')
	{
		data->game->plane_y = 0.66;
		data->game->dir_x = 1;
	}
}

void	init_player(t_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				data->game->player_x = (double)i + 0.5;
				data->game->player_y = (double)j + 0.5;
				data->m_map->pos_x = i;
				data->m_map->pos_y = j;
				init_pos(data, i, j);
				data->map[j][i] = '0';
				break ;
			}
			i++;
		}
		j++;
	}
}

void	init_bool(t_map *data)
{
	data->press = false;
	data->ceiling = false;
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_w = false;
	data->game->move_s = false;
	data->game->move_a = false;
	data->game->move_d = false;
	data->game->cursor_y = 0;
	data->game->cursor_x = 0;
	data->idx_menu = 0;
	data->press = false;
	data->game->rotate_left = false;
	data->game->rotate_right = false;
	data->but_option->click = false;
	data->but_option->press_enter = false;
	data->minima->enabled = true;
	data->mini_iso->enabled = false;
	data->game->moove_cur = false;
}

t_button	*init_button(void)
{
	t_button	*tmp;

	tmp = malloc(1 * sizeof(t_button));
	tmp->good = false;
	tmp->click = false;
	tmp->press_enter = false;
	return (tmp);
}

void	init_menu_option(t_map *data)
{
	data->menu_option->fps->enabled = false;
	data->menu_option->roof->enabled = false;
	data->menu_option->mini->enabled = false;
	data->menu_option->music->enabled = false;
	data->menu_option->rtn->enabled = false;
	data->menu_option->unvalid->enabled = false;
	data->menu_option->valid->enabled = false;
	data->menu_option->play_music = false;
	data->menu_option->display_map = true;
	data->menu_option->display_fps = true;
	data->menu_option->night_mode = false;
	data->menu_option->but_music = init_button();
	data->menu_option->but_map = init_button();
	data->menu_option->but_night = init_button();
	data->menu_option->but_fps = init_button();
	data->menu_option->bottom = mlx_texture_to_image(data->mlx, data->menufd2);
	data->menu_option->bottom->enabled = false;
	data->menu_option->index = 0;
	data->menu_option->cub->enabled = false;
}
