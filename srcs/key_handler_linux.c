/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:13:24 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/15 18:54:47 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define K_EXT_0 		7
#define K_EXT_1 		53
#define K_ZOOM_PLUS		24
#define K_ZOOM_MINUS	27
#define K_ROTATE_X_1	1
#define K_ROTATE_X_2 	13
#define K_ROTATE_Y_1	0
#define K_ROTATE_Y_2	2
#define K_ROTATE_Z_1 	14
#define K_ROTATE_Z_2	12
#define K_P_MODE		6
#define K_C_MODE		8
#define K_ARR_LEFT		123
#define K_ARR_RIGHT		124
#define K_ARR_UP		126
#define	K_ARR_DOWN		125

static int 		key_handler(int keycode, void *param)
{
	t_fdf		*f;
	
	f = param;
	ft_printf("key: [%d]\n", keycode);
	ft_printf("width: %d\n", f->map->width);
	if (keycode == K_EXT_0 || keycode == K_EXT_1)
		exit(0);
	// else if (keycode == K_ZOOM_PLUS || keycode == K_ZOOM_MINUS)
	// {
	// 	f->view->zoom += keycode == K_ZOOM_PLUS ? 1 : -1;
	// 	if (f->view->zoom <= 0)
	// 		f->view->zoom = 1;
	// }
	// else if (keycode == 119 || keycode == 115)
	// 	f->view->x_alpha += keycode == K_ROTATE_X_1 ? 0.1 : -0.1;
	// else if (keycode == K_ROTATE_Y_1 || keycode == K_ROTATE_Y_2)
	// 	f->view->y_alpha += keycode == K_ROTATE_Y_1 ? 0.1 : -0.1;
	// else if (keycode == K_ROTATE_Z_1 || keycode == K_ROTATE_Z_2)
	// 	f->view->z_alpha += keycode == K_ROTATE_Z_1 ? 0.1 : -0.1;
	// else if (keycode == K_P_MODE)
	// {
	// 	f->view->x_alpha = 0;
	// 	f->view->y_alpha = 0;
	// 	f->view->z_alpha = 0;
	// 	if (++(f->view->mode) > M_ISO)
	// 		f->view->mode = M_DEFAULT;
	// }
	// else if (keycode == K_C_MODE)
	// {
	// 	if (++(f->view->color) > C_PASTEL)
	// 		f->view->color = C_DEFAULT;
	// }
	// else if (keycode == K_ARR_LEFT || keycode == K_ARR_RIGHT 
	// 	|| keycode == K_ARR_UP || keycode == K_ARR_DOWN)
	// {
	// 	if (keycode == K_ARR_LEFT)
	// 		f->view->move.x -= WIDTH / 100;
	// 	if (keycode == K_ARR_RIGHT)
	// 		f->view->move.x += WIDTH / 100;
	// 	if (keycode == K_ARR_DOWN)
	// 		f->view->move.y += HEIGHT / 100;
	// 	if (keycode == K_ARR_UP)
	// 		f->view->move.y -= HEIGHT / 100;
	// }
	// drawing(f->map, f->view, f->mlx);
	return (0);
}

void			key_hook(t_fdf fdf)
{
	mlx_key_hook(fdf.mlx->window, key_handler, &fdf);
}
