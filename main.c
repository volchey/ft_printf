/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:37:36 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/11 17:50:47 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <locale.h>

int main()
{
	char	*str;
	int		x[4] = {24, 256, 23, 0};

	setlocale(LC_ALL, "");
	str = ft_strnew(2);
	str[0] = 'H';
//	ft_putchar(x);
	printf("printf: %x %cs %C %p\n", -1742, 'i', x[0], str);
	ft_printf("ft_printf: %x %cs %C %p\n", -1742, 'i', x[0], str);
//	system("leaks a.out");
}
