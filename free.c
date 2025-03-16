/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:34:25 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/16 21:49:00 by imchaibi         ###   ########.fr       */
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
        // free
        exit(0);
    }
}