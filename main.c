/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/24 22:43:13 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_long *lng;
	int i = 0;
	int		fd;
	i = 0;
	// lng = malloc(sizeof(t_long));
	// lng->mlx = mlx_init();
	// lng->win = mlx_new_window(lng->mlx, 1920, 1080, "Hello world!");
	// mlx_loop(lng->mlx);
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	
	get_map(lng, fd);
	//map_dimensions(lng, fd);
	ft_printf("width is %i\n", lng->map_width);
	ft_printf("len is %i\n", lng->map_len);
	while (i <= lng->map_len)
	{
		ft_printf("%s", lng->map[i]);
		i++;
	}
	while (lng->map[i])
	{
		free(lng->map[i]);
		i++;
	}
	close(fd);
	return (0);
}
