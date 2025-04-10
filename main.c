/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/10 21:47:21 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_game(t_long **lng, char *map_file)
{
	*lng = malloc(sizeof(t_long));
	if (!*lng)
		return (ft_printf("Error\nMemory allocation failed\n"), 1);
	if (initialise_validate_map(2, map_file, *lng))
		return (free(*lng), 1);
	if (!is_valid_path(*lng))
		return (ft_printf("Error\nInvalid path\n"),
			map_panic_exit(*lng, "Error\nInvalid path"), 1);
	return (0);
}

static int	setup_window(t_long *lng)
{
	lng->mlx = mlx_init();
	if (!lng->mlx)
		return (map_panic_exit(lng, "Error\nFailed to initialize MLX"), 1);
	lng->win = mlx_new_window(lng->mlx, lng->map_width * 64,
			lng->map_len * 64, "So Long");
	if (!lng->win)
		return (map_panic_exit(lng, "Error\nFailed to create a window"), 1);
	return (0);
}

static void	start_game(t_long *lng)
{
	if (load_textures(lng))
	{
		exit_game(lng);
		return ;
	}
	render_map(lng);
	mlx_hook(lng->win, DestroyNotify, 0, exit_wrapper, lng);
	mlx_key_hook(lng->win, handle_keyboard, lng);
	mlx_loop(lng->mlx);
}

int	main(int ac, char **av)
{
	t_long	*lng;

	if (ac != 2)
		return (ft_printf("Error\nUsage: ./so_long <map_file>\n"), 1);
	if (init_game(&lng, av[1]))
		return (1);
	if (setup_window(lng))
		return (1);
	start_game(lng);
	map_panic_exit(lng, NULL);
	return (0);
}
