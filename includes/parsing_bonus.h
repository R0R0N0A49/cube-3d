/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:08 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 14:12:19 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "cub3d_bonus.h"
# define RED "\033[1;31m"
# define WHITE "\033[1;m"

int			print_charerror(char **line, int posline, int pos, t_map *data);
void		error_colors(char *line, int index, t_map *data, t_tmp *map);
int			parsing_line(char *line, t_map *data, int i, t_tmp *map);
void		check_space(char **map, int j, char fst, char scd);
int			checkline(char **map, int j, int len, t_map *data);
void		print_error(char *line, t_map *data, t_tmp *map);
uint32_t	pasthexa(char *line, t_map *data, t_tmp *map);
int			middle_line(char **map, int j, t_map *data);
int			first_line(char **map, int j, t_map *data);
int			last_line(char **map, int j, t_map *data);
void		error_player(int player, t_map *data);
int			pars_door(char **map, t_map *data);
void		main_parsing(int len, char **src);
void		error_file(char *file, int index);
void		ft_free_stringtab(char **src);
int			verif_char(t_map *data);
int			isplayer(char const c);
TXT			*verif_png(char *png);

#endif