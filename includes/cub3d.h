/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:00 by trebours          #+#    #+#             */
/*   Updated: 2024/08/28 14:07:37 by trebours         ###   ########.fr       */
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
void	ft_lstadd_back(t_test **lst, t_test *new_tail);

#endif
