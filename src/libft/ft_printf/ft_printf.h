/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:31:44 by patatoss          #+#    #+#             */
/*   Updated: 2023/05/21 18:10:46 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printf_putchar(int c);
int	ft_printf_putstr(char *str);
int	ft_putptr(unsigned long nbr);
int	ft_puthex(unsigned long nbr, char c);
int	ft_putnbr(int nbr);
int	ft_putunsignednbr(unsigned int nbr);

#endif