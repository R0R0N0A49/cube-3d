/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:36:33 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 15:36:33 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_len(const char *l1, const char *l2, int i)
{
	size_t	len_1;
	size_t	len_2;
	size_t	little;

	len_1 = ft_strlen(l1);
	len_2 = ft_strlen(l2);
	if (len_1 <= len_2)
		little = len_1;
	else
		little = len_2;
	if (i < (int)little)
		return (1);
	return (0);
}

static void	check_space_loop(char **map, int j, int i, char scd)
{
	if (map[j + 1] && check_len(map[j], map[j + 1], i) && \
					(map[j + 1][i] == '0' || isplayer(map[j + 1][i])))
		map[j][i] = scd;
	if (j == 2 && check_len(map[j], map[j - 1], i) && (map[j - 1][i] == \
					'0' || isplayer(map[j - 1][i])))
		map[j][i] = scd;
	if (i && (map[j][i - 1] == '0' || isplayer(map[j][i - 1])))
		map[j][i] = scd;
	if (map[j][i + 1] == 0 || isplayer(map[j][i + 1]))
		map[j][i] = scd;
}

void	check_space(char **map, int j, char fst, char scd)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (map[j][i])
	{
		if (j && map[j][i] == '1')
			t = 1;
		if (j == 0 && map[j][i] == '2')
			map[j][i] = ' ';
		if (t && (map[j][i] == fst))
		{
			check_space_loop(map, j, i, scd);
		}
		i++;
	}
}
