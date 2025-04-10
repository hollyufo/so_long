/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:22 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/10 20:56:17 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_long
{
	void	*mlx;
	void	*img;
	void	*win;
	char	**map;
	int		map_len;
	int		map_width;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		exit_found;
	t_img	*wall;
	t_img	*player;
	t_img	*collectible;
	t_img	*exit;
	t_img	*floor;
}		t_long;

typedef struct s_fill_data
{
	int	collected;
	int	exit_found;
	int	rows;
	int	cols;
}		t_fill_data;

char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, const char *src);
ssize_t		gnl_buff(char *buffer, char *remainder, int fd);
int			ft_printf(const char *format, ...);
void		ft_putchar_fd(char c, int fd, int *count);
void		ft_putstr_fd(char *s, int fd, int *count);
void		ft_putnbr_fd(int n, int fd, int *count);
void		ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count);
void		ft_putptr_fd(void *ptr, int fd, int *count);
void		ft_puthex(unsigned long num, int fd, char case_type, int *count);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			check_extension(char *filename);
int			validate_map_elements(t_long *lng);
int			validate_map_boundaries(t_long *lng);
int			validate_map_structure(t_long *lng);
int			initialise_validate_map(int ac, char *str, t_long *lng);
void		get_map(t_long *lng, int fd);
void		map_panic_exit(t_long *lng, const char *error_msg);
void		map_dimensions(t_long *lng, int fd);
char		*ft_strdup(const char *src);
int			is_valid_path(t_long *lng);
int			handle_keyboard(int keycode, t_long *lng);
int			load_textures(t_long *lng);
void		render_tile(t_long *lng, int x, int y);
void		render_map(t_long *lng);
void		handle_exit(int keycode, t_long *lng);
void		exit_game(t_long *lng);
void		free_images(void *mlx, t_img *img);
void		free_map(char **map, t_long *lng);
void		cleanup(t_long *game);
int			exit_wrapper(t_long *lng);
void		process_map_line(t_long *lng, char *line, int *map_len);
void	free_texture(t_img *texture, void *mlx);

#endif