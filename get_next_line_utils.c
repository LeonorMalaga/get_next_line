/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:41:20 by leonmart          #+#    #+#             */
/*   Updated: 2025/03/13 12:52:21 by leonmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char	*str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	int	index;
	int	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[index] != 0 && index < (dstsize - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (src_len);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;

	index = 0;
	ptr = (char *) malloc(count * size);
	if (!ptr)
		return (NULL);
	while (index < (count * size))
	{
		ptr[index] = 0;
		index++;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_index;
	int		s2_index;
	int		str_joined_index;

	s1_index = 0;
	s2_index = 0;
	str_joined_index = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str || (!s1 && !s2))
		return (NULL);
	while (s1[s1_index] != '\0')
	{
		str[str_joined_index] = s1[s1_index];
		str_joined_index++;
		s1_index++;
	}
	while (s2[s2_index] != '\0')
	{
		str[str_joined_index] = s2[s2_index];
		str_joined_index++;
		s2_index++;
	}
	str[str_joined_index] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)(s + index));
	return (0);
}
