/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:12 by trebours          #+#    #+#             */
/*   Updated: 2024/08/21 15:57:07 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	verif(char *line, t_map *data)
{
	(void)data;
	ft_printf("%s", line);
	return (1);
}

void	parsing_line(char *line, t_map *data)
{
	static int	i = 0;

	if (i < 5)
		i += verif(line, data);

}
