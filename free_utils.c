/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:11:40 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/10 20:58:41 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_panic_exit(t_long *lng, const char *error_msg)
{
	if (lng)
	{
		free_map(lng->map, lng);
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

void	free_texture(t_img *texture, void *mlx)
{
	if (!texture)
		return;
	if (texture->img)
		mlx_destroy_image(mlx, texture->img);
	free(texture);
}
