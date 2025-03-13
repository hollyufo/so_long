/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/13 00:34:44 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av) 
{
    t_long *lng;
    int j;

    if (ac != 2)
        return (printf("Error\nUsage: ./so_long <map_file>\n"), 1);

    lng = malloc(sizeof(t_long));
    if (!lng)
        return (printf("Error\nMemory allocation failed\n"), 1);

    if (initialise_validate_map(ac, av[1], lng))
        return (free(lng), 1);
    
    // Validate if player has a valid path to all 'C' and 'E'
    if (!is_valid_path(lng))
        return (printf("Error\nInvalid path: Player cannot reach all collectibles or exit\n"),
                map_panic_exit(lng, "Error\nInvalid path"), 1);

    printf("Map is valid!\nWidth: %d | Height: %d\n", lng->map_width, lng->map_len);
    printf("player position x: %d, y: %d\n", lng->player_x, lng->player_y);
    lng->mlx = mlx_init();
    if (!lng->mlx)
        return (printf("Error\nFailed to initialize MLX\n"),
                map_panic_exit(lng, "Error\nFailed to initialize MLX"), 1);
    j = 0;
    while (j < lng->map_len)
    {
        printf("%s\n", lng->map[j]);
        j++;
    }
    lng->win = mlx_new_window(lng->mlx, lng->map_width * 64, lng->map_len * 64, "So Long");
    if (!lng->win)
        return (printf("Error\nFailed to create window\n"),
                map_panic_exit(lng, "Error\nFailed to create a window"), 1);
    load_textures(lng);
    render_map(lng);
    printf("map len : %d\n", lng->map_len);
    mlx_hook(lng->win, DestroyNotify, 0, mlx_quit, &lng);
    mlx_key_hook(lng->win, handle_keyboard, lng);
    mlx_loop(lng->mlx);

    map_panic_exit(lng, NULL); // Free memory properly before exiting
    return (0);
}
