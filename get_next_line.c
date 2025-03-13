/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:39:59 by leonmart          #+#    #+#             */
/*   Updated: 2025/03/13 18:55:05 by leonmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static char	*get_final_part_line(char *total_line)
{
	int		i_buffer;
	int		index_final_line;
	char	*final_line;

	i_buffer = 0;
	index_final_line = 0;
	while (total_line[i_buffer] != '\0' && total_line[i_buffer] != '\n')
		i_buffer++;
	if (!total_line[i_buffer])
	{
		free(total_line);
		return (NULL);
	}
	final_line = ft_calloc(ft_strlen(total_line) - i_buffer + 1, sizeof(char));
	if (!final_line)
		return (NULL);
	while (total_line[i_buffer] != '\0')
	{
		final_line[index_final_line] = total_line[i_buffer + 1];
		i_buffer++;
		index_final_line++;
	}
	final_line[index_final_line] = '\0';
	free(total_line);
	return (final_line);
}
*/
static char	*get_cleaned_line(char *buffer)
{
	int		index;
	char	*new_line;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index++;
	new_line = ft_calloc(index + 1 + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, buffer, index + 1 + 1);
	return (new_line);
}

/**
 * @brief Concatenates the `buffer` and `partial_line` strings into a new string.
 * 
 * This function checks if either `buffer` or `partial_line` is NULL.
 * If both are NULL,it returns NULL.
 * Otherwise, it concatenates the two strings and frees the memory of 
 * the `buffer` before returning the new concatenated string.
 *
 * @param buffer The first string to be concatenated.
 * @param partial_line The second string to be concatenated.
 * @return char* A new string that is the result of 
 * concatenating `buffer` and `partial_line`.
 * If the concatenation fails, it returns NULL.
 */
static char	*ft_strjoin_buffer_src(char	*buffer, char	*partial_line)
{
	char	*dest;

	if (!buffer && !partial_line)
		return (NULL);
	dest = ft_strjoin(buffer, partial_line);
	free(buffer);
	return (dest);
}

/**
 * @brief Reads data from a file descriptor and accumulates it into `total_line`.
 * 
 * This function reads data in chunks from the file associated 
 * with the given file descriptor (`fd`) and appends it to the `total_line`
 * string.The function continues reading until it encounters a newline
 * character or reaches the end of the file. If an error occurs, 
 * it frees any allocated memory and returns NULL.
 *
 * @param fd The file descriptor from which to read data.
 * @param total_line The accumulated appended strings.
 * @return char* a pointer to the first position of total_line,
 * or NULL in case of an error.
 */
static char	*read_line_buffer(int fd, char *total_line)
{
	int		char_to_read;
	char	*buffer;

	if (total_line == NULL)
		total_line = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	char_to_read = 1;
	while (char_to_read > 0)
	{
		char_to_read = read(fd, buffer, BUFFER_SIZE);
		if (char_to_read == -1)
		{
			free(total_line);
			free(buffer);
			return (NULL);
		}
		buffer[char_to_read] = '\0';
		total_line = ft_strjoin_buffer_src(total_line, buffer);
		if (ft_strchr(total_line, '\n'))
			break ;
	}
	free(buffer);
	return (total_line);
}
/*
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_line_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = get_cleaned_line(buffer);
	buffer = get_final_part_line(buffer);
	return (next_line);
}

# include <stdio.h>
int	main(void)
{
	int		fd = open("text_01.txt", O_RDONLY);
	
	int index_read;
	char	*buffer;
	char	*new_line;
	char	*final_line;
        
	index_read = 0;
	buffer = 0;
	new_line = 0;
	final_line = 0;

	buffer = malloc(BUFFER_SIZE + 1);
	// test 1-read file

	index_read = read(fd, buffer, BUFFER_SIZE);
	printf("buffer sice -> %d \n", index_read);
        printf("Buffer -> %s<-end\n", buffer);
	buffer = read_line_buffer(fd, buffer);
	printf("read complete buffer -> %s<-end\n", buffer);

	//test 2 - Get line until \n
	new_line = get_cleaned_line(buffer);
	printf("paragraph -> %s<-end\n", new_line);

	// test 2- 3º CONSEGUIR FINAL LINEA TEXTO DESPUES DE SALTO LINEA
	final_line = get_final_line(buffer);
	printf("final linea -> %s \n", final_line);

	free(buffer);
	free(new_line);
	free(final_line);

	// 4º TEST FUNCION GET_NEXT_LINE COMPLETA
	char	*next_line;
	int     count_line;

	count_line = 0;
	if (fd == -1) 
    {
        printf("Error al abrir archivo");
        return (1);
    }
	while ((next_line = get_next_line(fd)))
	{
		count_line++;
		printf("[%d]-> %s\n",count_line, next_line);
		free(next_line);
	}
	if (close(fd) == -1)
	{
        printf("Error al cerrar archivo");
        return (1);
    }
	return (0);
}*/
