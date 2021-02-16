/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:27:01 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/11 17:38:18 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	i = ft_strlen(s1);
	j = -1;
	k = -1;
	if (!(tmp = (char *)malloc(i + ft_strlen(s2) + 1)))
		return (0);
	while (s1[++j] != '\0')
		tmp[j] = s1[j];
	while (s2[++k] != '\0')
		tmp[j++] = s2[k];
	tmp[j] = '\0';
	return (tmp);
}
