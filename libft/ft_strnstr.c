/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:40:05 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 16:49:42 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *value, const char *t_v, size_t len)
{
	size_t	i;
	size_t	j;
	char	*val_tmp;
	char	*to_find_tmp;

	val_tmp = (char *)t_v;
	to_find_tmp = (char *)value;
	i = -1;
	if (val_tmp[i + 1] == '\0')
		return ((char*)value);
	while (to_find_tmp[++i] != '\0' && i < len)
	{
		j = 0;
		while (to_find_tmp[i + j] != '\0' && to_find_tmp[i + j] == val_tmp[j]
		&& i + j < len)
		{
			if (val_tmp[j + 1] == '\0')
				return (&to_find_tmp[i]);
			++j;
		}
	}
	return (0);
}
