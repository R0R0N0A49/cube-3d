/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:45 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 14:12:23 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"

# define TXT mlx_texture_t
# define IMG mlx_image_t
# define WINDOWSW 1920
# define WINDOWSH 1080
# define CUBE 30
# define FOG 0xFF
# define FOG_MIN 1
# define FOG_MAX 4
# define MINIMAP_SCALE 30
# define MINIMAP_OFFSET_X 700
# define MINIMAP_OFFSET_Y 200
# define X_MINI 1720
# define Y_MINI 200
# define R_MINI 150

# include <time.h>

typedef struct s_raymini
{
	double	center_angle;
	double	fov;
	double	angle_left;
	double	angle_right;
	int		num_rays;
	int		dist_sq;
	int		i;
	double	t;
	double	ray_angle;
	double	ray_x;
	double	ray_y;
	double	step_x;
	double	step_y;
	int		hit;
	int		map_x;
	int		map_y;
	int		screen_x;
	int		screen_y;
	int		step;
}	t_raymini;

typedef struct s_mini
{
	int		pos_x;
	int		pos_y;
	int		map_x;
	int		map_y;
	double	iso_x;
	double	iso_y;
	int		diamond_width;
	int		diamond_height;
	int		mini_x;
	int		mini_y;
	int		corners[4][2];
	double	slope;
	int		adj_color;
	double	dx;
	double	dy;
}	t_mini;

typedef struct s_tmp
{
	char			*line_map;
	struct s_tmp	*next;
}	t_tmp;

typedef struct s_line_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line_bresenham;

typedef struct s_game
{
	double	player_y;
	double	player_x;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	cursor_x;
	double	cursor_y;
	bool	move_w;
	bool	move_a;
	bool	move_d;
	bool	move_s;
	bool	moove_cur;
	bool	rotate_left;
	bool	rotate_right;
}	t_game;

typedef struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	double		wall_dist;
	double		wall_x;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			texture_x;
	int			texture_y;
	double		current_fc_x;
	double		current_fc_y;
	double		fl_x;
	double		fl_y;
	uint32_t	color;
	double		step;
	double		texture_pos;
	bool		isdoor;
}	t_ray;

typedef struct s_button
{
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	bool	click;
	bool	good;
	bool	press_enter;
}	t_button;

typedef struct s_textures
{
	char			**textures_name;
	mlx_texture_t	**textures;
	mlx_image_t		**image;
	size_t			nb_textures;
}	t_textures;

typedef struct s_weapon
{
	t_textures	walk;
	int			index_walk;
}	t_weapon;

typedef struct s_item
{
	double	dist;
	double	posy;
	double	posx;
	int		index;
	TXT		**textures; // a remplacer
	bool	enabled;
	bool	isvisible;
	int		x;
	int		x_max;
	double	item_dist;
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		height;
	int		width;
	int		drawstart_y;
	int		drawstart_x;
	int		drawend_y;
	int		drawend_x;
	int		px;
	int		py;
	int		tex_x;
	int		tex_y;
	int		d;
}	t_item;

typedef struct s_anim
{
	bool		enable_anim;
	int			nb_availed_weapon;
	int			index_weapon;
	t_weapon	barrel;
	t_weapon	e11;
	t_item		item;
	long		time;
	IMG			*center;
	TXT			*center_txt;
	IMG			**selected;
}	t_anim;

typedef struct s_option
{
	bool		visible;
	IMG			*bottom;
	IMG			*cub;
	IMG			*rtn;
	TXT			*rtn_txt;
	t_button	*but_rtn;
	t_button	*but_music;
	t_button	*but_map;
	t_button	*but_fps;
	t_button	*but_night;
	int			index;
	bool		play_music;
	bool		display_fps;
	bool		night_mode;
	bool		display_map;
	TXT			*valid_txt;
	TXT			*unvalid_txt;
	IMG			*valid;
	IMG			*unvalid;
	TXT			*music_txt;
	IMG			*music;
	TXT			*mini_txt;
	IMG			*mini;
	TXT			*fps_txt;
	IMG			*fps;
	TXT			*roof_txt;
	IMG			*roof;
}	t_opt;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_door
{
	TXT		**door;
	bool	isvisible;
	bool	isopen;
	double	i;
	double	j;
	int		x;
	int		side;
	double	sidedist_x;
	double	sidedist_y;
	int		map_x;
	int		map_y;
	double	dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_x;
	int		texture_y;
	double	door_x;
	double	door_y;
	double	raydir_x;
	double	raydir_y;
	double	step;
	double	texture_pos;
	double	dist_center;
	bool	isanime;
	int		index;
	long	time;
}	t_door;

typedef struct s_map
{
	t_opt		*menu_option;
	int			file;
	char		**map;
	int			len_map;
	TXT			*so;
	TXT			*no;
	TXT			*ea;
	TXT			*we;
	TXT			*cub;
	TXT			*texplay;
	TXT			*texopt;
	TXT			*texexit;
	TXT			*night;
	TXT			*floor;
	TXT			*cell;
	TXT			*menufd;
	TXT			*menufd2;
	IMG			*cubd;
	IMG			*img_play;
	IMG			*img_option;
	IMG			*img_exit;
	uint32_t	up;
	uint32_t	down;
	IMG			*rayc;
	IMG			*minima;
	IMG			*mini_iso;
	IMG			*menu;
	double		rotspeed;
	double		speed;
	bool		fog;
	bool		press;
	bool		pause;
	bool		ceiling;
	int			idx_menu;
	int			fps;
	int			w_map;
	int			h_map;
	char		*ifps;
	time_t		time_fps;
	t_ray		*raycast;
	t_mini		*m_map;
	t_game		*game;
	t_textures	font;
	t_button	*but_play;
	t_button	*but_option;
	t_button	*but_exit;
	mlx_t		*mlx;
	t_anim		weapon;
	t_door		*door;
	int			nmb_door;
}	t_map;

char	**ft_tmp_to_tab(t_tmp *src);
void	ft_tmpadd_back(t_tmp **lst, t_tmp *new_tail);
int		ft_tmplen(t_tmp *src);
void	ft_tmpclear(t_tmp **list, void (*del)(void*));
void	ft_tmpdelone(t_tmp **list, void (*del)(void*));
t_tmp	*ft_tmpnew(char *line);

#endif