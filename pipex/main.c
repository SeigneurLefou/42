/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:46:17 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/18 08:24:55 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		werror;
	int		exit_code;
	t_pipex	pipex_var;

	if (argv && argv[1] && !strcmp(argv[1], "here_doc") && argc < 6)
		return (1);
	if (argc < 5)
		return (1);
	if (!env)
		return (1);
	pipex_var.outfile = argv[argc - 1];
	init_pipex(argc, argv, &pipex_var);
	pipex_var.env = env;
	pipex_var.fd[0] = open(pipex_var.infile, O_RDONLY);
	if (pipex_var.fd[0] == -1)
		pipex_var.fd[0] = fake_fdin();
	execution_loop(&pipex_var);
	close(pipex_var.fd[0]);
	ft_cmdclear(pipex_var.cmd);
	werror = wait_all_pid(&pipex_var);
	exit_code = give_exit_code(werror);
	perror(NULL);
	exit(exit_code);
}
