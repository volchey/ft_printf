/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_farg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:08:39 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/01 15:08:41 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		get_c3(va_list ap, char c1, char c2, t_list **str)
{
	if (c1 == 'h' && (c2 == 'd' || c2 == 'i'))
		ft_itoa(va_arg(ap, signed int), str);
	else if (c1 == 'h' && c2 == 'u')
		ft_unitoa_base((unsigned char)va_arg(ap, int), 10, str);
	else if (c1 == 'h' && c2 == 'o')
		ft_unitoa_base((unsigned char)va_arg(ap, int), 8, str);
	else if (c1 == 'h' && c2 == 'x')
		ft_unitoa_base((unsigned char)va_arg(ap, int), 16, str);
	else if (c1 == 'h' && c2 == 'X')
		ft_unitoa_uppbase((unsigned char)va_arg(ap, int), 16, str);
	else if (c1 == 'l' && (c2 == 'd' || c2 == 'i'))
		ft_itoa(va_arg(ap, long long), str);
	else if (c1 == 'l' && c2 == 'u')
		ft_unitoa_base(va_arg(ap, unsigned long long), 10, str);
	else if (c1 == 'l' && c2 == 'o')
		ft_unitoa_base(va_arg(ap, unsigned long long), 8, str);
	else if (c1 == 'l' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, unsigned long long), 16, str);
	else if (c1 == 'l' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, unsigned long long), 16, str);
}

void		get_c2(va_list ap, char c1, char c2, t_list **str)
{
	if (c1 == 'h' && (c2 == 'd' || c2 == 'i'))
		ft_itoa((short int)va_arg(ap, int), str);
	else if (c1 == 'h' && c2 == 'u')
		ft_unitoa_base((unsigned short int)va_arg(ap, unsigned int), 10, str);
	else if (c1 == 'h' && c2 == 'o')
		ft_unitoa_base((unsigned short int)va_arg(ap, unsigned int), 8, str);
	else if (c1 == 'h' && c2 == 'x')
		ft_unitoa_base((unsigned short int)va_arg(ap, unsigned int), 16, str);
	else if (c1 == 'h' && c2 == 'X')
		ft_unitoa_uppbase((unsigned short int)va_arg(ap, unsigned int), 16, str);
	else if (c1 == 'l' && (c2 == 'd' || c2 == 'i'))
		ft_itoa(va_arg(ap, long int), str);
	else if (c1 == 'l' && c2 == 'u')
		ft_unitoa_base(va_arg(ap, unsigned long int), 10, str);
	else if (c1 == 'l' && c2 == 'o')
		ft_unitoa_base(va_arg(ap, unsigned long int), 8, str);
	else if (c1 == 'l' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, unsigned long int), 16, str);
	else if (c1 == 'l' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, unsigned long int), 16, str);
}

void		get_c1(va_list	ap, char c1, char c2, t_list **str)
{
	if (c1 == 'z' && (c2 == 'd' || c2 == 'i'))
		ft_itoa(va_arg(ap, size_t), str);
	else if (c1 == 'z' && c2 == 'u')
		ft_unitoa_base(va_arg(ap, size_t), 10, str);
	else if (c1 == 'z' && c2 == 'o')
		ft_unitoa_base(va_arg(ap, size_t), 8, str);
	else if (c1 == 'z' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, size_t), 16, str);
	else if (c1 == 'z' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, size_t), 16, str);
	else if (c1 == 'j' && (c2 == 'd' || c2 == 'i'))
		ft_itoa(va_arg(ap, intmax_t), str);
	else if (c1 == 'j' && c2 == 'u')
		ft_unitoa_base(va_arg(ap, uintmax_t), 10, str);
	else if (c1 == 'j' && c2 == 'o')
		ft_unitoa_base(va_arg(ap, uintmax_t), 8, str);
	else if (c1 == 'j' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, uintmax_t), 16, str);
	else if (c1 == 'j' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, uintmax_t), 16, str);
}

void		get_farg(va_list ap, t_format *format, t_list **str, int *len)
{
	char	c1;
	char 	c2;
	char	c3;

	c1 = (format->variable)[0];
	c2 = (format->variable)[1];
	c3 = (format->variable)[2];
	if ((c2 == 'l' || c2 == 'h') && (c1 == c2))
	{
		*len += 2;
		get_c3(ap, c2, c3, str);
	}
	else
	{
		(*len)++;
		if (c1 == 'z' || c1 == 'j')
			get_c1(ap, c1, c2, str);
		else
			get_c2(ap, c1, c2, str);
	}
}
