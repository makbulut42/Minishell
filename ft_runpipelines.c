/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runpipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:55:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/02 14:17:33 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static int	getheredocs(t_pipeline **pipes)
{
	int	i;
	int	k;

	i = 0;
	while (pipes && pipes[i])
	{
		k = 0;
		while (pipes[i]->commands[k])
		{
			if (ft_heredoc(pipes[i]->commands[k]))
				return (0);
			if (!getheredocs(pipes[i]->commands[k]->subshells))
				return (0);
			ft_freearr_str(pipes[i]->commands[k]->heredocsteps);
			pipes[i]->commands[k]->heredocsteps = NULL;
			k++;
		}
		i++;
	}
	return (1);
}

static void	runcommands(t_command **cmds)
{
	int		i;
	pid_t	lastcommand;

	ft_connectpipes(cmds);
	i = 0;
	while (cmds[i] && !g_mini->exitflag)
		lastcommand = ft_runcommand(cmds[i++]);
	ft_closepipes();
	if (lastcommand != -1)
	{
		waitpid(lastcommand, &(g_mini->return_code), 0);
		g_mini->return_code = (((g_mini->return_code) & 0xf00) >> 8);
	}
	while (wait(NULL) != -1)
		continue ;
}

void	ft_runpipelines(t_pipeline **pipes)
{
	int	i;

	i = 0;
	if (!getheredocs(pipes))
		return ;
	if (pipes[i++])
		runcommands(pipes[0]->commands);
	while (pipes[i] && !g_mini->exitflag)
	{
		if (pipes[i]->dependon == DEP_AND && g_mini->return_code == 0)
			runcommands(pipes[i]->commands);
		else if (pipes[i]->dependon == DEP_OR && g_mini->return_code != 0)
			runcommands(pipes[i]->commands);
		i++;
	}
	g_mini->intflag = 0;
}
