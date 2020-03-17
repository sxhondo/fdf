/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:33:43 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/16 17:33:43 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			isometry(int *x, int *y, int z)
{
	int				ycart;
	int				xcart;

	*y *= -1;
	xcart = (*x - *y) * cos(0.523599);
	*x = xcart;
	ycart = *y + (*x + z) * sin(0.523599);
	*y = -ycart;
}

static t_point		change_projection(t_view *v, t_point p)
{
	if (v->mode & M_DEFAULT)
	{
		rotation(v, &p.x, &p.y, &p.z);
		isometry(&p.x, &p.y, p.z);
	}
	else if (v->mode & M_ISO)
	{
		rotation(v, &p.x, &p.y, &p.z);
	}
	return (p);
}

static int			colorize(t_view *v, t_point p, uint32_t col_code)
{
	int				color;

	color = 0;
	if (col_code && col_code != 0xffffffff)
		return (col_code);
	else if (v->color == C_DEFAULT)
		color = p.z == 0 ? DEF_TOP_COL : DEF_BOT_COL;
	else if (v->color == C_RETRO)
		color = p.z == 0 ? RET_TOP_COL : RET_BOT_COL;
	else if (v->color == C_PASTEL)
		color = p.z == 0 ? PAS_TOP_COL : PAS_BOT_COL;
	return (color);
}

static t_point		create_point(t_view *v, t_map *map, size_t x, size_t y)
{
	size_t			*m;
	t_point			p;

	m = map->vec->data;
	p.x = (x - map->width / 2) * v->zoom;
	p.y = (y - map->height / 2) * v->zoom;
	p.z = m[x + (y * map->width)] * v->zoom;
	p.color = colorize(v, p, m[x + (y * map->width)] >> 32u);
	p = change_projection(v, p);
	p.x += X_ORIGIN + v->move.x;
	p.y += Y_ORIGIN + v->move.y;
	return (p);
}

t_point				*project_map(t_map *map, t_view *view)
{
	size_t			yi;
	size_t			xi;
	size_t			i;
	t_point			*p;

	i = 0;
	yi = 0;
	if (!(p = (t_point *)malloc(sizeof(t_point) * map->size)))
		display_error(ERR_MEM);
	while (yi < map->height)
	{
		xi = 0;
		while (xi < map->width)
		{
			p[i++] = create_point(view, map, xi, yi);
			xi++;
		}
		yi++;
	}
	return (p);
}
