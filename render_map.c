/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:43:08 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/16 21:43:55 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_long *lng)
{
	lng->wall = malloc(sizeof(t_img));
	lng->player = malloc(sizeof(t_img));
	lng->collectible = malloc(sizeof(t_img));
	lng->exit = malloc(sizeof(t_img));
	lng->floor = malloc(sizeof(t_img));
	if (!lng->wall || !lng->player || !lng->collectible
		|| !lng->exit || !lng->floor)
		return (ft_printf("Error\nFailed to allocate memory for textures\n"), 1);
	lng->wall->img = mlx_xpm_file_to_image(lng->mlx, "./textures/wall.xpm",
			&lng->wall->width, &lng->wall->height);
	lng->player->img = mlx_xpm_file_to_image(lng->mlx, "./textures/player.xpm",
			&lng->player->width, &lng->player->height);
	lng->collectible->img = mlx_xpm_file_to_image(lng->mlx, "./textures/collectible.xpm",
			&lng->collectible->width, &lng->collectible->height);
	lng->exit->img = mlx_xpm_file_to_image(lng->mlx, "./textures/exit.xpm",
			&lng->exit->width, &lng->exit->height);
	lng->floor->img = mlx_xpm_file_to_image(lng->mlx, "./textures/background.xpm",
			&lng->floor->width, &lng->floor->height);
	if (!lng->wall->img || !lng->player->img || !lng->collectible->img
		|| !lng->exit->img || !lng->floor->img)
		return (ft_printf("Error\nFailed to load textures\n"), 1);
	return (0);
}

void	render_tile(t_long *lng, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * 64;
	pos_y = y * 64;
	mlx_put_image_to_window(lng->mlx, lng->win, lng->floor->img, pos_x, pos_y);
	if (lng->map[y][x] == '1' && lng->wall && lng->wall->img)
		mlx_put_image_to_window(lng->mlx, lng->win, lng->wall->img, pos_x, pos_y);
	else if (lng->map[y][x] == 'P')
		mlx_put_image_to_window(lng->mlx, lng->win, lng->player->img, pos_x, pos_y);
	else if (lng->map[y][x] == 'C')
		mlx_put_image_to_window(lng->mlx, lng->win, lng->collectible->img, pos_x, pos_y);
	else if (lng->map[y][x] == 'E')
		mlx_put_image_to_window(lng->mlx, lng->win, lng->exit->img, pos_x, pos_y);
}

void	render_map(t_long *lng)
{
	int	y;
	int	x;

	y = 0;
	while (y < lng->map_len)
	{
		x = 0;
		while (x < lng->map_width)
		{
			render_tile(lng, x, y);
			x++;
		}
		y++;
	}
}
