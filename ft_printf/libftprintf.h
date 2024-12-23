/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:00:11 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/21 11:00:13 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdlib.h> //malloc free
#include <unistd.h> //write
#include <stdarg.h> //va_va_start, va_arg, va_copy
#include <stdio.h> //printf

int	ft_putstr(char *str);
int ft_printf(char const *format, ...);
int ft_putchr(char c);
int ft_swparam(char const format, va_list arg);

#endif
