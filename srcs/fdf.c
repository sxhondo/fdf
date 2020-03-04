/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:36:27 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/02 20:36:28 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		key_press(int keycode, void *param)
{
	(void )param;
	ft_printf("[%d]\n", keycode);
	if (keycode == 7)
		exit(0);
	return (0);
}

void		key_hook(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 1L << 17, key_press, mlx);
}

int				main(int ac, char **av)
{
	t_view		*view;
	t_mlx		*mlx;
	t_map		*map;

	if (ac == 2)
	{
		map = read_map(av[1]);
		mlx = init_mlx();
		view = init_view(map);
		key_hook(mlx);
		
		drawing(map, view, mlx);
		ft_vec_del(&map->vec);
		free(map);
	}
  	return (0);
}
