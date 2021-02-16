/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:25:30 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 16:49:40 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *to_find, int value)
{
	int		i;
	char	value_tmp;
	char	*to_find_tmp;

	i = 0;
	value_tmp = (char)value;
	to_find_tmp = (char *)to_find;
	while (to_find_tmp[i] != '\0')
		i++;
	while (i != -1)
	{
		if (to_find_tmp[i] == value_tmp)
			return (&(to_find_tmp[i]));
		i--;
	}
	return (0);
}
