/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freearr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:10:33 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/27 13:48:55 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void    ft_freearr(void **arr, void (*f)(void *))
{
    int i;

    i = 0;
    while (arr && arr[i])
        f(arr[i++]);
    free(arr);
}