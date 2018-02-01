/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:41:47 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 16:01:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_to_str(long long n, long long i, int f, t_list **str)
{
	if (f)
		ft_chrjoin(str, '-');
	while (i > 0)
	{
		ft_chrjoin(str, (n / i + '0'));
		n %= i;
		i /= 10;
	}
}

void			ft_itoa(long long n, t_list **str)
{
	long long	i;
	int			f;

	i = 1;
	f = 0;
	if (n < 0)
	{
		f = 1;
		n *= -1;
	}
	while (n / i > 9)
		i *= 10;
	ft_to_str(n, i, f, str);
}

