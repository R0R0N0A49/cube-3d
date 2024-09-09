/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:45 by trebours          #+#    #+#             */
/*   Updated: 2024/09/05 17:03:49 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MLX42/include/MLX42/MLX42.h"

# define TXT mlx_texture_t
# define IMG mlx_image_t
# define H_CUBE 20
# define W_CUBE 20
# define ARROUND 3
# define COLOR_GRID 0x646464

typedef struct s_mini
{
	int pos_x;
	int pos_y;
	TXT *red_t;
	TXT *white_t;
	TXT *player_t;
	IMG *red;
	IMG *white;
	IMG *player;
}	t_mini;

typedef struct s_game
{
	mlx_image_t *frame;
	int triangle_x;
	int triangle_y;
	double angle;
	int 	moove;
	int		move;
	bool rotating_left;
	bool rotating_right;
} t_game;

typedef struct s_test
{
	char			*line_map;
	struct s_test	*next;
}	t_test;

typedef struct s_map
{
	TXT		*so;
	TXT		*no;
	TXT		*ea;
	TXT		*we;
	char	*up;
	char	*down;
	char	**map;
	int		len_map;
	IMG 	*minima;
	t_mini	*mini_map;
	t_game	*game;
	mlx_t	*mlx;
}	t_map;

char	**ft_test_to_tab(t_test *src);
int		testlen(t_test *src);
void	ft_testclear(t_test **list, void (*del)(void*));
void	ft_testdelone(t_test **list, void (*del)(void*));
t_test	*ft_testnew(char *line);

#endif