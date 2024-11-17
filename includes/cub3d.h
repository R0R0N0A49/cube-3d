/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 19:26:17 by derey            ###   ########.fr       */
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

void	check_but_play(t_map *data);
void	check_but_option(t_map *data);
void	check_but_exit(t_map *data);
void	check_but_rtn(t_map *data);
void	check_but_music(t_map *data);
void	check_but_map(t_map *data);
void	check_but_fps(t_map *data);
void	check_but_night(t_map *data);

void	play_game(t_map *data);
void	pause_game(t_map *data);
int		get_pc(int value, int size, int max);
void	exit_cub3d(t_map *data);

void	init_door(t_map *data);
void	init_struct(char **src, t_map *data);
int		free_struct(t_map *data);
int		verif_start_line(char *line);
void	init_player(t_map *data);
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
void	init_anim(t_map *data);
void	anime_txt(t_textures *weapone, int *index);
void	ft_anim(t_map *data, t_weapon *current, t_weapon *nodisplay);
long	get_time(void);
void	choose_weapon(t_map *data);

void		display_item(t_map *data, t_item *item);
void		try_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, int color);
int			ft_abs(int nb);
void	scroll(double i, double y, void *param);
void draw_minimap(t_map *data);
size_t	ft_strlen_w(char **s);

uint32_t	apply_fog(uint32_t color, double current_dist);
uint32_t 	ft_lerp_color(uint32_t color1, uint32_t color2, double t);
uint32_t	color_fog(int32_t a, t_ray *ray);
uint32_t	color_tex(int32_t r);
void	raycast_door(t_door *door, t_map *data);
void	draw_door(int x, t_door *door, t_map *data, int i);
int		index_door(t_door *door, int nmb_door, int x, int y);
void	chois_door(t_map *data);
int	ray_hit_door(t_map *data, t_ray *ray, int i);

t_vector	set_vector(double x, double y);
int check_open(t_map *data, int x, int y);

void	init_item(t_item *item, t_map *data);
void	txt_item(char *src, t_item *item);
void	info_item(TXT *tmp, t_map *data, int i);
void	creat_pos_item(t_item *item, t_map *data);

void	init_struct_ray(t_ray *ray);
void	init_doors(t_ray *ray, t_map *data, int tmp, int x);
void	init_raycast(int x, t_ray *ray, t_game *game);
void	init_step(t_ray *ray, t_map *data);
void	init_floorcelling(t_ray *ray);

void	draw_floor(t_ray *ray, t_map *data, int x, int y);
void	draw_ceiling(t_ray *ray, t_map *data, int x, int y);
void	draw_nuit(t_ray *ray, t_map *data, int x, mlx_texture_t *tex);
void	door(t_ray *ray, t_map *data, int x);

void	calcul_projected_cam(t_ray *ray, t_map *data);
void	set_side_step(t_ray *ray, t_map *data, int x);

void	draw_isome(int width, int height, int color, t_map *data);
void	draw_isometric_rhombus(int width, int height, int color, t_map *data);

void	draw_button_exit(t_map *data, int x, int y);
void	draw_button_option(t_map *data, int x, int y);
void	draw_button_play(t_map *data, int x, int y);

void	condition_button_music(t_opt *option, int x, int y);
void	condition_button_rtn(t_opt *option, int x, int y);
void	condition_button_map(t_opt *option, int x, int y);
void	condition_button_fps(t_map *data, int x, int y);
void	condition_button_night(t_opt *option, int x, int y);

void	init_loop_raymini(t_map *data, t_raymini *ray_mi);
void	init_pw(t_map *data, t_vector x, t_vector y, uint32_t color);
void	init_pt(t_map *data, t_vector x, t_vector y, uint32_t color);
void	init_draw_lines(t_line_bresenham *bres, t_vector x0, t_vector x1);

void	draw_partial_cube(t_map *data, int x, int y, uint32_t color);
double	normalize_angle(double angle);
void	draw_w(t_map *data, int xx, int yy);

void	draw_circle(t_map *data, int r);
void	draw_map_in_circle(t_map *data, double px, double py);
void	draw_partial_cube(t_map *data, int x, int y, uint32_t color);
void	draw_cube(t_map *data, int i, int j, uint32_t te);

void	cast_rays_in_circle(t_map *data);
void	loop_raymini(t_map *data, t_raymini *ray_mi);
void	algo_raymini(t_map *data, t_raymini *ray_mi);
void	draw_lines(t_map *data, t_vector x0, t_vector x1, uint32_t color);
double	calculate_fov(double dir_x, double dir_y, double plane_x,
			double plane_y);

#endif
