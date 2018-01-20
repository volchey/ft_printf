/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:01:23 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/11 17:51:35 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		get_str(const char *s, char **str, va_list ap)
{
	int		i;

	i = 0;
	while (*s)
	{
		if(*s == '%')
		{
//			set_stuct(s);
			s += set_arg(s, str, ap);
		}
        if (*s)
    		ft_chrjoin(str, *s);
		if (*s)
			s++;
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*str;
	int		size;

	str = ft_strnew(0);
    *str = '\0';
	va_start(ap, format);
	get_str(format, &str, ap);
	va_end(ap);
	ft_putstr(str);
	size = ft_strlen(str);
    ft_strdel(&str);
	return (size);
}
