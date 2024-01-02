/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/23 09:17:30 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_line(int fd)
{
	int		i;
	int		rd;
	int		cpt;
	char	*c;

	i = 0;
	cpt = 1;
	c = 0;
	while (c[0] && c[0] != '\n')
	{
		rd = read(fd, c, 1);
		if (rd < 1)
			break ;
		if (c[0] == '\n')
			cpt += 1;
		i++;
	}
	return (cpt);
}

char	**ft_read_map(char *fd)
{
	int 	file;
	int		i;
	int 	size;
	char	**map;

	file = open(fd, O_RDONLY);
	size = ft_count_line(file);
	close(file);
	file = open(fd, O_RDONLY);
	map = malloc(sizeof(char) * size);
	if (!map)
		return (NULL);
	while (map != NULL && i <= INT_MAX)
	{
		map[i] = get_next_line(i);
		i++;
	}
	close(i);
	return (map);
}

int	ft_error(void)
{
	ft_printf("Error\n");
	return (-1);
}

t_map	ft_height_color(char *map)
{
	int		z;
	t_map	parsed_map;

	z = 0;
	parsed_map.y = ft_atoi(map);
	while (map[z] && map[z] != ',')
		z++;
	if (map[z] != ',')
	{
		parsed_map.color = ft_atoi_base(&map[z + 2], "0xFFFFFF");
		z++;
	}
	z++;
	while (map[z])
	{
		parsed_map.color = ft_atoi_base(&map[z + 2], "0123456789ABCDEF");
		z++;
	}
	return (parsed_map);
}
//z+2 pour skip le 0x
//ce qu'on envoie dans height color
//10
//10,0x00ff00

t_map	**ft_lavoisier(char **map)
{
	t_map	**parsed_map;
	int		z;
	int		x;
	char	**temp;

	z = 0;
	while (map[z])
	{
		temp = ft_split(map[z], ' ');
		x = 0;
		while (temp[x])
		{
			parsed_map[z][x] = ft_height_color(temp[x]);
			x++;
		}
		z++;
	}
	return (parsed_map);
}

t_map	**ft_parsing_map(char *file_name)
{
	int		file;
	int		i;
	char	**map;
	t_map	**parsed_map;

	if (!file_name)
		map = ft_read_map(file_name);
	parsed_map = ft_lavoisier(map);
	return (parsed_map);
}

/*char	**ft_valid_map(char *map)
{
	char	*line;
	int		fd;

	if (fd < 0)
		return (NULL);
	if (*line == ' ' && *line + 1 == ' ')
		return (NULL);
}*/
