/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:02:19 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/18 01:51:52 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "utils.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	formatid_char(int c);
size_t	formatid_string(char *str);
size_t	formatid_ptr(void *ptr, size_t size);
size_t	formatid_intbase(int nb, char *base, size_t size);
size_t	formatid_uintbase(unsigned int nb, char *base, size_t size);
size_t	formatid_percent(void);
size_t	formatid_unknown(char identifier);

#endif
