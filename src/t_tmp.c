/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/11/17 16:46:47 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_tmp	*ft_tmplast(t_tmp *lst)
{
	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst);
	return (ft_tmplast(lst->next));
}

void	ft_tmpadd_back(t_tmp **lst, t_tmp *new_tail)
{
	if (!lst || !new_tail)
		return ;
	if (!*lst)
	{
		*lst = new_tail;
		return ;
	}
	ft_tmplast(*lst)->next = new_tail;
}

t_tmp	*ft_tmpnew(char *content)
{
	t_tmp	*res;

	res = ft_calloc(1, sizeof(t_tmp));
	if (!res)
		return (NULL);
	res->line_map = ft_strdup(content);
	res->next = NULL;
	return (res);
}

int	ft_tmplen(t_tmp *src)
{
	int		i;
	t_tmp	*tmp;

	if (!src)
		return (-1);
	if (!src->line_map)
		return (0);
	i = 0;
	tmp = src;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**ft_tmp_to_tab(t_tmp *src)
{
	int		i;
	char	**map;
	t_tmp	*tmp;

	if (!src || !ft_tmplen(src))
		return (NULL);
	map = ft_calloc(ft_tmplen(src) + 1, sizeof(src));
	tmp = src;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->line_map);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (map);
}
