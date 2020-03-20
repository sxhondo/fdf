/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:13:25 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/20 14:09:38 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_fdf		f;

	if (ac == 2)
	{
		f.map = read_map(av[1]);
		f.mlx = init_mlx();
		f.view = init_view(f.map);
		key_hook(&f);
		drawing(f.map, f.view, f.mlx);
		mlx_loop(f.mlx->mlx);
		ft_vec_del(&f.map->vec);
	}
	ft_printf("usage: ./fdf map_file\n");
	return (0);
}
