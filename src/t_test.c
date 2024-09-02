/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by trebours          #+#    #+#             */
/*   Updated: 2024/09/02 11:07:41 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_test	*ft_testnew(char *line)
{
	t_test	*new_arg;

	new_arg = malloc(1 * sizeof(t_test));
	if (!new_arg)
		return (NULL);
	new_arg->line_map = ft_strdup(line);
	new_arg->next = NULL;
	return (new_arg);
}

void	ft_testdelone(t_test **list, void (*del)(void*))
{
	if (!list || !del || !*list)
		return ;
	free((*list)->line_map);
	del(*list);
	*list = NULL;
}

void	ft_testclear(t_test **list, void (*del)(void*))
{
	if (!list || !del || !*list)
		return ;
	if (((*list)->next) != NULL)
		ft_testclear(&(*list)->next, del);
	ft_testdelone(list, del);
}

int	testlen(t_test *src)
{
	int		i;
	t_test	*tmp;

	if (!src)
		return (-1);
	if (!src->line_map)
		return (0);
	tmp = src;
	if (!tmp)
		return (0);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**ft_test_to_tab(t_test *src)
{
	int		i;
	char 	**map;
	t_test	*tmp;

	if (!src)
		return (NULL);
	ft_printf("len = %d\n", testlen(src));
	map = ft_calloc(testlen(src) + 1, sizeof(src));
	tmp = src;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->line_map);
//		ft_printf("tmp->line_map = %s", tmp->line_map);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (map);
}
