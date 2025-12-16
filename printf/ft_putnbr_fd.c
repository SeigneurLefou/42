/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:54:28 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/31 09:35:29 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int nb, int fd)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return (11);
		}
		len = 1;
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
		len += ft_putnbr_fd(nb / 10, fd);
	len += ft_putchar_fd((nb % 10) + '0', fd);
	return (len);
}
