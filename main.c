/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/30 18:05:10 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av) 
{
    t_long *lng;

    if (ac != 2)
        return (ft_printf("Error\nUsage: ./so_long <map_file>\n"), 1);

    lng = malloc(sizeof(t_long));
    if (!lng)
        return (ft_printf("Error\nMemory allocation failed\n"), 1);

    if (initialise_validate_map(ac, av[1], lng))
        return (free(lng), 1);
    
    if (!is_valid_path(lng))
        return (ft_printf("Error\nInvalid path: Player cannot reach all collectibles or exit\n"),
                map_panic_exit(lng, "Error\nInvalid path"), 1);
    lng->mlx = mlx_init();
    if (!lng->mlx)
        return (ft_printf("Error\nFailed to initialize MLX\n"),
                map_panic_exit(lng, "Error\nFailed to initialize MLX"), 1);
    lng->win = mlx_new_window(lng->mlx, lng->map_width * 64, lng->map_len * 64, "So Long");
    if (!lng->win)
        return (ft_printf("Error\nFailed to create window\n"),
                map_panic_exit(lng, "Error\nFailed to create a window"), 1);
    load_textures(lng);
    render_map(lng);
    mlx_hook(lng->win, DestroyNotify, 0, exit_wrapper, &lng);
    mlx_key_hook(lng->win, handle_keyboard, lng);
    mlx_loop(lng->mlx);

    map_panic_exit(lng, NULL);
    return (0);
}
