/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:22 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/25 22:25:12 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

//#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

typedef struct s_long
{
    void    *mlx;
    void    *img;
    void    *win;
	char    **map;
    int     map_len;
    int     map_width;
}               t_long;

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
void        get_map(t_long *lng, int fd);
void        map_dimensions(t_long *lng, int fd);
int         validate_map_boundaries(t_long *lng);
#endif