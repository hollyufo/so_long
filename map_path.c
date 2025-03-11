/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:54:57 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/10 23:10:33 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void flood_fill(char **map, int y, int x, t_fill_data *data)
{
    // Check boundaries and if cell is a wall or already visited
    if (y < 0 || x < 0 || y >= data->rows || x >= data->cols || 
        map[y][x] == '1' || map[y][x] == 'V')
        return;
        
    // Handle collectible
    if (map[y][x] == 'C')
        data->collected++;

    // Handle exit
    if (map[y][x] == 'E')
        data->exit_found = 1;

    // Mark as visited
    map[y][x] = 'V';

    // Recursive calls in all four directions
    flood_fill(map, y + 1, x, data);  // Down
    flood_fill(map, y - 1, x, data);  // Up
    flood_fill(map, y, x + 1, data);  // Right
    flood_fill(map, y, x - 1, data);  // Left
}

static void find_player_position(t_long *lng)
{
    int y;
    int x;

    y = 0;
    while (y < lng->map_len)
    {
        x = 0;
        while (lng->map[y][x])
        {
            if (lng->map[y][x] == 'P')
            {
                lng->player_y = y;
                lng->player_x = x;
                return;
            }
            x++;
        }
        y++;
    }
}

static void count_collectibles(t_long *lng)
{
    int y;
    int x;
    int count;

    count = 0;
    y = 0;
    while (y < lng->map_len)
    {
        x = 0;
        while (lng->map[y][x])
        {
            if (lng->map[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    lng->collectible_count = count;
}

static char **duplicate_map(t_long *lng)
{
    char **map_copy;
    int i;

    map_copy = malloc(sizeof(char *) * lng->map_len);
    if (!map_copy)
        return (NULL);

    i = 0;
    while (i < lng->map_len)
    {
        map_copy[i] = ft_strdup(lng->map[i]);
        if (!map_copy[i])
        {
            // Free already allocated rows if allocation fails
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    return (map_copy);
}

static void free_map_copy(char **map_copy, int map_len)
{
    int i;

    if (!map_copy)
        return;
    
    i = 0;
    while (i < map_len)
    {
        if (map_copy[i])
            free(map_copy[i]);
        i++;
    }
    free(map_copy);
}

int is_valid_path(t_long *lng)
{
    t_fill_data data;
    char **map_copy;
    int result;

    // Find player position if not set
    if (lng->player_x == 0 && lng->player_y == 0)
        find_player_position(lng);

    // Count collectibles if not set
    if (lng->collectible_count == 0)
        count_collectibles(lng);

    // Initialize flood fill data
    data.collected = 0;
    data.exit_found = 0;
    data.rows = lng->map_len;
    data.cols = lng->map_width;

    // Create a copy of the map
    map_copy = duplicate_map(lng);
    if (!map_copy)
        return (printf("Error\nMemory allocation failed for map copy\n"), 0);

    // Perform flood fill starting from player position
    flood_fill(map_copy, lng->player_y, lng->player_x, &data);

    // Check if all collectibles are reachable and exit is found
    result = (data.collected == lng->collectible_count && data.exit_found);

    // Free the map copy
    free_map_copy(map_copy, lng->map_len);

    return (result);
}