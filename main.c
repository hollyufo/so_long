/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:19 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/24 18:22:05 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_long *lng;
	char	*line;
	int i = 0;
	int		fd;
	int		map_len;
	
	line == NULL;
	map_len = 0;
	// lng = malloc(sizeof(t_long));
	// lng->mlx = mlx_init();
	// lng->win = mlx_new_window(lng->mlx, 1920, 1080, "so_long!");
	// mlx_loop(lng->mlx);
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break;	
		}
		free(line);
		map_len++;
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	lng->map = malloc(sizeof(char *) * map_len);
	lng->map[map_len] = NULL;
	while (1)
	{
		lng->map[i] = get_next_line(fd);
		if (lng->map[i] == NULL)
			break;
		printf("%s\n", lng->map[i]);
		i++;
	}
	printf("\nMap len is %i", map_len);
	close(fd);

	i = 0;
	while (lng->map[i])
	{
		free(lng->map[i]);
		i++;
	}
	return (0);
}
