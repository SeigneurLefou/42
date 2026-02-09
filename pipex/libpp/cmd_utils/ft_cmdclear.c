/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:03:31 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/09 15:16:22 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmdclear(t_cmd **cmd, void (*del)(char *))
{
	t_cmd	*tmp;
	t_cmd	*last;

	if (!cmd || !del || !*cmd)
		return ;
	tmp = *cmd;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
		del(last->cmd_name);
		free(last);
	}
	*cmd = NULL;
}
