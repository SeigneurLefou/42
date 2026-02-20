/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:53:44 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/20 11:05:21 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fake_fdin(void)
{
	int	fake_pipe[2];

	pipe(fake_pipe);
	close(fake_pipe[1]);
	return (fake_pipe[0]);
}

t_cmd	*init_list_cmd(int argc, char **argv)
{
	int		i;
	t_cmd	*cmd;
	t_cmd	*new;

	i = 1;
	cmd = ft_cmdnew(argv[0], 0);
	while (i < argc)
	{
		new = ft_cmdnew(argv[i], i);
		ft_cmdadd_back(&cmd, &new);
		i++;
	}
	return (cmd);
}

void	init_pipex(int argc, char **argv, t_pipex *pipex_var)
{
	pipex_var->cmd = init_list_cmd(argc - 3, argv + 2);
	pipex_var->fd[0] = open(argv[1], O_RDONLY);
	if (pipex_var->fd[0] == -1)
	{
		pipex_var->fd[0] = fake_fdin();
		pipex_var->cmd = pipex_var->cmd->next;
	}
	pipex_var->pid = ft_calloc(sizeof(int), argc - 2);
	if (errno)
		perror(NULL);
}

void	init_pipex_bonus(int argc, char **argv, t_pipex *pipex_var)
{
	int	number_move_right_argv;

	number_move_right_argv = 2;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		number_move_right_argv = 3;
		pipex_var->fd[0] = here_doc_file(argv);
	}
	else
	{
		number_move_right_argv = 2;
		pipex_var->fd[0] = open(argv[1], O_RDONLY);
		if (errno)
			perror(NULL);
	}
	pipex_var->cmd = init_list_cmd(argc - (number_move_right_argv + 1),
			argv + number_move_right_argv);
	if (pipex_var->fd[0] == -1)
	{
		pipex_var->fd[0] = fake_fdin();
		if (pipex_var->cmd && pipex_var->cmd->next)
			pipex_var->cmd = pipex_var->cmd->next;
	}
	pipex_var->pid = ft_calloc(sizeof(int),
			argc - (number_move_right_argv));
}
