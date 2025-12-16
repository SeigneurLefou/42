/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:14:36 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/28 12:01:42 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isascii(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(char *nptr);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(char *s, int c);
int		ft_toupper(int c);
void	*ft_memchr(void *s, int c, size_t n);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_memcmp(void *s1, void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strrchr(char *s, int c);
int		ft_isalnum(int c);
char	*ft_itoa(int nb);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *str, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

#endif
