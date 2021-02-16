/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:32:08 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/11 17:37:52 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*f_tmp;

	if (!s || !f)
		return (0);
	i = -1;
	if (!(f_tmp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	while (s[++i] != '\0')
		f_tmp[i] = f(i, s[i]);
	f_tmp[i] = '\0';
	return (f_tmp);
}
