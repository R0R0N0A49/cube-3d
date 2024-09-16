/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/09/16 09:13:58 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_lineray(t_map *data, int y, int x)
{
	int	i;

	i = 0;
	while (i < data->raycast->wallH)
	{
		mlx_put_pixel(data->rayc, x, i + y, 0xFFFFFF);
		i++;
	}
}

void	raycasting(t_map *data)
{
	int	i;
	int	test;

	i = 0;
	test = (WINDOWSH / 2) - (data->raycast->wallH / 2);
	while (i < data->raycast->wallW)
	{
		draw_lineray(data, test, i);
		i++;
	}
}
