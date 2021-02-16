/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:35:14 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/10 16:28:04 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*src_tmp;

	i = ft_strlen(src);
	j = -1;
	if (!dest)
		return (0);
	if (!size)
		return (i);
	src_tmp = (char *)src;
	while (src_tmp[++j] != '\0' && j < (size - 1))
		dest[j] = src_tmp[j];
	dest[j] = '\0';
	return (i);
}
