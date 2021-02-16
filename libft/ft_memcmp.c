/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:44:44 by hyejang           #+#    #+#             */
/*   Updated: 2021/02/17 00:14:07 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *v1;
	unsigned char *v2;

	v1 = (unsigned char *)s1;
	v2 = (unsigned char *)s2;
	while (0 < n--)
		if (*(v1++) != *(v2++))
			return (*(--v1) - *(--v2));
	return (0);
}
