/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:33:48 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/16 21:56:34 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_up(int keycode, t_long *lng)
{
	if (keycode == 119)
	{
		if (lng->player_y <= 0 || lng->player_y >= lng->map_len
			|| lng->player_x < 0 || lng->player_x >= lng->map_width)
			return ;
		if (lng->map[lng->player_y - 1][lng->player_x] == '1')
			return ;
		if (lng->map[lng->player_y - 1][lng->player_x] == 'E' &&
			lng->collectible_count == 0)
		{
			exit(0);
		}
		else if (lng->map[lng->player_y - 1][lng->player_x] == 'E' &&
			lng->collectible_count != 0)
		{
			ft_printf("\nneed more collectibles\n");
			return ;
		}
		if (lng->map[lng->player_y - 1][lng->player_x] == 'C')
			lng->collectible_count--;
		lng->map[lng->player_y - 1][lng->player_x] = 'P';
		lng->map[lng->player_y][lng->player_x] = '0';
		lng->player_y--;
		render_map(lng);
	}
}

void	handle_left(int keycode, t_long *lng)
{
	if (keycode == 97)
	{
		if (lng->player_y < 0 || lng->player_y >= lng->map_len
			|| lng->player_x <= 0 || lng->player_x >= lng->map_width)
			return ;
		if (lng->map[lng->player_y][lng->player_x - 1] == '1')
			return ;
		if (lng->map[lng->player_y][lng->player_x - 1] == 'E' &&
			lng->collectible_count == 0)
		{
			exit(0);
		}
		else if (lng->map[lng->player_y][lng->player_x - 1] == 'E' &&
			lng->collectible_count != 0)
		{
			ft_printf("\nneed more collectibles\n");
			return ;
		}
		if (lng->map[lng->player_y][lng->player_x - 1] == 'C')
			lng->collectible_count--;
		lng->map[lng->player_y][lng->player_x - 1] = 'P';
		lng->map[lng->player_y][lng->player_x] = '0';
		lng->player_x--;
		render_map(lng);
	}
}

void	handle_right(int keycode, t_long *lng)
{
	if (keycode == 100)
	{
		if (lng->player_y < 0 || lng->player_y >= lng->map_len
			|| lng->player_x < 0 || lng->player_x >= lng->map_width - 1)
			return ;
		if (lng->map[lng->player_y][lng->player_x + 1] == '1')
			return ;
		if (lng->map[lng->player_y][lng->player_x + 1] == 'E' &&
			lng->collectible_count == 0)
		{
			exit(0);
		}
		else if (lng->map[lng->player_y][lng->player_x + 1] == 'E' &&
			lng->collectible_count != 0)
		{
			ft_printf("\nneed more collectibles\n");
			return ;
		}
		if (lng->map[lng->player_y][lng->player_x + 1] == 'C')
			lng->collectible_count--;
		lng->map[lng->player_y][lng->player_x + 1] = 'P';
		lng->map[lng->player_y][lng->player_x] = '0';
		lng->player_x++;
		render_map(lng);
	}
}

void	handle_down(int keycode, t_long *lng)
{
	if (keycode == 115)
	{
		if (lng->player_y < 0 || lng->player_y >= lng->map_len - 1
			|| lng->player_x < 0 || lng->player_x >= lng->map_width)
			return ;
		if (lng->map[lng->player_y + 1][lng->player_x] == '1')
			return ;
		if (lng->map[lng->player_y + 1][lng->player_x] == 'E' &&
			lng->collectible_count == 0)
		{
			exit(0);
		}
		else if (lng->map[lng->player_y + 1][lng->player_x] == 'E' &&
			lng->collectible_count != 0)
		{
			ft_printf("\nneed more collectibles\n");
			return ;
		}
		if (lng->map[lng->player_y + 1][lng->player_x] == 'C')
			lng->collectible_count--;
		lng->map[lng->player_y + 1][lng->player_x] = 'P';
		lng->map[lng->player_y][lng->player_x] = '0';
		lng->player_y++;
		render_map(lng);
	}
}

int	handle_keyboard(int keycode, t_long *lng)
{
	static int	i;

	handle_left(keycode, lng);
	handle_right(keycode, lng);
	handle_up(keycode, lng);
	handle_down(keycode, lng);
	handle_exit(keycode, lng);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		i++;
	ft_printf("\rMoves:");
	ft_printf(" %d", i);
	return (0);
}
