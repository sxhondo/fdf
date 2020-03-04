/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:52:42 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/04 13:52:43 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point 		point(t_view *v, size_t x, size_t y)
{
	t_point		p;

	p.x = (x * v->zoom) + WIDTH / 4;
	p.y = y * v->zoom + HEIGHT / 4;

	return (p);
}

void			drawing(t_map *map, t_view *view, t_mlx *mlx)
{
	size_t		*m;
	int			yi;
	int			xi;

	// draw_background(mlx);
	yi = 0;
	m = map->vec->data;
	while (yi < map->height)
	{
		xi = 0;
		while (xi < map->width)
		{
			if (yi + 1 < map->height)
				draw_line(point(view, xi, yi), point(view, xi, yi + 1), mlx);
			if (xi + 1 < map->width)
				draw_line(point(view, xi, yi), point(view, xi + 1, yi), mlx);
			xi++;
		}
		yi++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
}