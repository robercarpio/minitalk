/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swparam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:40:37 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:39 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_swparam(char const format, va_list args)
{
	char	m;

	if (format == 'c')
		return (ft_preptchr(args));
	else if (format == 's')
		return (ft_preptstr(args));
	else if (format == 'd' || format == 'i')
		return (ft_preptnbr(args));
	else if (format == 'u')
		return (ft_preptnbru(args));
	else if (format == 'x' || format == 'X')
	{
		if (format == 'x')
			m = 0;
		else
			m = 1;
		return (ft_prepthx(args, m));
	}
	else if (format == 'p')
		return (ft_preptvdhx(args));
	else if (format == '%')
		return (ft_putchr('%'));
	return (0);
}
