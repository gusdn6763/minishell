/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:15:02 by hyejang           #+#    #+#             */
/*   Updated: 2021/02/16 23:15:10 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_addchr(char **str, char c)
{
	char	*aux;

	aux = ft_calloc(sizeof(char), ft_strlen(*str) + 2);
	ft_memcpy(aux, *str, ft_strlen(*str));
	aux[ft_strlen(aux)] = c;
	if (*str)
		free(*str);
	*str = aux;
}
