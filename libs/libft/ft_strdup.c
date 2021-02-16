/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 01:35:28 by hyolim            #+#    #+#             */
/*   Updated: 2020/04/30 02:08:30 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	if (!(ptr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
