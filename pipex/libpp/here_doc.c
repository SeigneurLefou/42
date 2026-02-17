/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:48:59 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/17 17:50:09 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file_while_not_limiter(int fd, char *limiter, char **buffer)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		*buffer = ft_strjoin(*buffer, line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

char	*here_doc_file(char **argv)
{
	char	*input_user;
	int		tmp_fd;

	input_user = "";
	get_file_while_not_limiter(0, argv[2], &input_user);
	tmp_fd = open(".truncate_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(tmp_fd, input_user, ft_strlen(input_user));
	close(tmp_fd);
	return (".truncate_file");
}
