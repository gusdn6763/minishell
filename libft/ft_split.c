/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:59:07 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/11 20:26:26 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**div_word(char **test, char const *s, char c, int count)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	while (++i != count)
	{
		k = -1;
		while (s[j] == c)
			j++;
		if (!(test[i] = (char *)malloc(sizeof(char) * numchar(s, c, j) + 1)))
		{
			while (--i > -1)
				free(test[i + 1]);
			free(test);
			return (0);
		}
		while (s[j] != '\0' && s[j] != c)
			test[i][++k] = s[j++];
		test[i][++k] = '\0';
	}
	test[i] = NULL;
	return (test);
}

static int		get_count(char const *s, char c)
{
	int i;
	int div_count;

	i = -1;
	div_count = 0;
	if (s[0] == '\0' || !s)
		return (0);
	if (s[0] != c)
		div_count++;
	while (s[++i] != '\0')
		if (s[i] == c && s[i + 1] != '\0')
		{
			if (s[i + 1] == c)
				while (s[i + 1] == c)
				{
					if (s[i + 1] == '\0')
						div_count--;
					i++;
				}
			div_count++;
		}
	if (s[i - 1] == c)
		div_count--;
	return (div_count);
}

char			**ft_split(char const *s, char c)
{
	int		div_count;
	char	**tmp;

	if (s == NULL)
		return (NULL);
	div_count = get_count(s, c);
	if (!(tmp = (char **)malloc(sizeof(char *) * div_count + 1)))
		return (NULL);
	return (div_word(tmp, s, c, div_count));
}
