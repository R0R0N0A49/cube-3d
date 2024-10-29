/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:52:53 by derey             #+#    #+#             */
/*   Updated: 2024/10/28 16:04:41 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_struct_ray(t_ray *ray)
{
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->camera_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_raycast(int x, t_ray *ray, t_game *game)
{
	init_struct_ray(ray);
	ray->camera_x = 2 * x / (double)WINDOWSW - 1;
	ray->raydir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->raydir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->player_x;
	ray->map_y = (int)game->player_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
}

void	init_step(t_ray *ray, t_map *data)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->game->player_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - data->game->player_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->game->player_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - data->game->player_y) * ray->deltadist_y;
	}
}

void	set_side_step(t_ray *ray, t_map *data, int x)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25 || ray->map_y > WINDOWSH - 0.25 || ray->map_x > WINDOWSW - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
		else if (ray->map_y == (int)data->weapone.item.posy && ray->map_x == (int)data->weapone.item.posx)
		{
			data->weapone.item.isvisible = true;
			if (data->weapone.item.x == -1)
				data->weapone.item.x = x;
//			break ;
		}
	}
}

void	calcul_projected_cam(t_ray *ray, t_map *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOWSH / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WINDOWSH / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height) / 2 + WINDOWSH / 2;
	if (ray->draw_end >= WINDOWSH)
		ray->draw_end = WINDOWSH - 1;
	if (ray->side == 0)
		ray->wall_x = data->game->player_y + ray->wall_dist * ray->raydir_y;
	else
		ray->wall_x = data->game->player_x + ray->wall_dist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
}

mlx_texture_t *get_texture(t_ray *ray, t_map *data)
{
	if (ray->side == 0 && ray->raydir_x > 0)
		return (data->we);
	if (ray->side == 0 && ray->raydir_x < 0)
		return (data->ea);
	if (ray->side == 1 && ray->raydir_y < 0)
		return (data->so);
	if (ray->side == 1 && ray->raydir_y > 0)
		return (data->no);
	return (data->no);
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

uint32_t	color_tex(int32_t r)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t aa;
	uint32_t color;

	ra = ((r >> 24) & 0xFF);
	ga = ((r >> 16) & 0xFF);
	ba = ((r >> 8) & 0xFF);
	aa = (r & 0xFF);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	return (color);
}

float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

uint32_t	color_fog(int32_t a, t_ray *ray)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t color;
	uint32_t aa;
	float	t;

	ra = ((a >> 24) & 0xFF);
	ga = ((a >> 16) & 0xFF);
	ba = ((a >> 8) & 0xFF);
	aa = (a & 0xFF);
	t = (ray->wall_dist - FOG_MIN) / (FOG_MAX - FOG_MIN);
	aa = ft_lerp(aa, 0x00, t);
	ga = ft_lerp(ga, 0x00, t);
	ba = ft_lerp(ba, 0x00, t);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	//printf("%X || %X\n", color, ra);
	return (color);
}

uint32_t	color_fog_2(int32_t a, int h)
{
	uint32_t	ra;
	uint32_t	ga;
	uint32_t	ba;
	uint32_t color;
	uint32_t aa;
	float	t;

	aa = ((a >> 24) & 0xFF);
	ba = ((a >> 16) & 0xFF);
	ga = ((a >> 8) & 0xFF);
	ra = (a & 0xFF);
	t = (4.8 * h / (float)WINDOWSH) - 2.0f;
	if (t < 0)
		t = -t;
	aa = ft_lerp(aa, 0x00, t);
	ga = ft_lerp(ga, 0x00, t);
	ba = ft_lerp(ba, 0x00, t);
	color = ((aa << 24) | ((ba) << 16) | ((ga << 8)) | ra);
	//printf("%X || %X\n", color, ra);
	return (color);
}

void	draw_nuit(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int y;
	uint32_t col;

	y = 0;
	ray->texture_y = 0;
	ray->step = WINDOWSH / tex->height;
	while (y < ray->draw_start)
	{
		ray->texture_y = y * ray->step;
		col = ((uint32_t *)tex->pixels)[ft_abs(tex->width * ray->texture_y + x)];
		ray->color = color_tex(col);
		try_put_pixel(data->rayc, x, y, ray->color);
		y++;
	}
}

void	draw_tex(t_ray *ray, t_map *data, int x, mlx_texture_t *tex)
{
	int y;
	uint32_t col;

	y = ray->draw_start - 1;
	if (ray->wall_dist >= FOG_MAX && data->fog == true)
	{
		while(y < ray->draw_end) try_put_pixel(data->rayc, x, y++, FOG);
		return;
	}
	while (y < ray->draw_end)
	{
		ray->texture_y = (int)ray->texture_pos & (tex->height - 1);
		ray->texture_pos += ray->step;
		//printf("%d\n", ray->line_height);
		col = ((uint32_t *)tex->pixels)[ft_abs(tex->height * (ray->texture_y + 1) - (ray->texture_x + 1))];
		if (ray->wall_dist >= FOG_MIN && data->fog == true)
			ray->color = color_fog(col, ray);
		else
			ray->color = color_tex(col);
		try_put_pixel(data->rayc, x, y, ray->color);
		y++;
	}
}

void	draw_ray(int x, t_ray *ray, t_map *data)
{
	mlx_texture_t *tex;
	int	i;

	i= 0;
	tex = get_texture(ray, data);
	if (data->plafond == true)
		draw_nuit(ray, data, x, data->nuit);
	else
	{
		while (i < ray->draw_start)
		{
			mlx_put_pixel(data->rayc, x, i, data->up);
			i++;
		}
	}
	ray->texture_x = (int)(ray->wall_x * (double)tex->height);
	if ((ray->side == 0 && ray->raydir_x > 0) || (ray->side == 1 && ray->raydir_y < 0))
		ray->texture_x = tex->width - ray->texture_x - 1;
	ray->step = 1.0 * tex->height / ray->line_height;
	ray->texture_pos = (ray->draw_start - WINDOWSH / 2 + ray->line_height / 2) * ray->step;
	draw_tex(ray, data, x, tex);
	i = ray->draw_end;
	while (i < WINDOWSH)
	{
		if (data->fog && i <= 3 * (WINDOWSH / 4.8))
			mlx_put_pixel(data->rayc, x, i, color_fog_2(data->down, i - WINDOWSH / 4.8));
		else
			mlx_put_pixel(data->rayc, x, i, data->down);
		i++;
	}
}

uint32_t	get_color(TXT *tex, t_map *data, int item_dist, int x, int y)
{
	uint32_t col;
	uint32_t color;

	//printf("%d\n", ray->line_height);
	col = ((uint32_t *)tex->pixels)[ft_abs(tex->height * (y + 1) - (x + 1))];
	if (item_dist >= FOG_MIN && data->fog == true)
		color = color_fog(col, data->raycast);
	else
		color = color_tex(col);
	return (color);
}

void	display_item(t_map *data, int x)
{
	(void)x;
	int	item_dist = (data->game->player_x - data->weapone.item.posx) * (data->game->player_x - data->weapone.item.posx) - (data->game->player_y - data->weapone.item.posy) * (data->game->player_y - data->weapone.item.posy);
	double	spriteX = data->weapone.item.posx - data->game->player_x;
	double	spriteY = data->weapone.item.posy - data->game->player_y;
//	double	invDet = 1.0 / (data->game->plane_x * data->game->dir_y - data->game->dir_x * data->game->plane_y);
	double invDet = 1.0 / (data->game->plane_x * data->game->dir_y - data->game->dir_x * data->game->plane_y);

	double	transformX = invDet * (data->game->dir_y * spriteX - data->game->dir_x * spriteY);
	double	transformY = invDet * (-data->game->plane_y * spriteX + data->game->plane_x * spriteY);
	// pb avec transform X et Y. peut venir de dir_y et dir_x

	int		spriteScreenX = (int)((WINDOWSW / 2) * (1 + transformX / transformY));
//	printf("spriteX = %f\nspriteY = %f\n", spriteX, spriteY);

	int		spriteHeight = abs((int)(WINDOWSH / transformY));
	int 	drawStartY = -spriteHeight / 4 + WINDOWSH / 2;
	if (drawStartY < 0)
		drawStartY = 0;
	int 	drawEndY = spriteHeight / 2 + WINDOWSH / 2;
	if (drawEndY >= WINDOWSH)
		drawEndY = WINDOWSH - 1;
	int		spriteWidth = abs((int)(WINDOWSH / transformY));

	int 	drawStartX = -spriteWidth + spriteScreenX;
	if (drawStartX < 0)
		drawStartX = 0;

	int 	drawEndX = drawStartX + spriteWidth;

	if (drawEndX >= WINDOWSW)
		drawEndX = WINDOWSW - 1;
	if (drawStartX < data->weapone.item.x)
		drawStartX = data->weapone.item.x;
//	printf("transformY = %f\n", transformY);
	for (int px = drawStartX; px < drawEndX; px++)
	{
		int texX = (int)-((px - (-spriteWidth + spriteScreenX)) * data->weapone.item.texture->width / spriteWidth);
		if (texX && transformY > 0 && px > 0 && px < WINDOWSW)
		{
			for (int py = drawStartY; py < drawEndY; py++) {
				int d = (py) * 256 - WINDOWSH * 128 + spriteHeight * 128;
				int	texY = (int)((d * data->weapone.item.texture->height) / spriteHeight) / 256;
				if (texY && py > 0 && py < WINDOWSH) {
					uint32_t color = get_color(data->weapone.item.texture, data, item_dist, texX, texY);
					if((color & 0x00FFFFFF) != 0)
						try_put_pixel(data->rayc, px, py, color);
				}
			}
		}
	}
	data->weapone.item.isvisible = false;
	data->weapone.item.x = -1;
//	int	line_height = 0;
//	int	draw_start = 0;
//	int	draw_end = 0;
//	double	wall_x = 0;
//	double	raydir_y = 0;
//	double	raydir_x = 0;
//
//	if (!data->weapone.item.hit)
//	{
////		printf("test\n");
//		return ;
//	}
////	if (data->weapone.item.side == 0)
////		data->weapone.item.dist_item = data->weapone.item.sidedist_x - data->weapone.item.deltadist_x;
////	if (data->weapone.item.side == 1)
////		data->weapone.item.dist_item = data->weapone.item.sidedist_y - data->weapone.item.deltadist_y;
////	item_dist = data->weapone.item.dist_item;
//	line_height = (int)(WINDOWSH / item_dist);
//	draw_start = -(line_height) / 2 + WINDOWSH / 2;
//	if (draw_start < 0)
//		draw_start = 0;
//	draw_end = (line_height) / 2 + WINDOWSH / 2;
//	if (draw_end >= WINDOWSH)
//		draw_end = WINDOWSH - 1;
//	if (data->weapone.item.side == 0)
//		wall_x = data->game->player_y + item_dist * raydir_y;
//	else
//		wall_x = data->game->player_x + item_dist * raydir_x;
//	wall_x -= floor(wall_x);
////	printf("x = %d, height = %d\n", x, (int)data->rayc->width);
//	for (int i = draw_start; i < draw_end && x < (int)data->rayc->width; i++)
//		try_put_pixel(data->rayc, x, i - 1, 0xFF00FFFF);
}

void	raycasting(t_map *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = data->raycast;
	while (x < WINDOWSW)
	{
		init_raycast(x, ray, data->game);
		init_step(ray, data);
		set_side_step(ray, data, x);
		calcul_projected_cam(ray, data);
		draw_ray(x, ray, data);
		x++;
	}
	if (data->weapone.item.isvisible == true)
		display_item(data, x);
}
