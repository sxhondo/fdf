/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:50:52 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/02 20:50:53 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char **open_file(char *path)
{
	char 	**split;
	t_vec	*file;
	int 	fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		display_error(ERR_READ);
	if (!(file = ft_vec_read(fd)))
		display_error(ERR_MEM);
	if (!(split = ft_strsplit(file->data, '\n')))
		display_error(ERR_MEM);
	ft_vec_del(&file);
	close(fd);
	return (split);
}

int32_t				fdf_atoi(const char *str, int32_t *color)
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
			if (!(ft_atoi_base(str + i + 1, color, 16)))
				display_error(ERR_MAP);
			break ;
		}
		if (str[i] < '0' || str[i] > '9')
		{
			display_error(ERR_MAP);
		}
		nb = nb * 10 + (str[i++] - '0');
	}
	return ((int32_t)(nb * sign));
}

static void 		parse_line(t_vec **vec, char *line, size_t *map_width)
{
	size_t 			i;
	size_t			val;
	int32_t			col;
	char 			**ln;

	i = -1;
	if (!(ln = ft_strsplit(line, ' ')))
		display_error(ERR_MEM);
	while (ln[++i])
	{
		col = 0xFFFFFF;
		val = fdf_atoi(ln[i], &col);
		ft_vec_add(vec, &val);
	}
	if (*map_width != 0 && i != *map_width)
		display_error(ERR_MAP);
	*map_width = i;
	ft_strsplit_free(ln);
}

t_map			*read_map(char *path)
{
	size_t 		i;
	t_vec		*vec;
	char 		**file;
	t_map		*map;

	i = -1;
	map = init_map();
	file = open_file(path);
	if (!(vec = ft_vec_init(1, sizeof(size_t))))
		display_error(ERR_MEM);
	while (file[++i])
	{
		parse_line(&vec, file[i], &map->width);
		map->height += 1;
	}
	if (!(ft_vec_resize(&vec)))
		display_error(ERR_MEM);
	map->vec = vec;
	map->size = vec->total;
	ft_strsplit_free(file);
	return (map);
}
