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

static int			atoi_base(const char *str, int32_t *res)
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
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb = nb * 10 + (str[i++] - '0');
	}
	*res = (int32_t)(nb * sign);
	return (1);
}

static int		**create_grid(t_vec *vec, size_t hei, size_t wid, size_t size)
{
	int32_t 	**res;
	int32_t 	*tmp;
	size_t 		r;
	size_t 		c;

	if (!(res = (int **)malloc(sizeof(int *) * hei)))
		display_error("allocation faliure");
	tmp = vec->data;
	c = 0;
	r = 0;
	while (c * r < size)
	{
		c = -1;
		if (!(res[r] = (int *)malloc(sizeof(int) * wid)))
			display_error("allocation faliure");
		while (++c < wid)
			res[r][c] = tmp[c  + (r * wid)];
		r += 1;
	}
	return (res);
}

static char 	**open_file(char *path)
{
	char 		**split;
	t_vec		*file;
	int 		fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		display_error("error while open file");
	if (!(file = ft_vec_read(fd)))
		display_error("allocation faliure");
	if (!(split = ft_strsplit(file->data, '\n')))
		display_error("allocation faliure");
	ft_vec_del(&file);
	close(fd);
	return (split);
}

static void 	parse_line(t_vec **vec, char *line, int *map_width)
{
	size_t 		i;
	int32_t		val;
	char 		**ln;

	i = -1;
	if (!(ln = ft_strsplit(line, ' ')))
		display_error("allocation faliure");
	while (ln[++i])
	{
		if (!(atoi_base(ln[i], &val)))
			;
		ft_vec_add(vec, &val);
	}
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
	if (!(vec = ft_vec_init(1, sizeof(int32_t))))
		display_error("allocation faliure");
	while (file[++i])
	{
		parse_line(&vec, file[i], &map->width);
		map->height += 1;
	}
	map->size = vec->total;
	map->grid = create_grid(vec, map->height, map->width, map->size);
	ft_strsplit_free(file);
	ft_vec_del(&vec);
	return (map);
}
