/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseredoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:24:39 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/30 14:28:24 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_parseredoutput(t_command *cmd, t_token **tokens, int *i)
{
    t_stream    *stream;

    stream = ft_calloc(sizeof(t_stream), 1);
    if (tokens[*i]->type == RED_APPEND)
        stream->appendmode = 1;
    (*i)++;
    if (tokens[*i] && tokens[*i]->type == WORD)
    {
        stream->path = ft_strdup(tokens[*i]->data);
        stream->type = STREAM_OUT;
        ft_addarr_stream(&(cmd->redirections), stream);
        return (1);
    }
    ft_syntaxerror(tokens[*i]);
    ft_freestream(stream);
    return (0);
}