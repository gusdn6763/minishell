/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:56:03 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/08 15:58:02 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*src_tmp;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	src_tmp = (char *)src;
	if (size <= i)
	{
		j += size;
		return (j);
	}
	else
		j += i;
	k = 0;
	while (src_tmp[k] != '\0' && i + 1 < size)
	{
		dst[i] = src_tmp[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}
