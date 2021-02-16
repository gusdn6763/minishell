/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:23:41 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 17:04:11 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *value, int to_find, size_t size)
{
	size_t			i;
	unsigned char	to_find_tmp;
	unsigned char	*value_tmp;

	i = -1;
	to_find_tmp = (unsigned char)to_find;
	value_tmp = (unsigned char*)value;
	while (++i < size)
		if (value_tmp[i] == to_find_tmp)
			return ((void *)&(value_tmp[i]));
	return (0);
}
