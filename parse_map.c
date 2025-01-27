/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/27 16:28:35 by imchaibi         ###   ########.fr       */
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
    while (i < lng->map_len)
    {
        lng->map[i] = get_next_line(fd);
        if (!lng->map[i]) {
            perror("Failed to read line");
            break;
        }
        i++;
    }
    lng->map[i] = NULL;    
}

void map_dimensions(t_long *lng, int fd) {
    char *line;
    int map_len = 0;
    lng->map_width = 0;
    while ((line = get_next_line(fd)) != NULL) {
        if (map_len == 0) {
            lng->map_width = ft_strlen(line) - 1;
        }
        free(line);
        map_len++;
    }
    if (map_len == 0) {
        lng->map_width = 0;
        lng->map_len = 0;
        return;
    }
    lng->map_len = map_len;
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
					return (0);
				j++;
			}
		}
        else
        {
            if (lng->map[i] == NULL)
                return (0);
            int len = ft_strlen(lng->map[i]) - 1;
            if (len != lng->map_width)
                return (0);
            if (lng->map[i][0] != '1' || lng->map[i][len] != '1')
                return (0);
        }
		i++;
	}
	return(1);
}

int validate_map_elements(t_long *lng)
{
    int i, j;
    int count_p = 0, count_e = 0, count_c = 0;

    i = 0;
    while (i < lng->map_len)
    {
        j = 0;
        while (lng->map[i][j])
        {
            if (lng->map[i][j] == 'P')
                count_p++;
            else if (lng->map[i][j] == 'E')
                count_e++;
            else if (lng->map[i][j] == 'C')
                count_c++;
            j++;
        }
        i++;
    }
    
    if (count_p == 1 && count_e == 1 && count_c >= 1) {
        return 1;
    }
    return 0;
}

void initialise_validate_map(int ac, char *str, t_long *lng)
{
    int fd;
    int valid;
    
    if (ac != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", str[0]);
        return (1);
    }
    fd = open(str, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        free(lng);
        return (1);
    }
    map_dimensions(lng, fd);
    close(fd);
    fd = open(str, O_RDONLY);
    get_map(lng, fd);
    // Print map dimensions
    printf("Width is %i\n", lng->map_width);
    printf("Length is %i\n", lng->map_len);
    valid = validate_map_boundaries(lng);
    printf("valid is : %d\n", valid);
    if (valid && validate_map_elements(lng))
    {
        printf("map vaid a7777\n");
    }
    else
    {
        ft_printf("map is not valid a zabi\n");
    }
    close(fd);
}