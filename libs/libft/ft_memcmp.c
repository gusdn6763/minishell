/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:32:11 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/05 17:01:06 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t count)
{
	unsigned char *ucptr1;
	unsigned char *ucptr2;

	ucptr1 = (unsigned char *)ptr1;
	ucptr2 = (unsigned char *)ptr2;
	while (count-- > 0)
	{
		if (*ucptr1 != *ucptr2)
			return ((unsigned char)*ucptr1 - (unsigned char)*ucptr2);
		ucptr1++;
		ucptr2++;
	}
	return (0);
}
