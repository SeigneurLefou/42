/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:38:17 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/11 18:21:43 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

int		ft_strchr(char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strnjoin(char *dest, char *src, size_t size);

char	*while_no_newline(int fd, char *buffer, char *line);
char	*join_line_with_previous_line(char	*buffer, char *line);
char	*give_next_line(char *buffer);
char	*get_next_line(int fd);

#endif
