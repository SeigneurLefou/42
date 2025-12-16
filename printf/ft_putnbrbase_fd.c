/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:22:46 by lchamard          #+#    #+#             */
/*   Updated: 2025/11/04 16:15:19 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase_fd(size_t nb, char *base, int fd)
{
	size_t	len;

	len = 0;
	if (nb >= ft_strlen(base))
		len += ft_putnbrbase_fd(nb / ft_strlen(base), base, fd);
	len += ft_putchar_fd(base[nb % ft_strlen(base)], fd);
	return (len);
}
