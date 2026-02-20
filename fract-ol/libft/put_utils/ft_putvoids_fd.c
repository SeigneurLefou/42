/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoids_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:22:46 by lchamard          #+#    #+#             */
/*   Updated: 2025/11/04 16:11:41 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_putvoids_fd(size_t ptr, int fd)
{
	size_t	len;

	if (!ptr)
	{
		len = ft_putstr_fd("(nil)", fd);
		return (len);
	}
	len = ft_putstr_fd("0x", fd);
	len += ft_putnbrbase_fd(ptr, "0123456789abcdef", fd);
	return (len);
}
