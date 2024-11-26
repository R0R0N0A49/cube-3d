/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:40:33 by derey             #+#    #+#             */
/*   Updated: 2024/11/26 13:44:37 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	try_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, int color)
{
	if (x > img->width || y > img->height)
		return ;
	mlx_put_pixel(img, x, y, color);
}

void	error_mlx(t_map *data)
{
	free_struct(data);
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
