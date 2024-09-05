/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:08 by trebours          #+#    #+#             */
/*   Updated: 2024/09/05 16:00:11 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

int		checkline(char **map, int j, int len);
void	main_parsing(int len, char **src);
int		parsing_line(char *line, t_map *data, int i, t_test *map);
int		verif_char(t_map *data);
int 	print_charerror(char **line, int pos, int posline);

#endif