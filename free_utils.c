/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:11:40 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/03 15:08:17 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_panic_exit(t_long *lng, const char *error_msg)
{
	if (lng)
	{
		free_map(lng->map);
		free(lng);
	}
	if (error_msg)
		ft_printf("Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}

int	exit_wrapper(t_long *lng)
{
	exit_game(lng);
	return (0);
}
