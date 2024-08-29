/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/08/29 11:00:31 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "libft/libft.h"
# include "parsing.h"
# include <fcntl.h>
# include <unistd.h>

void	init_struct(char **src, t_map *data);
void	free_struct(t_map *data);
void	print_error(char *line);
int		verif_start_line(char *line);

void	mini_map(t_map *data, mlx_t *mlx);
void	key_press(mlx_key_data_t keydata, void *param);
void	left(t_map *data);
void	right(t_map *data);
void	botom(t_map *data);
void	high(t_map *data);

#endif
