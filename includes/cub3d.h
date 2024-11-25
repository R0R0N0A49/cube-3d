/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/19 11:14:47 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "libft/libft.h"
# include "parsing.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/*================================read_file.c=================================*/
void		init_struct(char **src, t_map *data);
int			free_struct(t_map *data);

/*===============================print_error.c================================*/
int			verif_start_line(char *line);

/*===================================init.c===================================*/
void		init_null(t_map *data);
void		init_player(t_map *data);
void		init_game(t_map *data);

/*================================key_press.c=================================*/
void		key_press(mlx_key_data_t keydata, void *param);

/*=============================init_raycasting.c==============================*/
void		init_raycast(int x, t_ray *ray, t_game *game);
void		init_step(t_ray *ray, t_map *data);

/*===============================raycasting.c=================================*/
void		raycasting(t_map *data);

/*=============================raycasting_dda.c===============================*/
void		calcul_projected_cam(t_ray *ray, t_map *data);
void		set_side_step(t_ray *ray, t_map *data);

/*=================================moove.c====================================*/
void		move_w(t_map *data);
void		move_s(t_map *data);
void		move_a(t_map *data);
void		move_d(t_map *data);

/*=================================rotate.c===================================*/
void		rotate_left(t_map *map);
void		rotate_right(t_map *map);

/*=================================utils.c====================================*/
void		try_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, int color);
int			ft_abs(int nb);

#endif