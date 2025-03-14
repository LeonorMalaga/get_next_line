/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:38:49 by leonmart          #+#    #+#             */
/*   Updated: 2025/03/14 13:10:22 by leonmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
/**
 * @brief ft_strlen(str) return the length of the given string
 * 
 * @param str If "str" doesn't exist (is 0 or NULL) the function return NULL.
 * @return ** unsigned int to can used in other functions
 */
int		ft_strlen(const char *str);
/**
 * @brief ft_strlcpy(dst,src,dstsize) if "dstsize" is not 0,
 * "ft_strlcpy()" copies up to (dstsize - 1)
 * characters from the string src to dst, adding a NUL-terminating.
 * 
 * @param dst It is necesarry declare it with malloc before passing 
 * it to the function.
 * @param src It is necesarry declare it with malloc before passing 
 * it to the function.
 * @param dstsize if "dstsize = 0" the fun
 * @return ** unsigned int,  always the length of src.
 */
int		ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
/**
 * @brief ft_calloc(count,size) allocate memory for count * size bytes,
 * and full that memory with 0
 * 
 * @param  "count" number of positions, "size" bytes for every position
 * @return *void a pointer to the first byte of the allocate memory
 */
void	*ft_calloc(size_t count, size_t size);
/**
 * @brief ft_strjoin(*s1,*s2) allocates memory for a new string with length
 * (length s1 + length s2),and copy the contents of s1 and s2 into it.
 *
 * @param s1 if "s1" doesn't exist (is 0 or NULL)
 *  the function cause a :!! segmenttion fault !!.
 * @param s2 if "s2" doesn't exist (is 0 or NULL)
 *  the function cause a :!! segmenttion fault !!.
 * @return char*
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief The ft_strchr(*s,c) function locates the FIRST occurrence of "c"
 * in the string "s";
 *
 * @param s a string of characters.if "s" doesn't exist (is 0 or NULL)
 *  the function cause a: !! segmenttion fault !!.
 * @param c int the ascii integer value of the char to locate.
 * @return a char* pointer to the first (char)c int *s,
 * if (char)c is not present in *s, return 0.
 */
char	*ft_strchr(const char *s, int c);
#endif
