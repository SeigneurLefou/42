/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:46:17 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/19 16:35:51 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	pipex_loop(int argc, char **argv, char **env)
{
	t_pipex	pipex_var;

	pipex_var.outfile = argv[argc - 1];
	init_pipex_bonus(argc, argv, &pipex_var);
	pipex_var.env = env;
	if (pipex_var.fd[0] == -1)
		pipex_var.fd[0] = fake_fdin();
	if (!strcmp(argv[1], "here_doc"))
		execution_loop_here_doc(&pipex_var);
	else
		execution_loop(&pipex_var);
	return (pipex_var);
}

int	main(int argc, char **argv, char **env)
{
	int		werror;
	int		exit_code;
	t_pipex	pipex_var;

	if ((argv && argv[1] && !strcmp(argv[1], "here_doc") && argc < 6)
		|| argc < 5 || !env)
		return (1);
	pipex_var = pipex_loop(argc, argv, env);
	close(pipex_var.fd[0]);
	ft_cmdclear(pipex_var.cmd);
	werror = wait_all_pid(&pipex_var);
	exit_code = give_exit_code(werror);
	perror(NULL);
	exit(exit_code);
}
