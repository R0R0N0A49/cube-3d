/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:29 by trebours          #+#    #+#             */
/*   Updated: 2024/08/21 10:22:29 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include <stdlib.h>

int    main(int argc, char **argv)
{
    if (main_parsing(argc, argv))
        return (1);
    system("/bin/ls");
    return (0);
}
