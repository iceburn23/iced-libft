/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <hugogoncalv@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:21:49 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/02/26 22:11:13 by hugogoncalv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libftprintf.h"

int		countdigits(long  int n, int base)
{
	long  int	i;
	long  int	absn;

	i = 0;
	if (n <= 0)
		i++;
	absn = n;//abs(n);
	while (absn > 0)
	{
		i++;
		absn /= base;
	}
	return (i);
}

char	*ft_itoa_base(long  int n, int base)
{
	long  int			i;
	long  int	absn;
	long  int	c;
	char			*num_str;
	long  int	len;

	len = countdigits(n, base);
	num_str = malloc((len + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	i = 0;
	absn = n;//abs(n);
	if (n < 0)
		num_str[0] = '-';
	if (n == 0)
		num_str[0] = '0';
	while (absn > 0)
	{
		if (absn % base > 9)
			c = absn % base + 'a' - 10;
		else
			c = absn % base + '0';
		num_str[len - 1 - i++] = c;
		absn /= base;
	}
	num_str[len] = '\0';
	return (num_str);
}
