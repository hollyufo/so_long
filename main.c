/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/29 20:16:24 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av) 
{
    t_long *lng;
    int i = 0;
    
	// lng->mlx = mlx_init();
	// lng->win = mlx_new_window(lng->mlx, 1920, 1080, "Hello world!");
	// mlx_loop(lng->mlx);
	
    lng = malloc(sizeof(t_long));
    if (!lng) {
        perror("Failed to allocate memory for lng");
        return (1);
    }
    if (initialise_validate_map(ac, av[1], lng))
    {
        printf("Map is valid!\n");
        // Proceed with the rest of your program
    } else
    {
        printf("Map is invalid!\n");
    }
    // Print the map
    for (i = 0; i < lng->map_len; i++) {
        printf("%s\n", lng->map[i]);
        free(lng->map[i]);
    }
    free(lng->map);
    free(lng);
    return (0);
}