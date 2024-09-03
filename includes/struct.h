/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:45 by trebours          #+#    #+#             */
/*   Updated: 2024/09/03 11:03:01 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MLX42/include/MLX42/MLX42.h"

# define TXT mlx_texture_t
# define IMG mlx_image_t

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
}	t_map;

char	**ft_test_to_tab(t_test *src);
int		testlen(t_test *src);
void	ft_testclear(t_test **list, void (*del)(void*));
void	ft_testdelone(t_test **list, void (*del)(void*));
t_test	*ft_testnew(char *line);

#endif