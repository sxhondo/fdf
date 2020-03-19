/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:13:24 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/19 20:10:17 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

static int		key_handler(int keycode, void *param)
{
	t_fdf		*fp;

	fp = param;
	printf("%d\n", fp->view->zoom);
	printf("keycode: %d\n", keycode);
	if (keycode == LIN_X || keycode == LIN_ESC)
		exit(0);
	return (0);
}

void			key_hook(t_fdf fdf)
{
	mlx_key_hook(fdf.mlx->window, key_handler, &fdf);
}
