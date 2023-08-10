/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:00:50 by apolo-to          #+#    #+#             */
/*   Updated: 2023/04/05 14:15:18 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * This ft count the chars of an str except the final null.
 * This a modified ft from libft that considers a null str.
 * @param str The str to count.
 * @return Return an size_t value.
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i ++;
	return (i);
}

/**
 * This ft search a char in an str an return a ptr to this char.
 * In this special case we add +1 to the ptr to jump the '\n' from a line.
 * This a modified ft from libft that considers a null str.
 * @param *line The string
 * @param c The caracter to search
 * @return A ptr to the char position + 1. To jump the '\n'.
*/
char	*ft_strchr_gnl(const char *line, int c)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (line[i] == (char)c)
			return ((char *)&line[i + 1]);
		i++;
	}
	if (line[i] == (char)c)
		return ((char *)&line[i]);
	return (NULL);
}

/**
 * This ft join two str.
 * This ft is a modified version of ft_strjoin of libft.
 * The ft considers a null static_line creating a str[1] with a '\0'.
 * If the buffer is null returns null.
 * @param *static_line The previous line.
 * @param *buffer The buffer content.
 * @return A pointer to final_line.
*/
char	*ft_strjoin(char *static_line, char *buffer)
{
	char	*final_line;
	size_t	i;
	size_t	j;

	if (!static_line)
	{
		static_line = (char *)malloc(sizeof(char) * 1);
		static_line[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	final_line = malloc(sizeof(char) * (ft_strlen(static_line)
				+ ft_strlen(buffer) + 1));
	if (!final_line)
		return (NULL);
	i = -1;
	j = -1;
	while (static_line[++i])
		final_line[i] = static_line[i];
	while (buffer[++j])
		final_line[i++] = buffer[j];
	final_line[i] = '\0';
	free(static_line);
	return (final_line);
}

/**
 * This ft copy a str from src to dest.
 * @param *dest The ptr to destiny.
 * @param *src The ptr to the source.
 * @param *size Number of chars to copy.
 * @return A size_t with the num of char copied.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (ft_strlen((char *)src));
}
