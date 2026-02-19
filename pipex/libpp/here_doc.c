/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:48:59 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/19 16:37:36 by lchamard         ###   ########.fr       */
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
	free(line);
	return (0);
}

int	here_doc_file(char **argv)
{
	int		pipe_fd[2];
	char	*input_user;

	input_user = NULL;
	pipe(pipe_fd);
	get_file_while_not_limiter(0, argv[2], &input_user);
	write(pipe_fd[1], input_user, ft_strlen(input_user));
	close(pipe_fd[1]);
	if (input_user)
		free(input_user);
	return (pipe_fd[0]);
}
