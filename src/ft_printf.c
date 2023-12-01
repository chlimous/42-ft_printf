/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/22 02:39:15 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/01 22:44:03 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_percent_terminated(const char *str)
{
	size_t	i;

	i = ft_strlen(str);
	if (!i || str[i - 1] != '%' || (i >= 2 && str[i - 1] == '%' \
				&& str[i - 2] == '%'))
		return (0);
	return (1);
}

static size_t	call_format(va_list args, char identifier)
{
	size_t	size;

	size = 0;
	if (identifier == 'c')
		return (size + formatid_char(va_arg(args, int)));
	else if (identifier == 's')
		return (size + formatid_string(va_arg(args, char *)));
	else if (identifier == 'p')
		return (size + formatid_ptr(va_arg(args, void *), 0));
	else if (identifier == 'd' || identifier == 'i')
		return (size + formatid_intbase(va_arg(args, int), "0123456789", 0));
	else if (identifier == 'u')
		return (size + formatid_uintbase(va_arg(args, unsigned int), \
					"0123456789", 0));
	else if (identifier == 'x')
		return (size + formatid_uintbase(va_arg(args, unsigned int), \
					"0123456789abcdef", 0));
	else if (identifier == 'X')
		return (size + formatid_uintbase(va_arg(args, unsigned int), \
					"0123456789ABCDEF", 0));
	else if (identifier == '%')
		return (size + formatid_percent());
	else
		return (size + formatid_unknown(identifier));
}

int	ft_printf(const char *str, ...)
{
	size_t	size;
	va_list	args;

	if (!str || is_percent_terminated(str))
		return (-1);
	size = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			size += call_format(args, *str);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			size++;
		}
		str++;
	}
	va_end(args);
	return (size);
}
