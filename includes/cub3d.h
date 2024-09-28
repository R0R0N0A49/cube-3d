/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/28 17:20:20 by derey            ###   ########.fr       */
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
void	init_player(t_map *data);
void	mini(t_map *data);
void	draw_cube(t_map *data, int i, int j, uint32_t te);

void	key_press(mlx_key_data_t keydata, void *param);
void	cursor(double xpos, double ypos, void* param);
void	mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param);
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
void	button_fov(t_opt *option);
void	button_floor(t_opt *option);
void	button_roof(t_opt *option);

void	editeur(t_map *data);

void	play(t_map *data);
void	pause_game(t_map *data);

void	check_but_play(t_map *data);
void	check_but_option(t_map *data);
void	check_but_edit(t_map *data);
void	check_but_exit(t_map *data);

void	verif_option(t_opt *opt);
void	exit_cub3d(t_map *data);

void	check_but_roof(t_map *data);
void	check_but_floor(t_map *data);
void	check_but_fov(t_map *data);
void	check_but_music(t_map *data);
void	check_but_rtn(t_opt *option, t_map *data);

void	init_button_len(t_map *data);

void	recup_str(t_map *data, mlx_key_data_t keydata);

#endif
