/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/05 15:58:02 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 5)
        return (0);
    return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int validate_map_elements(t_long *lng)
{
    int i;
    int j;
    int p;
    int e;
    int c;

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
                p++;
            else if (lng->map[i][j] == 'E')
                e++;
            else if (lng->map[i][j] == 'C')
                c++;
            else if (lng->map[i][j] != '0' && lng->map[i][j] != '1')
                return (printf("Error\nInvalid character '%c' found at row %d, column %d\n",
                               lng->map[i][j], i, j), 0);
            j++;
        }
        i++;
    }
    if (p != 1)
        return (printf("Error\nInvalid number of players (P). Found: %d\n", p), 0);
    if (e != 1)
        return (printf("Error\nInvalid number of exits (E). Found: %d\n", e), 0);
    if (c < 1)
        return (printf("Error\nNo collectibles (C) found in the map.\n"), 0);
    return (1);
}

int validate_map_boundaries(t_long *lng)
{
    int i;
    int j;

    i = 0;
    while (i < lng->map_len)
    {
        j = 0;
        if (i == 0 || i == lng->map_len - 1)
        {
            while (lng->map[i][j])
            {
                if (lng->map[i][j] != '1')
                    return (printf("Error\nMap border not closed at row %d, column %d\n", i, j), 0);
                j++;
            }
        }
        else
        {
            if (lng->map[i][0] != '1' || lng->map[i][lng->map_width - 1] != '1')
                return (printf("Error\nSide walls missing at row %d\n", i), 0);
        }
        i++;
    }
    return (1);
}

int validate_map_structure(t_long *lng)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(lng->map[0]);
    while (i < lng->map_len)
    {
        if (ft_strlen(lng->map[i]) != len)
            return (printf("Error\nMap row %d has inconsistent length (%d instead of %d)\n",
                           i, (int)ft_strlen(lng->map[i]), len), 0);
        i++;
    }
    return (1);
}

void map_dimensions(t_long *lng, int fd)
{
    char *line;
    int map_len = 0;
    lng->map_width = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (map_len == 0)
            lng->map_width = ft_strlen(line) - 1;
        free(line);
        map_len++;
    }
    if (map_len == 0)
    {
        lng->map_width = 0;
        lng->map_len = 0;
        printf("Error\nEmpty map file\n");
        return;
    }
    lng->map_len = map_len;
}

void get_map(t_long *lng, int fd)
{
    int i = 0;

    lng->map = malloc(sizeof(char *) * (lng->map_len + 1));
    if (!lng->map)
    {
        perror("Failed to allocate memory for map");
        return;
    }
    while (i < lng->map_len)
    {
        lng->map[i] = get_next_line(fd);
        if (!lng->map[i])
        {
            perror("Failed to read line");
            break;
        }
        if (lng->map[i][ft_strlen(lng->map[i]) - 1] == '\n') // Remove trailing newline
            lng->map[i][ft_strlen(lng->map[i]) - 1] = '\0';
        i++;
    }
    lng->map[i] = NULL;
}

int initialise_validate_map(int ac, char *str, t_long *lng)
{
    int fd;
    int i;

    if (ac != 2 || !check_extension(str))
        return (printf("Error\nInvalid file name. Must be a .ber file\n"), 1);
    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (printf("Error\nFailed to open file: %s\n", str), 1);
    map_dimensions(lng, fd);
    close(fd);
    fd = open(str, O_RDONLY);
    get_map(lng, fd);
    i = 0;
    while (lng->map[i])
    {
        printf("%s", lng->map[i]);
        i++;
    }
    close(fd);
    if (!validate_map_structure(lng))
        return (1);
    if (!validate_map_boundaries(lng))
        return (1);
    if (!validate_map_elements(lng))
        return (1);
    printf("Map validation successful!\n");
    return (0);
}
