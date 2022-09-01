/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:05:15 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 12:30:14 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"

int	ft_initbuiltin(t_command *cmd)
{
	pid_t	pid;

	if (cmd->in != 0 || cmd->out != 1)
	{
		pid = fork();
		if (pid == 0)
		{
			g_mini->exitflag = 1;
			if (!ft_open_reads(cmd))
				return (-1);
			g_mini->return_code = ft_runbuiltin(cmd);
			ft_closepipes();
			return (-1);
		}
		return (pid);
	}
	if (!ft_open_reads(cmd))
		return (-1);
	g_mini->return_code = ft_runbuiltin(cmd);
	return (-1);
}