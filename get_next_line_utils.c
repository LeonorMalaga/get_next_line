/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:41:20 by leonmart          #+#    #+#             */
/*   Updated: 2025/03/12 13:41:46 by leonmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	ft_strlcpy(char *dest, const char *src, unsigned int destsize)
{
	int	index;
	int	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (destsize != 0)
	{
		while (src[index] != 0 && index < (destsize - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (src_len);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;

	index = 0;
	ptr = malloc(count * size);
	if (!ptr)
	return (NULL);		
	while (index < (count * size))
	{	
		ptr[index] = 0;
		index++;
	}
	return ((void *)ptr);
}
