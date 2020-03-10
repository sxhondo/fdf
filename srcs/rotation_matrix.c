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

/*
** 	float mx[3][3] = {
**	{cosA, 0.0f, sinA},
**	{0.0f, 1.0f, 0.0f},
**	{-sinA, 0.0f, cosA}
**	};
*/

// void				y_rotation(int alpha, int y_rot[3][3])
// {
// 	const int		cosA = cos(alpha);
// 	const int 		sinA = sin(alpha);
	
// 	y_rot[0][0] = cosA;
// 	y_rot[0][1] = 0;
// 	y_rot[0][2] = sinA;

// 	y_rot[1][0] = 0;
// 	y_rot[1][1] = 1;
// 	y_rot[1][2] = 0;
	
// 	y_rot[2][0] = -sinA;
// 	y_rot[2][1] = 0;
// 	y_rot[2][2] = cosA;
// }

/*
** 	float mx[3][3] = {
**	{cosA, -sinA, 0.0f},
**	{sinA, cosA, 0.0f},
**	{0.0f, 0.0f, 1.0f}
**	};
*/

// void				z_rotation(int alpha, int z_rot[3][3])
// {
// 	const int		cosA = cos(alpha);
// 	const int 		sinA = sin(alpha);
	
// 	z_rot[0][0] = cosA;
// 	z_rot[0][1] = -sinA;
// 	z_rot[0][2] = 0;

// 	z_rot[1][0] = sinA;
// 	z_rot[1][1] = cosA;
// 	z_rot[1][2] = 0;
	
// 	z_rot[2][0] = 0;
// 	z_rot[2][1] = 0;
// 	z_rot[2][2] = 1;
// }

/*
** 	float mx[3][3] = {
**	{1.0f, 0.0f, 0.0f},
**	{0.0f, cosA, -sinA},
**	{0.0f, sinA, cosA}
**	};
*/
 
void				x_rotation(int alpha, float x_rot[3][3])
{
	const float		cosA = (float)cos(alpha);
	const float		sinA = (float)sin(alpha);
	
	// ft_printf("%d : %d\n", cosA, sinA);

	x_rot[0][0] = 1.0f;
	x_rot[0][1] = 0.0f;
	x_rot[0][2] = 0.0f;

	x_rot[1][0] = 0.0f;
	x_rot[1][1] = cosA;
	x_rot[1][2] = -sinA;
	
	x_rot[2][0] = 0.0f;
	x_rot[2][1] = sinA;
	x_rot[2][2] = cosA;	
}

void 				apply_rotation(t_view *v, int *x, int *y, int *z)
{
	const int		xyz[3] = {*x, *y, *z};
	int 			res;
	int 			i;


	// for (int i = 0; i < 3; i++)
	// {
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		ft_printf("%f ", v->x_rot[i][j]);
	// 	}
	// 	ft_printf("\n");
	// }
	// exit(0);


	i = -1;
	res = 0;
	while (++i < 3)
		res += v->x_rot[i][0] * xyz[i];
	*x = res;

	i = -1;
	res = 0;	
	while (++i < 3)
		res += v->x_rot[i][1] * xyz[i];
	*y = res;

	i = -1;
	res = 0;
	while (++i < 3)
		res += v->x_rot[i][2] * xyz[i];
	*z = res;

}