/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <lchamard@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:04:13 by lchamard          #+#    #+#             */
/*   Updated: 2025/11/07 12:10:04 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_catcher(char cr_format, va_list args)
{
	size_t	len;

	if (cr_format == 'c')
		len = ft_putchar_fd(va_arg(args, int), 1);
	else if (cr_format == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (cr_format == 'p')
		len = ft_putvoids_fd(va_arg(args, size_t), 1);
	else if (cr_format == 'd' || cr_format == 'i')
		len = ft_putnbr_fd(va_arg(args, int), 1);
	else if (cr_format == 'u')
		len = ft_put_unsigned_nbr_fd(va_arg(args, t_unint), 1);
	else if (cr_format == 'x')
		len = ft_putnbrbase_fd(va_arg(args, t_unint), "0123456789abcdef", 1);
	else if (cr_format == 'X')
		len = ft_putnbrbase_fd(va_arg(args, t_unint), "0123456789ABCDEF", 1);
	else if (cr_format == '%')
		len = ft_putchar_fd('%', 1);
	else
	{
		write(1, "%", 1);
		write(1, &cr_format, 1);
		len = 2;
	}
	return (len);
}

static size_t	ft_format_str(const char *format, va_list args,
	size_t *ptr_txt)
{
	size_t	len;

	if (format[*ptr_txt] == '%')
	{
		if (format[*ptr_txt + 1])
			len = ft_format_catcher(format[*ptr_txt + 1], args);
		else
			return (-1);
		*ptr_txt += 2;
	}
	else
	{
		write(1, &format[*ptr_txt], 1);
		len = 1;
		(*ptr_txt)++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	print_len;
	long	format_len;
	size_t	ptr_txt;
	va_list	args;

	if (!format)
		return (-1);
	print_len = 0;
	format_len = 0;
	ptr_txt = 0;
	va_start(args, format);
	while (format[ptr_txt])
	{
		format_len = ft_format_str(format, args, &ptr_txt);
		if (format_len < 0)
			return (-1);
		print_len += format_len;
	}
	va_end(args);
	return (print_len);
}
