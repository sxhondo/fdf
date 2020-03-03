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

int				main(int ac, char **av)
{
	t_map		*m;

	if (ac == 2)
	{
		m = read_map(av[1]);
		
		for (int i = 0; i < m->height; i++)
		{
			for (int j = 0; j < m->width; j++)
				ft_printf("%2d", m->grid[i][j]);
			ft_printf("\n");
		}
		ft_free_2d_array(m->grid, m->height);
		free(m);
	}
  	return (0);
}
