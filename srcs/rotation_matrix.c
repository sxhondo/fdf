/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:16:46 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 19:21:54 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			mult_xyz(double rmatrix[3][3], int *x, int *y, int *z)
{
	const int 		xyz[3] = {*x, *y, *z};
	int 			res[3];
	int 			i;

	i = 0;
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	while (i < 3)
	{
		res[0] += (rmatrix[i][0] * xyz[i]);
		res[1] += (rmatrix[i][1] * xyz[i]);
		res[2] += (rmatrix[i][2] * xyz[i]);
		i += 1;
	}
	*x = res[0];
	*y = res[1];
	*z = res[2];
}

 
 void				x_rotation(double alpha, int *x, int *y, int *z)
{
	const double 	cosA = cos(alpha);
	const double	sinA = sin(alpha);
	const double 	matrix[3][3] = {
		{1.0, 0.0, 0.0},
		{0.0, cosA, -sinA},
		{0.0, sinA, cosA}
	};
	mult_xyz(&matrix, x, y, z);
}
