/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepthx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:34:09 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/22 16:34:11 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prepthx(va_list args, int m)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_puthx(n, m));
}
