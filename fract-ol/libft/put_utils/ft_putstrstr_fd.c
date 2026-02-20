/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:21:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/11 09:29:09 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_putstrstr_fd(char **strstr, int fd)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (strstr[i])
	{
		len += ft_putendl_fd(strstr[i], fd);
		i++;
	}
	return (len);
}
