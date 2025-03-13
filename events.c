/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:33:48 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/13 00:34:14 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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