/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 01:10:25 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/01 22:01:41 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;
	size_t			index;

	ptrdest = dest;
	ptrsrc = (unsigned char *)src;
	index = 0;
	while (index < len)
	{
		ptrdest[index] = ptrsrc[index];
		if (ptrsrc[index] == (unsigned char)c)
			return (dest + index + 1);
		index++;
	}
	return (NULL);
}
