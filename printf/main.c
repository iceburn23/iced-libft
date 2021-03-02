/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <hugogoncalv@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:50:58 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/03/02 12:59:15 by hugogoncalv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>



int	main(void)
{
	int i;
	ft_printf("%-10o", 230);
	printf("\n%-10o\n", 230);
	//ft_printf("\n%x", 123);
	//ft_printf("\n%.*d", 5, 10);
	//printf("%d", -123);
	return(0);
}
