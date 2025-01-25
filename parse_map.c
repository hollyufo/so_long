/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:23:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/25 13:10:29 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void get_map(t_long *lng, int fd) {
    int i = 0;

    map_dimensions(lng, fd);

    // Allocate memory for the map
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
    lng->map[i] = NULL; // Null-terminate the map array
}

void map_dimensions(t_long *lng, int fd) {
    char *line;
    int map_len = 0;

    // Reset file descriptor position
    lseek(fd, 0, SEEK_SET);

    while ((line = get_next_line(fd)) != NULL) {
        if (map_len == 0) {
            lng->map_width = ft_strlen(line) - 1; // Exclude newline
        }
        free(line);
        map_len++;
    }
    lng->map_len = map_len;

    // Reset file descriptor position
    lseek(fd, 0, SEEK_SET);
}