/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:54:28 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/31 09:35:25 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr_fd(unsigned int nb, int fd)
{
	size_t	len;

	len = 0;
	if (nb > 9)
		len += ft_putnbr_fd(nb / 10, fd);
	len += ft_putchar_fd((nb % 10) + '0', fd);
	return (len);
}
