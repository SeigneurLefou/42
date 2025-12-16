/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:18:33 by lchamard          #+#    #+#             */
/*   Updated: 2025/11/05 10:34:45 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef unsigned int	t_unint;

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putvoids_fd(size_t ptr, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_put_unsigned_nbr_fd(unsigned int nb, int fd);
int		ft_putendl_fd(char *str, int fd);
int		ft_putnbrbase_fd(size_t nb, char *base, int fd);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);

#endif
