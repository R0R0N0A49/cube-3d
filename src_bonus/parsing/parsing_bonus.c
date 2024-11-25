/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:02:22 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:09:52 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_bonus.h"

void	ft_verif_cub(char *src)
{
	size_t	len_src;
	int		i;

	len_src = ft_strlen(src);
	i = 0;
	if (len_src <= 4)
		i = 15;
	else if (src[len_src - 1] != 'b')
		i++;
	else if (src[len_src - 2] != 'u')
		i++;
	else if (src[len_src - 3] != 'c')
		i++;
	else if (src[len_src - 4] != '.')
		i++;
	if (i > 0)
		error_file(src, 1);
}

void	main_parsing(int len, char **src)
{
	if (len != 2)
		error_file(src[1], 2);
	ft_verif_cub(src[1]);
}
