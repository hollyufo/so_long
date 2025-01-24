/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/24 19:49:49 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_map(t_long *lng, int fd)
{
    int i = 0;
    
    map_dimensions(lng, fd);
    lng->map = malloc(sizeof(char *) * lng->map_len);
	lng->map[lng->map_len] = NULL;
	while (1)
	{
		lng->map[i] = get_next_line(fd);
		if (lng->map[i] == NULL)
			break;
		i++;
	}
}
void map_dimensions(t_long *lng, int fd )
{
    int		map_len;
	int     map_wid;
	char	*line;
	
	line == NULL;
	map_len = 0;
    map_wid = 0;
    while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break;	
		}
        if(map_len == 0)
        {
            lng->map_width = ft_strlen(line);
        }
		free(line);
		map_len++;
	}
    lng->map_len = map_len;
}

// int is_map_rectangular()
// {
    
// }

// int is_map_valid(int fd)
// {
    
// }