/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:36:14 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/02 20:36:15 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*init_map()
{
	t_map		*m;

	if (!(m = ft_memalloc(sizeof(t_map))))
		display_error("memory allocation failure");
	m->width = 0;
	m->height = 0;
	return (m);
}
