/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/03 15:07:29 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_characters(t_long *lng, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lng->map_len)
	{
		j = -1;
		while (lng->map[i][++j])
		{
			if (lng->map[i][j] == 'P')
			{
				(*p)++;
				lng->player_y = i;
				lng->player_x = j;
			}
			else if (lng->map[i][j] == 'E')
				(*e)++;
			else if (lng->map[i][j] == 'C')
				(*c)++;
			else if (lng->map[i][j] != '0' && lng->map[i][j] != '1')
				return (ft_printf("Error\nInvalid char '%c' at row %d\n",
						lng->map[i][j], i), 0);
		}
	}
	return (1);
}

int	validate_map_elements(t_long *lng)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	if (!validate_map_characters(lng, &p, &e, &c))
		return (0);
	lng->collectible_count = c;
	if (p != 1)
		return (ft_printf("Error\nInvalid number of players\n"), 0);
	if (e != 1)
		return (ft_printf("Error\nInvalid number of exits\n"), 0);
	if (c < 1)
		return (ft_printf("Error\nNo collectibles in the map\n"), 0);
	return (1);
}

int	validate_map_structure(t_long *lng)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(lng->map[0]);
	while (i < lng->map_len)
	{
		if (ft_strlen(lng->map[i]) != len)
			return (ft_printf("Error\nMap row %d has inconsistent length\n",
					i, (int)ft_strlen(lng->map[i]), len), 0);
		i++;
	}
	return (1);
}

void	process_map_line(t_long *lng, char *line, int *map_len)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len == 0 || (line_len == 1 && line[0] == '\n'))
	{
		free(line);
		return ;
	}
	if (line[line_len - 1] == '\n')
		line_len--;
	if (line_len > lng->map_width)
		lng->map_width = line_len;
	free(line);
	(*map_len)++;
}

void	map_dimensions(t_long *lng, int fd)
{
	char	*line;
	int		map_len;

	map_len = 0;
	lng->map_width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_map_line(lng, line, &map_len);
		line = get_next_line(fd);
	}
	if (map_len == 0)
	{
		lng->map_width = 0;
		lng->map_len = 0;
		return ;
	}
	lng->map_len = map_len;
}
