/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 02:31:41 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/05 19:33:39 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = (long long)n * (long long)-1;
	}
	else
		num = (long long)n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	write(fd, &"0123456789"[num % 10], 1);
}
