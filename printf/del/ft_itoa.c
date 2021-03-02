/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <hugogoncalv@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:46:53 by hgoncalv          #+#    #+#             */
/*   Updated: 2021/02/19 23:47:24 by hugogoncalv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countdigits(int n)
{
	unsigned int	i;
	unsigned int	absn;

	i = 0;
	if (n <= 0)
		i++;
	absn = abs(n);
	while (absn > 0)
	{
		i++;
		absn /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	absn;
	char			*buf;
	unsigned int	len;

	n = n * 1;
	len = countdigits(n);
	buf = malloc((len + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	absn = abs(n);
	if (n < 0)
		buf[0] = '-';
	if (n == 0)
		buf[0] = '0';
	while (absn > 0)
	{
		buf[len - 1 - i++] = absn % 10 + '0';
		absn /= 10;
	}
	buf[len] = '\0';
	return (buf);
}
