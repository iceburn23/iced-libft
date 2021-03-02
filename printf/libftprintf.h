/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoncalv <hugogoncalv@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:40:05 by hugogonca         #+#    #+#             */
/*   Updated: 2021/03/02 05:28:54 by hugogoncalv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	char			*nbr_str;
	size_t			nbr_len;
	int				signal;
	int				push_front;
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				plus;
	int				zero;
	int				dot;
	int				star;
	int				base;
	int				upper;
}					t_flags;

void				ft_printf(char *fmt, ...);
char				*ft_itoa_base(long int n, int base);
int					ft_is_flag(char c);
int					ft_is_spec(char c);
void				ft_flag_minus(t_flags *flags);
void				ft_flag_plus(t_flags *flags);
void				ft_flag_digit(char *c, t_flags *flags);
void				ft_flag_width(va_list *args, t_flags *flags);
char				*ft_flag_dot(char *fmt,t_flags *flags, va_list *args);
#endif
