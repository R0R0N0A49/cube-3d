/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/08 14:34:10 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    print_color(t_item *item, t_map *data, int x, int y)
{
	uint32_t    col;
	uint32_t    color;

	col = ((uint32_t *)item->textures[item->index]->pixels)[ft_abs(
			item->textures[item->index]->height * (y) - (x))];
	color = color_tex(col);
	if (item->item_dist / 5 >= 5 && data->fog == true)
		color = apply_fog(color, item->item_dist / 5);
	else if (item->item_dist / 5 >= FOG_MAX && data->fog == true)
		color = FOG;
	else
		color = color_tex(col);
	if ((color & 0xFFFFFFFF) != 0)
		try_put_pixel(data->rayc, item->px, item->py, color);

}

static void	print_item(t_map *data, t_item *item)
{
	item->px = item->drawstart_x;
	while (item->px < item->drawend_x)
	{
		item->py = item->drawstart_y;
		item->tex_x = (int)-((item->px - (-item->width * 0.5 + item
						->screen_x)) * item->textures[item->index]->width
				/ item->width);
		if (item->tex_x && item->transform_y > 0
			&& item->px > 0 && item->px < WINDOWSW)
		{
			while (item->py < item->drawend_y)
			{
				item->d = item->py * 256 - WINDOWSH * 128 + item->height * 128;
				item->tex_y = (int)((item->d * item->textures[item->index]->height)
						/ item->height) / 256;
				if (item->tex_y && item->py > 0 && item->py < WINDOWSH)
					print_color(item, data, item->tex_x, item->tex_y);
				item->py++;
			}
		}
		item->px++;
	}
}

static void	anim_item(t_item *item)
{
	static long time = -1;

	if (time == -1)
		time = get_time();
	if (get_time() - time >= 500)
	{
		item->index = !item->index;
		time = get_time();
	}
}

void	display_item(t_map *data, t_item *item)
{
	anim_item(item);
	item->item_dist = (data->game->player_x - item->posx) * (data->game->player_x - item->posx) + (data->game->player_y - item->posy) * (data->game->player_y - item->posy);
//	printf("dist = %f\n", item->item_dist);
	if (item->item_dist < 0.5)
	{
		item->enabled = false;
		data->weapon.nb_availed_weapon = 2;
		data->weapon.selected[data->weapon.index_weapon]->enabled = false;
		data->weapon.index_weapon = !data->weapon.index_weapon;
		data->weapon.selected[data->weapon.index_weapon]->enabled = true;
	}
	item->sprite_x = item->posx - data->game->player_x;
	item->sprite_y = item->posy - data->game->player_y;
	item->invdet = 1.0 / (data->game->plane_x * data->game->dir_y - data->game->dir_x * data->game->plane_y);
	item->transform_x = item->invdet * (data->game->dir_y * item->sprite_x - data->game->dir_x * item->sprite_y);
	item->transform_y = item->invdet * (-data->game->plane_y * item->sprite_x + data->game->plane_x * item->sprite_y);
	item->screen_x = (int)((WINDOWSW * 0.5) * (1 + item->transform_x / item->transform_y));
	item->height = ft_abs((int)(WINDOWSH/ item->transform_y));
	item->drawstart_y = -item->height * 0.5 + WINDOWSH * 0.5;
	if (item->drawstart_y < 0)
		item->drawstart_y = 0;
	item->drawend_y = item->height * 0.5 + WINDOWSH * 0.5;
	if (item->drawend_y >= WINDOWSH)
		item->drawend_y = WINDOWSH - 1;
	item->width = ft_abs((int)(WINDOWSH / item->transform_y));
	item->drawstart_x = -item->width * 0.5 + item->screen_x;
	item->drawend_x = item->drawstart_x + item->width;
	if (item->drawstart_x < 0)
		item->drawstart_x = 0;
	if (item->drawend_x >= WINDOWSW)
		item->drawend_x = WINDOWSW - 1;
	if (item->drawstart_x < item->x)
		item->drawstart_x = item->x;
	if (item->drawend_x > item->x_max)
		item->drawend_x = item->x_max;
	print_item(data, item);
	data->weapon.item.isvisible = false;
	data->weapon.item.x = -1;
}
