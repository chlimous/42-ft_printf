/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/17 17:04:09 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/25 20:09:38 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

void	ft_bzero(void *mem, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(mem + i) = 0;
		++i;
	}
}

int	ft_ascii_to_nb(char ascii)
{
	return (ascii - 48);
}

int	ft_isnan(long double x)
{
	return (x != x);
}
