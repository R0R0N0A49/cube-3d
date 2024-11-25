/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tmp_clear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:09:34 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	ft_tmpdelone(t_tmp **list, void (*del)(void*))
{
	if (!list || !del || !*list)
		return ;
	free((*list)->line_map);
	free(*list);
	*list = NULL;
}

void	ft_tmpclear(t_tmp **list, void (*del)(void*))
{
	if (!list || !del || !*list)
		return ;
	if (((*list)->next) != NULL)
		ft_tmpclear(&(*list)->next, del);
	ft_tmpdelone(list, del);
}
