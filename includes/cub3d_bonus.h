/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/26 09:45:47 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "struct_bonus.h"
# include "libft/libft.h"
# include "parsing_bonus.h"
# include "sys/syscall.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <math.h>

/*══════════════════════════════════DISPLAY═══════════════════════════════════*/
/*═════════════════════════════animation_bonus.c══════════════════════════════*/
void		choose_weapon(t_map *data);
void		anime_txt(t_textures *weapone, int *index);
void		ft_anim(t_map *data, t_weapon *current, t_weapon *nodisplay);

/*════════════════════════════button_utils_bonus.c════════════════════════════*/
void		but_rtn_utils(t_map *data);
void		but_music_utils(t_map *data);
void		but_map_utils(t_map *data);
void		but_fps_utils(t_map *data);
void		but_night_utils(t_map *data);

/*═══════════════════════════════check_bonus.c════════════════════════════════*/
void		check_music(t_map *data);
void		check_door_open(t_map	*data);
int			check_open(t_map *data, int x, int y);

/*════════════════════════════check_button_bonus.c════════════════════════════*/
void		check_but_play(t_map *data);
void		check_but_option(t_map *data);
void		check_but_exit(t_map *data);

/*═════════════════════════check_option_button_bonus.c════════════════════════*/
void		check_but_rtn(t_map *data);
void		check_but_music(t_map *data);
void		check_but_map(t_map *data);
void		check_but_fps(t_map *data);
void		check_but_night(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
uint32_t	ft_lerp_color(uint32_t color1, uint32_t color2, double t);
uint32_t	apply_fog(uint32_t color, double current_dist);
uint32_t	color_fog(int32_t a, t_ray *ray);
uint32_t	color_tex(int32_t r);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		condition_button_music(t_opt *option, int x, int y);
void		condition_button_rtn(t_opt *option, int x, int y);
void		condition_button_map(t_opt *option, int x, int y);
void		condition_button_fps(t_map *data, int x, int y);
void		condition_button_night(t_opt *option, int x, int y);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		chois_door(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		raycast_door(t_door *door, t_map *data);
int			index_door(t_door *door, int nmb_door, int x, int y);
int			ray_hit_door(t_map *data, t_ray *ray, int i);
uint32_t	color_fog_door(int32_t a, t_door *ray);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
int			is_line_hitting_segment(t_vector v1p1, t_vector v1p2, \
		t_vector v2p1, t_vector v2p2);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		draw_isome(int width, int height, int color, t_map *data);
void		draw_isometric_rhombus(int width, int height, int color, \
		t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		draw_button_exit(t_map *data, int x, int y);
void		draw_button_option(t_map *data, int x, int y);
void		draw_button_play(t_map *data, int x, int y);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		draw_cube(t_map *data, int i, int j, uint32_t te);
void		draw_circle(t_map *data, int r);
void		draw_map_in_circle(t_map *data, double px, double py);
void		draw_partial_cube(t_map *data, int x, int y, uint32_t color);
void		draw_w(t_map *data, int xx, int yy);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		draw_floor(t_ray *ray, t_map *data, int x, int y);
void		draw_ceiling(t_ray *ray, t_map *data, int x, int y);
void		draw_nuit(t_ray *ray, t_map *data, int x, mlx_texture_t *tex);
void		door(t_ray *ray, t_map *data, int x);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		draw_lines(t_map *data, t_vector x0, t_vector x1, uint32_t color);
void		loop_raymini(t_map *data, t_raymini *ray_mi);
void		algo_raymini(t_map *data, t_raymini *ray_mi);
void		cast_rays_in_circle(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		fonts_init(t_map *data);
void		fonts_update(t_map *data);
void		fonts_disabled(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_loop_raymini(t_map *data, t_raymini *ray_mi);
void		init_pw(t_map *data, t_vector x, t_vector y, uint32_t color);
void		init_pt(t_map *data, t_vector x, t_vector y, uint32_t color);
void		init_draw_lines(t_line_bresenham *bres, t_vector x0, t_vector x1);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_struct_ray(t_ray *ray);
void		init_doors(t_ray *ray, t_map *data, int tmp, int x);
void		init_raycast(int x, t_ray *ray, t_game *game);
void		init_step(t_ray *ray, t_map *data);
void		init_floorcelling(t_ray *ray);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		key_press(mlx_key_data_t keydata, void *param);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		key_esc(t_map *data);
void		key_left_right(t_map *data, int i);
void		key_down(t_map *data);
void		key_up(t_map *data);
void		key_enter(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		loop(void *param);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		button_play(t_map *data);
void		button_option(t_map *data);
void		button_exit(t_map *data);
void		menu(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		draw_minimap(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
double		normalize_angle(double angle);
double		calculate_fov(double dir_x, double dir_y, double plane_x, \
		double plane_y);
void		mini(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		move_w(t_map *data);
void		move_s(t_map *data);
void		move_a(t_map *data);
void		move_d(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		mouse(mouse_key_t but, action_t action, modifier_key_t mod, \
		void *param);
void		scroll(double i, double y, void *param);
void		cursor(double xpos, double ypos, void *param);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		button_rtn(t_opt *option);
void		button_music(t_opt *option);
void		button_map(t_opt *option);
void		button_fps(t_map *data);
void		button_night(t_opt *option);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		time_fps(t_map	*data);
void		pause_game(t_map *data);
int			get_pc(int value, int size, int max);
void		play_game(t_map *data);
void		exit_cub3d(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		display_item(t_map *data, t_item *item);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		raycasting(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		calcul_projected_cam(t_ray *ray, t_map *data);
void		set_side_step(t_ray *ray, t_map *data, int x);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		rotate_left(t_map *map, double speed);
void		rotate_right(t_map *map, double speed);
void		rotate_cur(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
size_t		ft_strlen_w(char **s);
int			ft_abs(int nb);
void		try_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, int color);
long		get_time(void);
t_vector	set_vector(double x, double y);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/

int			verif_start_line(char *line);

/*═══════════════════════════════════CUB3D════════════════════════════════════*/
/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		len_map(t_map *data);
void		init_null(t_map *data);
void		verif_option(t_opt *option);
int			free_struct(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		free_at_end(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		ft_error(t_map *data);
void		init_anim(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_item(t_item *item, t_map *data);
void		txt_item(char *src, t_item *item);
void		info_item(TXT *tmp, t_map *data, int i);
void		creat_pos_item(t_item *item, t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_door(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_txt_menu(t_map *data);
void		place_img(t_map *data, t_opt *opt);
void		init_mlx_and_new_image(t_map *data);
void		init_txt_menu_option(t_map *data, t_opt *opt);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_player(t_map *data);
void		init_menu_option(t_map *data);
t_button	*init_button(void);
void		init_bool(t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
void		init_struct(char **src, t_map *data);

/*═══════════════════════════color_raycast_bonus.c════════════════════════════*/
t_textures	init_txtr(size_t nb_textures, t_map *data);
void		set_textures_terrain(t_map	*data);

#endif
