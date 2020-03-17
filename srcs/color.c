/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:35:06 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/13 14:35:06 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double			get_percent(int start, int end, int current)
{
	double				placement;
	double				distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int						get_gradient(t_point cur, t_point src, t_point dst,
	int sign)
{
	int					r;
	int					g;
	int					b;
	double				percent;

	if (cur.color == dst.color)
		return (cur.color);
	if (sign == -1)
		percent = get_percent(src.x, dst.x, cur.x);
	if (sign == 1)
		percent = get_percent(src.y, dst.y, cur.y);
	r = get_light((src.color >> 16) & 0xFF, (dst.color >> 16) & 0xFF, percent);
	g = get_light((src.color >> 8) & 0xFF, (dst.color >> 8) & 0xFF, percent);
	b = get_light((src.color) & 0xFF, (dst.color) & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
}
