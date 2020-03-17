/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:13:12 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 19:13:12 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			drawing(t_map *map, t_view *view, t_mlx *mlx)
{
	size_t		i;
	t_point		*proj;

	i = 0;
	draw_background(mlx, view);
	proj = project_map(map, view);
	while (i < map->size)
	{
		if (i + map->width < map->size)
			draw_line(proj[i], proj[i + map->width], mlx);
		if ((i + 1) < map->size && (i + 1) % map->width)
			draw_line(proj[i], proj[i + 1], mlx);
		i++;
	}
	free(proj);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}
