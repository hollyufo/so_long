/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:57:24 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/24 17:03:59 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp_str;
	size_t	total_size;

	if (count == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (count > SIZE_MAX / size)
	{
		return (NULL);
	}
	total_size = count * size;
	temp_str = malloc(total_size);
	if (!temp_str)
	{
		return (NULL);
	}
	ft_memset(temp_str, 0, total_size);
	return (temp_str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

static char	*allocate_and_copy(const char *src, size_t len)
{
	char	*result;

	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result)
		ft_strlcpy(result, src, len + 1);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_result;

	if (!s1 && !s2)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (!s1)
		return (allocate_and_copy(s2, ft_strlen(s2)));
	if (!s2)
		return (allocate_and_copy(s1, ft_strlen(s1)));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_result = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str_result)
		return (NULL);
	ft_strlcpy(str_result, s1, s1_len + 1);
	ft_strlcpy(str_result + s1_len, s2, s2_len + 1);
	free((char *)s1);
	return (str_result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
