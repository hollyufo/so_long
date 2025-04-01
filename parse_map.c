/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/01 18:10:00 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int validate_map_elements(t_long *lng)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (i < lng->map_len)
	{
		j = 0;
		while (lng->map[i][j])
		{
			if (lng->map[i][j] == 'P')
			{
				p++;
				lng->player_y = i;
				lng->player_x = j;
			}
			else if (lng->map[i][j] == 'E')
				e++;
			else if (lng->map[i][j] == 'C')
				c++;
			else if (lng->map[i][j] != '0' && lng->map[i][j] != '1')
				return (ft_printf("Error\nInvalid character '%c' found at row %d, column %d\n",
							   lng->map[i][j], i, j), 0);
			j++;
		}
		i++;
	}
	lng->collectible_count = c;
	if (p != 1)
		return (ft_printf("Error\nInvalid number of players (P). Found: %d\n", p), 0);
	if (e != 1)
		return (ft_printf("Error\nInvalid number of exits (E). Found: %d\n", e), 0);
	if (c < 1)
		return (ft_printf("Error\nNo collectibles (C) found in the map.\n"), 0);
	return (1);
}

int	validate_map_boundaries(t_long *lng)
{
	int	i;
	int	j;

	i = 0;
	while (i < lng->map_len)
	{
		j = 0;
		if (i == 0 || i == lng->map_len - 1)
		{
			while (lng->map[i][j])
			{
				if (lng->map[i][j] != '1')
					return (ft_printf("Error\nMap border not closed at row %d, column %d\n", i, j), 0);
				j++;
			}
		}
		else
		{
			if (lng->map[i][0] != '1' || lng->map[i][lng->map_width - 1] != '1')
				return (ft_printf("Error\nSide walls missing at row %d\n", i), 0);
		}
		i++;
	}
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
			return (ft_printf("Error\nMap row %d has inconsistent length (%d instead of %d)\n",
						   i, (int)ft_strlen(lng->map[i]), len), 0);
		i++;
	}
	return (1);
}

void	map_dimensions(t_long *lng, int fd)
{
	char	*line;
	int		map_len = 0;

	lng->map_width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		int line_len = ft_strlen(line);
		if (line_len == 0 || (line_len == 1 && line[0] == '\n'))
		{
			free(line);
			ft_printf("Error\nEmpty line found in map\n");
			return ;
		}
		if (line[line_len - 1] == '\n')
			line_len--;
		if (line_len > lng->map_width)
			lng->map_width = line_len;
		free(line);
		map_len++;
	}
	if (map_len == 0)
	{
		lng->map_width = 0;
		lng->map_len = 0;
		ft_printf("Error\nEmpty map file\n");
		return ;
	}
	lng->map_len = map_len;
}
