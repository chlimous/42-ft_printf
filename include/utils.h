/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/17 17:06:33 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/25 20:10:27 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

size_t		ft_strlen(const char *str);
int			ft_isspace(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *mem, size_t n);
int			ft_ascii_to_nb(char ascii);
int			ft_isnan(long double x);

#endif
