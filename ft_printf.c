/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:09:49 by imchaibi          #+#    #+#             */
/*   Updated: 2025/03/06 22:47:44 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_handle_format(const char *form, va_list args, int fd, int *c)
{
	if (*form == 's')
		ft_putstr_fd(va_arg(args, char *), fd, c);
	else if (*form == 'd')
		ft_putnbr_fd(va_arg(args, int), fd, c);
	else if (*form == 'i')
		ft_putnbr_fd(va_arg(args, int), fd, c);
	else if (*form == 'c')
		ft_putchar_fd(va_arg(args, int), fd, c);
	else if (*form == 'p')
		ft_putptr_fd(va_arg(args, void *), fd, c);
	else if (*form == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), fd, c);
	else if (*form == 'x' || *form == 'X')
		ft_puthex(va_arg(args, unsigned int), fd, *form, c);
	else
		ft_putchar_fd(*form, fd, c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (!format)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_handle_format(format, args, 1, &count);
		}
		else
		{
			ft_putchar_fd(*format, 1, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dub;

	if (src == NULL)
	{
		dub = (char *)ft_calloc(1, sizeof(char));
		if (dub == NULL)
			return (NULL);
		return (dub);
	}
	len = ft_strlen(src);
	dub = (char *)ft_calloc(len + 1, sizeof(char));
	if (dub == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(dub, src, len + 1);
	return (dub);
}