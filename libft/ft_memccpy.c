/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:01:27 by hugogonca         #+#    #+#             */
/*   Updated: 2021/02/19 15:31:21 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		cuc;
	unsigned char		*dstc;
	const unsigned char	*srccc;
	size_t				i;

	cuc = (unsigned char)c;
	dstc = (unsigned char *)dst;
	srccc = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dstc[i] = srccc[i];
		if (srccc[i] == cuc)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
