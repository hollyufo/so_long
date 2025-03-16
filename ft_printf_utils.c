/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:11:31 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/16 21:16:59 by imchaibi         ###   ########.fr       */
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
