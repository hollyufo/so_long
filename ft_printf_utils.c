/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:11:31 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/04 21:28:31 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd, int *count)
{
	(*count)++;
	write(fd, &c, 1);
}

void	ft_puthex(unsigned long num, int fd, char case_type, int *count)
{
	const char	*hex;

	if (case_type == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num >= 16)
		ft_puthex(num / 16, fd, case_type, count);
	ft_putchar_fd(hex[num % 16], fd, count);
}

void	ft_putnbr_fd(int nb, int fd, int *count)
{
	long int	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar_fd('-', fd, count);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd, count);
	}
	ft_putchar_fd((num % 10) + '0', fd, count);
}

void	ft_putnbr_unsigned_fd(unsigned int nb, int fd, int *count)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned_fd(nb / 10, fd, count);
	}
	ft_putchar_fd((nb % 10) + '0', fd, count);
}

void	ft_putptr_fd(void *ptr, int fd, int *count)
{
	unsigned long	address;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd, count);
		return ;
	}
	address = (unsigned long)ptr;
	ft_putstr_fd("0x", fd, count);
	ft_puthex(address, fd, 'x', count);
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	size_t	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		(*count) = (*count) + 6;
		return ;
	}
	i = 0;
	while (s[i])
		i++;
	(*count) = (*count) + i;
	write(fd, s, i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}