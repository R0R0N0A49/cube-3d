/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:45 by trebours          #+#    #+#             */
/*   Updated: 2024/09/16 09:19:59 by derey            ###   ########.fr       */
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

typedef struct s_mini
{
	int pos_x;
	int pos_y;
}	t_mini;

typedef struct s_test
{
	char			*line_map;
	struct s_test	*next;
}	t_test;

typedef struct s_ray
{
	int	wallW;
	int	wallH;
}	t_ray;

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
	IMG		*rayc;
	IMG 	*minima;
	t_ray	*raycast;
	t_mini	*mini_map;
	mlx_t	*mlx;
}	t_map;

char	**ft_test_to_tab(t_test *src);
int		testlen(t_test *src);
void	ft_testclear(t_test **list, void (*del)(void*));
void	ft_testdelone(t_test **list, void (*del)(void*));
t_test	*ft_testnew(char *line);

#endif