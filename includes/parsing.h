/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:08 by trebours          #+#    #+#             */
/*   Updated: 2024/09/18 15:44:03 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
#define RED "\033[1;31m"
#define WHITE "\033[1;m"

int		checkline(char **map, int j, int len, t_map *data);
void	main_parsing(int len, char **src);
int		parsing_line(char *line, t_map *data, int i, t_tmp *map);
int		verif_char(t_map *data);
int		print_charerror(char **line, int posline, int pos, t_map *data);
void	check_space(char **map, int j, char fst, char scd);
void	ft_free_stringtab(char **src);
void	error_file(char *file, int index);
void	error_colors(char *line, int index, t_map *data, t_tmp *map);
void	error_player(int player, t_map *data);
void	print_error(char *line, t_map *data, t_tmp *map); // a enlever et a passer dans parsing

#endif