/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/26 22:49:17 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av) 
{
    t_long *lng;
    int i = 0;
    int fd;
    int valid;
    int rec;

	// lng->mlx = mlx_init();
	// lng->win = mlx_new_window(lng->mlx, 1920, 1080, "Hello world!");
	// mlx_loop(lng->mlx);
	
    if (ac != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", av[0]);
        return (1);
    }

    // Allocate memory for lng
    lng = malloc(sizeof(t_long));
    if (!lng) {
        perror("Failed to allocate memory for lng");
        return (1);
    }

    fd = open(av[1], O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        free(lng);
        return (1);
    }
    map_dimensions(lng, fd);
    close(fd);
    fd = open(av[1], O_RDONLY);
    get_map(lng, fd);

    // Print map dimensions
    printf("Width is %i\n", lng->map_width);
    printf("Length is %i\n", lng->map_len);
    valid = validate_map_boundaries(lng);
    printf("valid is : %d\n", valid);
    if (valid)
    {
        printf("map vaid a7777\n");
    }
    else
    {
        ft_printf("map is not valid a zabi\n");
    }
    // Print the map
    for (i = 0; i < lng->map_len; i++) {
        printf("%s\n", lng->map[i]);
        free(lng->map[i]); // Free each map line
    }
    // Free the map array and close the file
    free(lng->map);
    close(fd);
    free(lng);
    return (0);
}