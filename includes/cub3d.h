/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/10/18 10:01:22 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "libft/libft.h"
# include "parsing.h"
# include "sys/syscall.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
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

void	menu(t_map *data);
void	button_play(t_map *data);
void	button_option(t_map *data);
void	button_edit(t_map *data);
void	button_exit(t_map *data);
void	mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

void	time_fps(t_map	*data);

void	option(t_map *data);
void	button_rtn(t_opt *option);
void	button_music(t_opt *option);
void	button_map(t_opt *option);
void	button_fps(t_map *data);
void	button_night(t_opt *option);
void	set_textures_terrain(t_map	*data);
void	fonts_init(t_map *data);
void	fonts_update(t_map *data);
void	fonts_disabled(t_map *data);

t_textures	init_txtr(size_t nb_textures);
// animation
void	init_anim(t_map *data);
void	anime_txt(t_textures *weapone, int *index);
void	ft_anim(t_map *data, t_weapon *current, t_weapon *nodisplay);
long	get_time(void);
void	choose_weapon(t_map *data);

#endif
