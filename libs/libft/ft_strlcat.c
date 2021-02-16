/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:40:25 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/04 17:45:52 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t destlen;
	size_t k;

	k = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= dstsize)
		return (srclen + dstsize);
	while ((destlen + 1 + k < dstsize) && (*src != 0))
	{
		dest[destlen + k] = *src;
		src++;
		k++;
	}
	dest[destlen + k] = 0;
	return (destlen + srclen);
}
