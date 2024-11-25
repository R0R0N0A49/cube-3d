/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:40:33 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:09:02 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

size_t	ft_strlen_w(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != NULL)
		i++;
	return (i);
}

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

long	get_time(void)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

t_vector	set_vector(double x, double y)
{
	t_vector	result_vector;

	result_vector.x = x;
	result_vector.y = y;
	return (result_vector);
}
