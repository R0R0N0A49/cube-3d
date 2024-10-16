/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_font_perso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:32:49 by derey             #+#    #+#             */
/*   Updated: 2024/10/15 13:39:01 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/src/font/font.h"
#include "../../includes/cub3d.h"

static void mlx_draw_char(mlx_image_t* image, int32_t texoffset, int32_t imgoffset)
{
	if (texoffset < 0)
		return;

	char* pixelx;
	uint8_t* pixeli;
	for (uint32_t y = 0; y < FONT_H; y++)
	{
		pixelx = &font_atlas.pixels[(y * font_atlas.width + texoffset) * sizeof(int32_t)];
		pixeli = image->pixels + ((y * image->width + imgoffset) * sizeof(int32_t));
		memcpy(pixeli, pixelx, FONT_W * sizeof(int32_t));
	}
}

//= Public =//

const mlx_texture_t* mlx_get_font(void)
{
    return ((const mlx_texture_t*)&font_atlas);
}

int32_t mlx_get_texoffset(char c)
{
    const bool _isprint = isprint(c);

    // NOTE: Cheesy branchless operation :D
    // +2 To skip line separator in texture
    return (-1 * !_isprint + ((FONT_W + 2) * (c - 32)) * _isprint);
}

mlx_image_t* mlx_put_string(mlx_t* mlx, const char* str, int32_t x, int32_t y)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(str);

	mlx_image_t* strimage;
	const size_t len = strlen(str);
	if (len > 512)
		return ((void*)mlx_error(MLX_STRTOOBIG));	
	if (!(strimage = mlx_new_image(mlx, len * FONT_W, FONT_H)))
		return (NULL);

	// Draw the text itself
	int32_t imgoffset = 0;
	for (size_t i = 0; i < len; i++, imgoffset += FONT_W)
		mlx_draw_char(strimage, mlx_get_texoffset(str[i]), imgoffset);

	if (mlx_image_to_window(mlx, strimage, x, y) == -1)
		return (mlx_delete_image(mlx, strimage), NULL);
	return (strimage);
}