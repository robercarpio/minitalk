/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preptvdhx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:40:20 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/22 16:40:47 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_preptvdhx(va_list args)
{
	unsigned long long	ptr;
	int					i;

	i = 0;
	ptr = va_arg(args, unsigned long long);
	if (!ptr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_puthx(ptr, 0);
	return (i);
}
