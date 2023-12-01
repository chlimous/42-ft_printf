/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_unknown.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/22 04:59:27 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/11/25 00:54:40 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	formatid_unknown(char identifier)
{
	ft_putchar_fd('%', 1);
	ft_putchar_fd(identifier, 1);
	return (2);
}
