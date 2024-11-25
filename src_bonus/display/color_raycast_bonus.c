/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_raycast_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:24:36 by derey             #+#    #+#             */
/*   Updated: 2024/11/25 13:07:43 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

uint32_t	ft_lerp_color(uint32_t color1, uint32_t color2, double t)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t	aa;

	ra = (uint32_t)(ft_lerp((color1 >> 24) & 0xFF, (color2 >> 24) & 0xFF, t));
	ga = (uint32_t)(ft_lerp((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, t));
	ba = (uint32_t)(ft_lerp((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, t));
	aa = (uint32_t)(ft_lerp(color1 & 0xFF, color2 & 0xFF, t));
	return ((ra << 24) | (ga << 16) | (ba << 8) | aa);
}

uint32_t	apply_fog(uint32_t color, double current_dist)
{
	float		fog_factor;
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t	aa;

	fog_factor = (current_dist - FOG_MIN) / (FOG_MAX - FOG_MIN);
	if (fog_factor > 1.0f)
		fog_factor = 1.0f;
	if (fog_factor < 0.0f)
		fog_factor = 0.0f;
	ra = (color >> 24) & 0xFF;
	ga = (color >> 16) & 0xFF;
	ba = (color >> 8) & 0xFF;
	aa = (color) & 0xFF;
	ra = (uint32_t)ft_lerp(ra, 0x00, fog_factor);
	ga = (uint32_t)ft_lerp(ga, 0x00, fog_factor);
	ba = (uint32_t)ft_lerp(ba, 0x00, fog_factor);
	return ((ra << 24) | (ga << 16) | (ba << 8) | aa);
}

uint32_t	color_fog(int32_t a, t_ray *ray)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t	aa;
	float		t;

	ra = ((a >> 24) & 0xFF);
	ga = ((a >> 16) & 0xFF);
	ba = ((a >> 8) & 0xFF);
	aa = (a & 0xFF);
	t = (ray->wall_dist - FOG_MIN) / (FOG_MAX - FOG_MIN);
	aa = ft_lerp(aa, 0x00, t);
	ga = ft_lerp(ga, 0x00, t);
	ba = ft_lerp(ba, 0x00, t);
	return ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
}

uint32_t	color_tex(int32_t r)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t	aa;
	uint32_t	color;

	ra = ((r >> 24) & 0xFF);
	ga = ((r >> 16) & 0xFF);
	ba = ((r >> 8) & 0xFF);
	aa = (r & 0xFF);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	return (color);
}
