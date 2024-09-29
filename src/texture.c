/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:35:38 by derey             #+#    #+#             */
/*   Updated: 2024/09/29 17:44:59 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	set_fonts_textures_names(char ***t_names)
{
	(*t_names)[0] = ft_strdup("font0.png");
	(*t_names)[1] = ft_strdup("font1.png");
	(*t_names)[2] = ft_strdup("font2.png");
	(*t_names)[3] = ft_strdup("font3.png");
	(*t_names)[4] = ft_strdup("font4.png");
	(*t_names)[5] = ft_strdup("font5.png");
	(*t_names)[6] = ft_strdup("font6.png");
	(*t_names)[7] = ft_strdup("font7.png");
	(*t_names)[8] = ft_strdup("font8.png");
	(*t_names)[9] = ft_strdup("font9.png");
}

t_textures	init_txtr(size_t nb_textures)
{
	t_textures	tmp;

	tmp.nb_textures = nb_textures;
	tmp.textures_name = ft_calloc(sizeof(char *), nb_textures);
	if (!tmp.textures_name)
		ft_error();
	tmp.textures = ft_calloc(sizeof(mlx_texture_t *), nb_textures);
	if (!tmp.textures)
	{
		free(tmp.textures_name);
		ft_error();
	}
	tmp.image = ft_calloc(sizeof(mlx_image_t *), nb_textures);
	if (!tmp.image)
	{
		free(tmp.textures_name);
		free(tmp.textures);
		ft_error();
	}
	return (tmp);
}

void	set_textures(t_map	*data, t_textures *txtr, char *path,
	void (*set_texture_name)(char ***t_names))
{
	char	*name;
	size_t	i;

	i = 0;
	set_texture_name(&txtr->textures_name);
	while (i < txtr->nb_textures)
	{
		name = ft_strjoin(path, txtr->textures_name[i]);
		if (!name)
			ft_error();
		txtr->textures[i] = mlx_load_png(name);
		txtr->image[i] = mlx_texture_to_image(data->mlx, txtr->textures[i]);
		if (name)
			free(name);
		if (!txtr->textures[i] || !txtr->image[i])
			ft_error();
		i++;
	}
}

void	set_textures_terrain(t_map	*data)
{
	data->font = init_txtr(10);
	set_textures(data, &data->font, "./tiles/fonts/",
		&set_fonts_textures_names);
}
