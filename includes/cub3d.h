/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/17 15:14:46 by derey            ###   ########.fr       */
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

void	init_struct(char **src, t_map *data);
int		free_struct(t_map *data);
int		verif_start_line(char *line);
void	ft_lstadd_back(t_tmp **lst, t_tmp *new_tail);
void	mini_map(t_map *data, mlx_t *mlx);
void	mini(t_map *data);
void	draw_cube(t_map *data, int i, int j, uint32_t te);

void	key_press(mlx_key_data_t keydata, void *param);
void	cursor(double xpos, double ypos, void* param);
void	loop(void *param);

void	raycasting(t_map *data);

void	move_w(t_map *data);
void	move_s(t_map *data);
void	move_a(t_map *data);
void	move_d(t_map *data);
void	rotate_left(t_map *map);
void	rotate_right(t_map *map);

#endif
