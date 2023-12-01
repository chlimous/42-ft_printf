/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatid_intbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:53:24 by chlimous          #+#    #+#             */
/*   Updated: 2023/11/24 20:30:11 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	formatid_intbase(int nb, char *base, size_t size)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar_fd('-', 1);
		size++;
		lnb = -lnb;
	}
	if (lnb / ft_strlen(base) != 0)
		size = formatid_intbase(lnb / ft_strlen(base), base, size);
	ft_putchar_fd(base[lnb % ft_strlen(base)], 1);
	return (size + 1);
}
