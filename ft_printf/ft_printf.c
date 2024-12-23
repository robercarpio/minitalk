/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:42:28 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/22 20:42:32 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		chrs;

	chrs = 0;
	i = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			chrs += ft_swparam(format[i], args);
		}
		else
		{
			chrs += ft_putchr(format[i]);
		}
		i++;
	}
	va_end(args);
	return (chrs);
}
/*
int main(void)
{
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    printf("%d",ft_printf("%c",'h'));
    return (0);
}
*/
