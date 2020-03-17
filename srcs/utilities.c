/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:11:02 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/04 21:11:02 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			valid_char(char ch)
{
	return ((ch >= '0' && ch <= '9')
		|| (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'));
}

int					get_hex(const char *str, size_t *res)
{
	unsigned long	nb;
	size_t			i;

	i = 0;
	nb = 0;
	if (!ft_strnequ(str, "0x", 2))
		return (0);
	str += 2;
	while (*str)
	{
		if (valid_char(*str))
		{
			if (*str >= '0' && *str <= '9')
				nb = nb * 16 + (*str - '0');
			else if (*str >= 'a' && *str <= 'f')
				nb = nb * 16 + (*str - 'a' + 10);
			else if (*str >= 'A' && *str <= 'F')
				nb = nb * 16 + (*str - 'A' + 10);
			str += 1;
		}
		else
			return (0);
	}
	*res = (int)(nb);
	return (1);
}

size_t				fdf_atoi(const char *str, size_t *color)
{
	unsigned long	nb;
	int				sign;
	size_t			i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (!(get_hex(str + i + 1, color)))
				display_error(ERR_MAP);
			break ;
		}
		if (str[i] < '0' || str[i] > '9')
			display_error(ERR_MAP);
		nb = nb * 10 + (str[i++] - '0');
	}
	return ((*color << 32u) | (nb * sign));
}

void				display_error(char *text)
{
	ft_fprintf(2, "%s\n", text);
	exit(1);
}
