/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/08/22 12:15:30 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_null(t_map *data)
{
    data->nord = NULL;
    data->sud = NULL;
    data->oest = NULL;
    data->est = NULL;
    data->down = NULL;
    data->up = NULL;
}

void    free_struct(t_map *data)
{
    if (data->nord)
        free(data->nord);
    if (data->sud)
        free(data->sud);
    if (data->est)
        free(data->est);
    if (data->oest)
        free(data->oest);
    if (data->down)
        free(data->down);
    if (data->up)
        free(data->up);
}

int    main(int argc, char **argv)
{
    t_map   data;

    init_null(&data);
    main_parsing(argc, argv);
    init_struct(argv, &data);
    if (data.nord)
        ft_printf("%s", data.nord);
    if (data.sud)
        ft_printf("%s", data.sud);
    if (data.est)
        ft_printf("%s", data.est);
    if (data.oest)
        ft_printf("%s", data.oest);
    if (data.down)
        ft_printf("%s", data.down);
    if (data.up)
        ft_printf("%s", data.down);
    free_struct(&data);
    return (0);
}
