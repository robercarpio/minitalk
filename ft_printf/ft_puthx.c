/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:48:54 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/21 11:48:57 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthx(unsigned long long n, int m)
{
	int		i;
	char	*values;

	i = 0;
	if (m == 1 || m == 0)
	{
		if (m == 1)
			values = "0123456789ABCDEF";
		else
			values = "0123456789abcdef";
		if (n / 16)
		{
			i += ft_puthx(n / 16, m);
		}
		i += ft_putchr(values[n % 16]);
	}
	return (i);
}

/*
int	main(void)
{
	printf("%d",ft_puthx(1132131131313123233,1));
	return(0);
}
*/