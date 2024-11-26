/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tmp_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:35:38 by derey             #+#    #+#             */
/*   Updated: 2024/11/26 13:39:43 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
