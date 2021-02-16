/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42.seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:26:05 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/05 17:11:16 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char *ptrdest;
	unsigned char *ptrsrc;

	if (dest == 0 && src == 0)
		return (NULL);
	ptrdest = dest;
	ptrsrc = (unsigned char *)src;
	while (len-- > 0)
	{
		*ptrdest++ = *ptrsrc++;
	}
	return (dest);
}
