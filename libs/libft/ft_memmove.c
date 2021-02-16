/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:59:34 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/07 00:26:40 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	char		*lastd;
	const char	*s;
	const char	*lasts;

	if (dest == 0 && src == 0)
		return (NULL);
	d = dest;
	s = src;
	if (d < s)
		while (len-- > 0)
			*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len-- > 0)
			*lastd-- = *lasts--;
	}
	return (dest);
}
