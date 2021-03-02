/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <hugogoncalv@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:57:31 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/03/02 12:57:42 by hugogoncalv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot =		-1;
	flags.minus =	0;
	flags.star =	0;
	flags.type =	'd';
	flags.width =	0;
	flags.zero =	0;
	flags.nbr_len =	0;
	flags.base =	10;
	flags.push_front =	0;
	flags.signal =	1;
	return (flags);
}

static long	ft_itostr_base(long nbr, t_flags *flags, int nbr_len)
{
	char ten;

	if(nbr_len == 0)
	{
		if (nbr == 0)
			return (0);
		flags->nbr_len += 1;
		ft_itostr_base((nbr / flags->base), flags, 0);
		return (nbr);
	}
	if (nbr == 0 && nbr_len == 1)
	{
		flags->nbr_str[0] = '0';
	}
	if (nbr == 0)
		return (0);
	ft_itostr_base((nbr / flags->base), flags, nbr_len + 1);
	if (nbr % flags->base > 9)
	{
		if(flags->upper == 1)
			ten = 'A';
		else
			ten = 'a';
		flags->nbr_str[flags->nbr_len-nbr_len + flags->push_front] = nbr % flags->base + ten - 10;
	}
	else
		flags->nbr_str[flags->nbr_len-nbr_len + flags->push_front] = nbr % flags->base + '0';
	return (nbr);

}

static void	ft_print_specifier(char fmt, va_list *ap, t_flags *flags)
{
	long	nb;

	flags->type = fmt;
	/*
	if (fmt == 'c')
		ft_putchar_fd((char)va_arg(*ap, int), 1);
	if (fmt == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1);
	*/
	if (fmt != 'c' && fmt != 's')
	{
		if(fmt == 'p')
		{
			nb = (long)va_arg(*ap, int*);
			flags->push_front += 2;
		}
		else
			nb = va_arg(*ap, int);
		if (fmt == 'x' || fmt == 'X' || fmt == 'p')
		{
			flags->base = 16;
			if (fmt == 'X')
				flags->upper = 1;
			if (nb < 0)
				nb = 0xffffffff + nb + 1;
		}
		if (fmt == 'o')
			flags->base = 8;
		if (nb < 0)
		{
			flags->signal = -1;
			flags->push_front++;
			nb *= -1;
		}

		ft_itostr_base(nb, flags, 0);
		flags->nbr_str = calloc(sizeof(char),1 + flags->nbr_len + flags->push_front);

		if(fmt == 'p')
		{
			flags->nbr_str[0] = '0';
			flags->nbr_str[1] = 'x';
		}
		if (flags->signal == -1)
		{
			flags->nbr_str[0] = '-';
		}
		flags->nbr_str[flags->nbr_len]= '\0';
		ft_itostr_base(nb, flags, 1);
		flags->nbr_len += flags->push_front;
	}
}




char	*ft_fprint_getflags(char *fmt, va_list *args, t_flags *flags)
{
	while (1)
	{
		if (*fmt == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (*fmt == '.')
			fmt = ft_flag_dot(fmt, flags, args);
		if (*fmt == '-')
			ft_flag_minus(flags);
		if (*fmt == '+')
			ft_flag_plus(flags);
		if (*fmt == '*')
			ft_flag_width(args, flags);
		if (ft_isdigit(*fmt))
			ft_flag_digit(fmt, flags);
		if(ft_is_spec(*fmt))
			break;
		fmt++;
	}

	if (*fmt == '%')
		ft_putchar_fd('%', 1);
	else
	{
		ft_print_specifier(*fmt, args, flags);
	}
	return (fmt);
}

void	ft_printoscreen(t_flags *flags)
{
	char	pad_char;
	size_t	len;

	pad_char = ' ';
	if(flags->zero)
		pad_char = '0';
	if (flags->width > 0)
	{
		len = flags->width;
		if (flags->minus == 1)
		{
			ft_putstr_fd(flags->nbr_str, 1);
			while (len-(flags->nbr_len) > 0)
			{
				len--;
				ft_putchar_fd(pad_char, 1);
			}
		}
		else
		{
			if(flags->plus == 1)
					len--;
			while (len-(flags->nbr_len) > 0)
			{
				len--;

				ft_putchar_fd(pad_char, 1);
			}

			if(flags->plus == 1 && flags->nbr_str[0] != '-')
				ft_putchar_fd('+', 1);
			ft_putstr_fd(flags->nbr_str, 1);

		}
	}
	//ft_putnbr_fd(flags->plus, 1);
	//ft_putnbr_fd(flags->width, 1);
	//ft_putstr_fd(flags->nbr_str, 1);
}

void	ft_printf(char *fmt, ...)
{
	va_list	args;
	t_flags	flags;

	va_start(args, fmt);
	while (*fmt)
	{
		if(*fmt=='\0')
			break ;
		if (*fmt == '%')
		{
			if (ft_is_flag(*fmt))
				flags = ft_init_flags();
			fmt++;
			fmt = ft_fprint_getflags(fmt, &args, &flags);
			ft_printoscreen(&flags);
		}
		else
			ft_putchar_fd(*fmt, 1);
		fmt++;

	}

	va_end(args);
}
