/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <derey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:59:08 by trebours          #+#    #+#             */
/*   Updated: 2024/11/25 13:07:53 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

double	ft_fmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_fmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static double	cross_product(t_vector p1, t_vector p2, t_vector p3)
{
	return ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
}

static int	is_point_on_segment(t_vector p, t_vector q, t_vector r)
{
	return (r.x <= ft_fmax(p.x, q.x) && r.x >= ft_fmin(p.x, q.x) && \
			r.y <= ft_fmax(p.y, q.y) && r.y >= ft_fmin(p.y, q.y));
}

int	is_line_hitting_segment(t_vector v1p1, t_vector v1p2, \
	t_vector v2p1, t_vector v2p2)
{
	double	d1;
	double	d2;
	double	d3;
	double	d4;

	d1 = cross_product(v1p1, v1p2, v2p1);
	d2 = cross_product(v1p1, v1p2, v2p2);
	d3 = cross_product(v2p1, v2p2, v1p1);
	d4 = cross_product(v2p1, v2p2, v1p2);
	if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
		return (1);
	if (d1 == 0 && is_point_on_segment(v1p1, v1p2, v2p1))
		return (1);
	if (d2 == 0 && is_point_on_segment(v1p1, v1p2, v2p2))
		return (1);
	if (d3 == 0 && is_point_on_segment(v2p1, v2p2, v1p1))
		return (1);
	if (d4 == 0 && is_point_on_segment(v2p1, v2p2, v1p2))
		return (1);
	return (0);
}
