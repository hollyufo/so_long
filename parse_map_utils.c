/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:10:40 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/31 22:13:55 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_map(t_long *lng, int fd)
{
    int i = 0;
    char *line;

    lng->map = malloc(sizeof(char *) * (lng->map_len + 1));
    if (!lng->map)
        map_panic_exit(lng, "Memory allocation failed for map");

    while (i < lng->map_len)
    {
        line = get_next_line(fd);
        if (!line)
        {
            map_panic_exit(lng, "Failed to read map line");
        }

        lng->map[i] = ft_strdup(line);
        free(line);
        if (!lng->map[i])
        {
            map_panic_exit(lng, "Memory allocation failed for map row");
        }
        i++;
    }
    lng->map[i] = NULL;
}

int initialise_validate_map(int ac, char *str, t_long *lng)
{
    int fd;
    int i;

    if (ac != 2 || !check_extension(str))
        return (ft_printf("Error\nInvalid file name. Must be a .ber file\n"), 1);
    
    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (ft_printf("Error\nFailed to open file: %s\n", str), 1);
    map_dimensions(lng, fd);
    close(fd);
    fd = open(str, O_RDONLY);
    get_map(lng, fd);
    close(fd);

    if (!lng->map)
        return (ft_printf("Error\nFailed to load map\n"), map_panic_exit(lng, "Invalid map configuration"), 1);
    if (!validate_map_structure(lng) || 
        !validate_map_boundaries(lng) || 
        !validate_map_elements(lng))
    {
        map_panic_exit(lng, "Invalid map configuration");
        return (1);
    }
    return (0);
}

void free_map_exit(char **map, int map_len)
{
    int i = 0;

    if (map)
    {
        while (i < map_len)
        {
            if (map[i])
            {
                free(map[i]);
                map[i] = NULL;
            }
            i++;
        }
        free(map);
        map = NULL;
    }
}
int exit_wrapper(t_long *lng)
{
    exit_game(lng);
    return (0);
}
