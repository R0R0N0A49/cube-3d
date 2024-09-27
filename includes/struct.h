/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:45 by trebours          #+#    #+#             */
/*   Updated: 2024/09/27 13:08:52 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MLX42/include/MLX42/MLX42.h"

# define TXT mlx_texture_t
# define IMG mlx_image_t
# define WINDOWSW 1920
# define WINDOWSH 1080
# define CUBE 20
# define COLOR_GRID 0x646464
# define FOG 0xFF
# define FOG_MIN 4
# define FOG_MAX 16

typedef struct s_mini
{
	int	pos_x;
	int	pos_y;
}	t_mini;

typedef struct s_tmp
{
	char			*line_map;
	struct s_tmp	*next;
}	t_tmp;

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
	bool	rotate_left;
	bool	rotate_right;
}	t_game;


typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	double wall_dist;
	double wall_x;
	int side;
	int line_height;
	int draw_start;
	int draw_end;
	int	texture_x;
	int	texture_y;
	uint32_t	color;
	double step;
	double texture_pos;
}	t_ray;

typedef	struct s_button
{
	int	but_x_min;
	int	but_x_max;
	int	but_y_min;
	int	but_y_max;
	bool	click;
	bool	good;
	bool	press_enter;
} t_button;

typedef struct s_option
{
	IMG			*bottom;
	IMG			*cub;
	IMG			*rtn;
	TXT			*rtn_txt;
	bool		option;
	t_button	*but_rtn;
	t_button	*but_music;
	t_button	*but_fov;
	t_button	*but_floor;
	t_button	*but_roof;

	bool		play_music;
	bool		txt_floor;
	bool		txt_roof;
	bool		show_fov;

	TXT			*valid_txt;
	TXT			*unvalid_txt;

	IMG			*m_valid;
	IMG			*f_valid;
	IMG			*fl_valid;
	IMG			*r_valid;

	IMG			*m_unvalid;
	IMG			*f_unvalid;
	IMG			*fl_unvalid;
	IMG			*r_unvalid;

	TXT			*music_txt;
	IMG			*music;

	TXT			*fov_txt;
	IMG			*fov;

	TXT			*floor_txt;
	IMG			*floor;

	TXT			*roof_txt;
	IMG			*roof;
} t_opt;

typedef struct s_map
{
	t_opt	*opt;
	int		file;
	char	**map;
	int		len_map;
	int		w;
	int		h;
	TXT		*so;
	TXT		*no;
	TXT		*ea;
	TXT		*we;
	TXT		*cub;
	TXT		*texplay;
	TXT		*texopt;
	TXT		*texedi;
	TXT		*texexit;
	TXT		*nuit;
	TXT		*menufd;
	TXT		*menufd2;
	IMG		*cubd;
	IMG		*img_play;
	IMG		*img_option;
	IMG		*img_edit;
	IMG		*img_exit;
	uint32_t	up;
	uint32_t	down;
	IMG		*rayc;
	IMG		*minima;
	IMG		*menu;
	double	rotspeed;
	double 	speed;
	bool	fog;
	bool	press;
	bool	pause;
	bool	plafond;
	int		idx_menu;
	t_ray	*raycast;
	t_mini	*mini_map;
	t_game	*game;
	t_button	*but_play;
	t_button	*but_option;
	t_button	*but_edit;
	t_button	*but_exit;
	mlx_t	*mlx;
}	t_map;

char	**ft_tmp_to_tab(t_tmp *src);
void	ft_tmpadd_back(t_tmp **lst, t_tmp *new_tail);
int		ft_tmplen(t_tmp *src);
void	ft_tmpclear(t_tmp **list, void (*del)(void*));
void	ft_tmpdelone(t_tmp **list, void (*del)(void*));
t_tmp	*ft_tmpnew(char *line);

#endif