/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:13:24 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 15:13:25 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define K_EXT_0 		7
#define K_EXT_1 		53
#define K_ZOOM_PLUS		69
#define K_ZOOM_MINUS	78
#define K_ROTATE_X_1	84
#define K_ROTATE_X_2 	91

static int 		key_handler(int keycode, void *param)
{
	t_fdf		*f;
	
	f = param;
	ft_printf("[%d]\n", keycode);
	if (keycode == K_EXT_0 || keycode == K_EXT_1)
		exit(0);
	else if (keycode == K_ZOOM_PLUS || keycode == K_ZOOM_MINUS)
	{
		f->view->zoom += keycode == K_ZOOM_PLUS ? 1 : -1;
		drawing(f->map, f->view, f->mlx);
	}
	else if (keycode == K_ROTATE_X_1 || keycode == K_ROTATE_X_2)
	{
		f->view->x_r += keycode == K_ROTATE_X_1 ? 1 : -1;
		drawing(f->map, f->view, f->mlx);
	}
	return (0);
}

void			key_hook(t_fdf *fdf)
{
	mlx_hook(fdf->mlx->window, 2, 1L << 17, key_handler, fdf);
}
