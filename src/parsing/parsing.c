/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:02:22 by trebours          #+#    #+#             */
/*   Updated: 2024/08/21 17:15:46 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	ft_verif_cub(char *src)
{
	size_t	len_src;
	int	i;

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
	{
		ft_printf("Error\nthe file has the wrong format\n");
		exit(1);
	}
}

void main_parsing(int len, char **src)
{
	if (len != 2)
	{
		ft_printf("Error\ncub3d nead a file\n");
		exit(2);
	}
	ft_verif_cub(src[1]);
}
