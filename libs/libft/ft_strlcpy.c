/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:17:24 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/04 20:40:34 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t index;

	index = 0;
	while ((index + 1 < dstsize) && (src[index] != 0))
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize != 0)
		dst[index] = 0;
	while (src[index])
		index++;
	return (index);
}
