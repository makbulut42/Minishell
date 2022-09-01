/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:07:15 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 13:12:50 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"

char	*ft_get_value(char *s)
{
	int		len;
	int		lenvalue;
	char	*value;

	len = ft_strlenchr(s, '=');
	lenvalue = ft_strlen(s + len + 1);
	if (!lenvalue)
		return (0);
	value = ft_substr(s, len + 1, lenvalue);
	return (value);
}
