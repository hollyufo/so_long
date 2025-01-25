/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/26 00:29:35 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void get_map(t_long *lng, int fd) {

    int i = 0;
    
    lng->map = malloc(sizeof(char *) * (lng->map_len + 1));
    if (!lng->map) {
        perror("Failed to allocate memory for map");
        return;
    }

    // Read each line into the map
    for (i = 0; i < lng->map_len; i++) {
        lng->map[i] = get_next_line(fd);
        if (!lng->map[i]) {
            perror("Failed to read line");
            break;
        }
    }
    lng->map[i] = NULL;
}

void map_dimensions(t_long *lng, int fd) {
    char *line;
    int map_len = 0;
    
    lseek(fd, 0, SEEK_SET);

    while ((line = get_next_line(fd)) != NULL) {
        if (map_len == 0) {
            lng->map_width = ft_strlen(line) - 1;
        }
        free(line);
        map_len++;
    }
    lng->map_len = map_len;

    lseek(fd, 0, SEEK_SET);
}
int	validate_map_boundaries(t_long *lng)
{
    int i;
	int j;

	i = 0;
    int len;

	while (i < lng->map_len)
	{
		if (i == 0 || i == lng->map_len - 1)
		{
		    j = 0;
			while (lng->map[i][j])
			{
				if (lng->map[i][j] != '1')
				{
					return (0);
				}
				j++;
			}
		}
        else
        {
            if (lng->map[i] == NULL) // Check if the row is NULL
            {
                printf("Error: Map row %d is NULL\n", i);
                return (0);
            }

            int len = ft_strlen(lng->map[i]) - 1;
            if (len != lng->map_width) // Ensure row length matches the expected width
            {
                printf("Error: Map row %d has inconsistent width (expected %d, got %d)\n", i, lng->map_width, len);
                return (0);
            }

            // Check the first and last characters of the row
            if (lng->map[i][0] != '1' || lng->map[i][len] != '1')
            {
                printf("Error: Map row %d boundaries are invalid\n", i);
                return (0);
            }
        }
		i++;
	}
	return(1);
}