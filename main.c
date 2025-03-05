/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/05 15:58:55 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av) 
{
    t_long *lng;

    lng = malloc(sizeof(t_long));
    if (!lng)
        return (printf("Error\nMemory allocation failed\n"), 1);



    
    
    // if (initialise_validate_map(ac, av[1], lng))
    //     return (free(lng), 1);
    
    // printf("Map is valid!\nWidth: %d | Height: %d\n", lng->map_width, lng->map_len);
    
    // lng->mlx = mlx_init();
    // if (!lng->mlx)
    //     return (printf("Error\nFailed to initialize MLX\n"), free(lng), 1);
    
    // lng->win = mlx_new_window(lng->mlx, lng->map_width * 64, lng->map_len * 64, "So Long");
    // if (!lng->win)
    //     return (printf("Error\nFailed to create window\n"), free(lng), 1);
    
    // mlx_loop(lng->mlx);
    
    return (0);
}
