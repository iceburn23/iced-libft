/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 23:17:25 by hugogonca         #+#    #+#             */
/*   Updated: 2021/02/14 23:17:56 by hugogonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	array_len;

	array_len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	str = (char*)malloc((array_len + 1) * sizeof(*s1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, array_len + 1);
	return (str);
}
