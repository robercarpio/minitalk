/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:52:21 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/22 21:52:24 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> //malloc free
# include <unistd.h> //write
# include <stdarg.h> //va_va_start, va_arg, va_copy
# include <stdio.h> //printf

int	ft_preptchr(va_list args);
int	ft_prepthx(va_list args, int m);
int	ft_preptnbr(va_list args);
int	ft_preptnbru(va_list args);
int	ft_preptstr(va_list args);
int	ft_preptvdhx(va_list args);
int	ft_printf(char const *format, ...);
int	ft_putchr(char c);
int	ft_puthx(unsigned long long n, int m);
int	ft_putnbr(int n);
int	ft_putnbru(unsigned int n);
int	ft_putstr(char *str);
int	ft_swparam(char const format, va_list args);

#endif
