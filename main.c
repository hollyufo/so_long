/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/11 00:56:56 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

void handle_up(int keycode, t_long *lng)
{
    if (keycode == 119)
    {
        // Check boundaries first
        if (lng->player_y <= 0 || lng->player_y >= lng->map_len || 
            lng->player_x < 0 || lng->player_x >= lng->map_width)
            return;
        // Then check what's in the cell above
        if (lng->map[lng->player_y - 1][lng->player_x] == '1')
            return;
        // Rest of your logic...
        if (lng->map[lng->player_y - 1][lng->player_x] == 'E' &&
            lng->collectible_count == 0)
        {
            printf("done \n");
        }
        else if (lng->map[lng->player_y - 1][lng->player_x] == 'E' &&
            lng->collectible_count != 0)
        {
            printf("need more collectibles\n");
            return;
        }
        if (lng->map[lng->player_y - 1][lng->player_x] == 'C')
            lng->collectible_count--;
        // Update map
        lng->map[lng->player_y - 1][lng->player_x] = 'P';
        lng->map[lng->player_y][lng->player_x] = '0';
        // Update player position
        lng->player_y--;
        render_map(lng);
    }
}
void handle_left(int keycode, t_long *lng)
{
    if (keycode == 97) // 'a' key
    {
        // Check boundaries first
        if (lng->player_y < 0 || lng->player_y >= lng->map_len || 
            lng->player_x <= 0 || lng->player_x >= lng->map_width)
            return;
            
        // Check what's in the cell to the left
        if (lng->map[lng->player_y][lng->player_x - 1] == '1')
            return;
            
        // Handle exit
        if (lng->map[lng->player_y][lng->player_x - 1] == 'E' &&
            lng->collectible_count == 0)
        {
            printf("done \n");
        }
        else if (lng->map[lng->player_y][lng->player_x - 1] == 'E' &&
            lng->collectible_count != 0)
        {
            printf("need more collectibles\n");
            return;
        }
        
        // Handle collectible
        if (lng->map[lng->player_y][lng->player_x - 1] == 'C')
            lng->collectible_count--;
            
        // Update map
        lng->map[lng->player_y][lng->player_x - 1] = 'P';
        lng->map[lng->player_y][lng->player_x] = '0';
        
        // Update player position
        lng->player_x--;
        render_map(lng);
    }
}

void handle_right(int keycode, t_long *lng)
{
    if (keycode == 100) // 'd' key
    {
        // Check boundaries first
        if (lng->player_y < 0 || lng->player_y >= lng->map_len || 
            lng->player_x < 0 || lng->player_x >= lng->map_width - 1)
            return;
            
        // Check what's in the cell to the right
        if (lng->map[lng->player_y][lng->player_x + 1] == '1')
            return;
            
        // Handle exit
        if (lng->map[lng->player_y][lng->player_x + 1] == 'E' &&
            lng->collectible_count == 0)
        {
            printf("done \n");
        }
        else if (lng->map[lng->player_y][lng->player_x + 1] == 'E' &&
            lng->collectible_count != 0)
        {
            printf("need more collectibles\n");
            return;
        }
        
        // Handle collectible
        if (lng->map[lng->player_y][lng->player_x + 1] == 'C')
            lng->collectible_count--;
            
        // Update map
        lng->map[lng->player_y][lng->player_x + 1] = 'P';
        lng->map[lng->player_y][lng->player_x] = '0';
        
        // Update player position
        lng->player_x++;
        render_map(lng);
    }
}

void    handle_exit(int keycode, t_long *lng)
{
    if (keycode == 65307)
    {
        // free
        exit(0);
    }
}

void handle_down(int keycode, t_long *lng)
{
    if (keycode == 115) // 's' key
    {
        // Check boundaries first
        if (lng->player_y < 0 || lng->player_y >= lng->map_len - 1 || 
            lng->player_x < 0 || lng->player_x >= lng->map_width)
            return;
            
        // Check what's in the cell below
        if (lng->map[lng->player_y + 1][lng->player_x] == '1')
            return;
            
        // Handle exit
        if (lng->map[lng->player_y + 1][lng->player_x] == 'E' &&
            lng->collectible_count == 0)
        {
            printf("done \n");
        }
        else if (lng->map[lng->player_y + 1][lng->player_x] == 'E' &&
            lng->collectible_count != 0)
        {
            printf("need more collectibles\n");
            return;
        }
        
        // Handle collectible
        if (lng->map[lng->player_y + 1][lng->player_x] == 'C')
            lng->collectible_count--;
            
        // Update map
        lng->map[lng->player_y + 1][lng->player_x] = 'P';
        lng->map[lng->player_y][lng->player_x] = '0';
        
        // Update player position
        lng->player_y++;
        render_map(lng);
    }
}

int    handle_keyboard(int keycode, t_long *lng)
{
    static int i = 0;
    
    handle_left(keycode, lng);
    handle_right(keycode, lng);
    handle_up(keycode, lng);
    handle_down(keycode, lng);
    handle_exit(keycode,lng);
    if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		i++;
	printf("Moves:");
    printf(" %d", i);
    return 0;
}

int	mlx_quit(t_long *data)
{
	// mlx_hunter(data);
	// ft_putstr_fd("\n exiting... \n", 1);
	// cleanup(data);
    exit(0);
	return (0);
}


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
    printf("map len : %d\n", lng->map_len);
    mlx_hook(lng->win, DestroyNotify, 0, mlx_quit, &lng);
    mlx_key_hook(lng->win, handle_keyboard, lng);
    mlx_loop(lng->mlx);

    map_panic_exit(lng, NULL); // Free memory properly before exiting
    return (0);
}
