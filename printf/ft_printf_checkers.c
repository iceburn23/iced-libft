/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <hugogoncalv@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:43:13 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/03/02 05:27:52 by hugogoncalv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' '
		|| c >= '0'|| c <= '9')
		return (1);
	else
		return (0);
}

int		ft_is_spec(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'e' || c == 'E'
		|| c == 'f' || c == 'g' || c == 'G' || c == 'o'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'n')
		return (1);
	else
		return (0);
}


void		ft_flag_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void		ft_flag_plus(t_flags *flags)
{
	flags->plus = 1;
}

void		ft_flag_digit(char *c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (*c - '0');
}

void		ft_flag_width(va_list *args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
}

char		*ft_flag_dot(char *fmt,
				t_flags *flags, va_list *args)
{
	fmt++;
	if (*fmt == '*')
	{
		flags->dot = va_arg(*args, int);
		fmt++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(*fmt))
			flags->dot = (flags->dot * 10) + (*(fmt++) - '0');
	}
	return (fmt);
}
