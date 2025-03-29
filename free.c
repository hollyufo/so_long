/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:34:25 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/29 23:28:54 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_quit(t_long *data)
{
	// mlx_hunter(data);
	// ft_putstr_fd("\n exiting... \n", 1);
	// cleanup(data);
	exit(0);
	return (0);
}

void	handle_exit(int keycode, t_long *lng)
{
	if (keycode == 65307)
	{
		exit_game(lng);
	}
}
void free_images(void *mlx, t_img *img)
{
    if (img)
    {
        if (img->img)
            mlx_destroy_image(mlx, img->img);
        free(img);
    }
}

void free_map(char **map)
{
    int i = 0;
    if (map)
    {
        while (map[i])
            free(map[i++]);
        free(map);
    }
}

void cleanup(t_long *game)
{
    if (!game)
        return;
    
    free_map(game->map);
    free_images(game->mlx, game->wall);
    free_images(game->mlx, game->player);
    free_images(game->mlx, game->collectible);
    free_images(game->mlx, game->exit);
    free_images(game->mlx, game->floor);
    
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    free(game);
}

void exit_game(t_long *game)
{
    cleanup(game);
    exit(EXIT_SUCCESS);
}