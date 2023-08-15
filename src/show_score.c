/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:52:13 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/15 13:26:52 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_num_len(long num)
{
	size_t	i;

	i = 1;
	if (num < 0)
	{
		num = num * -1;
		i ++;
	}
	while (num > 9)
	{
		num = num / 10;
		i ++;
	}
	return (i);
}

static void	ft_num_to_char(long num, char *res, size_t *i)
{
	if (num > 9)
	{
		ft_num_to_char(num / 10, res, i);
		ft_num_to_char(num % 10, res, i);
	}
	else
	{
		res[*i] = num + '0';
		(*i)++;
	}
}

/**
 * This ft convert an Int to an string. 
 * Return a string with the result.
 * @param int num	- The number.
 * @return char*	- Pointer to resulted string.
*/
char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	size_t	i;

	num = n;
	res = malloc(sizeof(char) * (ft_num_len(num) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		res[i] = '-';
		num = num * -1;
		i ++;
	}
	ft_num_to_char(num, res, &i);
	res[i] = '\0';
	return (res);
}
