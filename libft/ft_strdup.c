/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:14:02 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 17:03:50 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_strlen(src);
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	j = -1;
	while (src[++j] != '\0')
		tmp[j] = src[j];
	tmp[j] = '\0';
	return (tmp);
}
