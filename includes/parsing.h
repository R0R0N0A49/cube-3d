/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:08 by trebours          #+#    #+#             */
/*   Updated: 2024/09/02 16:03:14 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

void	main_parsing(int len, char **src);
int		parsing_line(char *line, t_map *data, int i, t_test *map);
int		verif_char(t_map *data);
void	print_charerror(char *line, int pos, int posline);

#endif