/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:45 by trebours          #+#    #+#             */
/*   Updated: 2024/08/22 12:29:56 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MLX42/include/MLX42/MLX42.h"

# define txt mlx_texture_t
# define img mlx_image_t

typedef struct s_map
{
	char	*sud;
	char	*nord;
	char	*est;
	char	*oest;
	char	*up;
	char	*down;
	char	**map;
} t_map;

#endif