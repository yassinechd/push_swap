/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:28:24 by yass              #+#    #+#             */
/*   Updated: 2024/09/22 21:16:32 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_arg_count(const char	*str);
int		ft_dispatch(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbr_unsigned(unsigned int nbr);
void	ft_recur_hexa(int nbr, char format);
int		ft_putnbr_hexa2(int nbr);
int		ft_putnbr_hexa(unsigned int nbr, char format);
int		ft_aff_point(unsigned long long nbr);
int		ft_print_ptr2(unsigned long long ptr);
#endif
