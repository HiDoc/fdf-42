/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:24:48 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/14 10:31:21 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(unsigned long n, int c)
{
	return ((n > 9 ? ft_getlen(n / 10, c + 1) : c));
}

char			*ft_ultoa(unsigned long n)
{
	char	*nbr;
	int		count;

	if (n == 0)
		return (ft_strdup("0"));
	count = ft_getlen(n, 0);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 2)))) == NULL)
		return (NULL);
	nbr[count + 1] = '\0';
	while (count >= 0)
	{
		nbr[count] = ABS((n % 10)) + '0';
		count--;
		n /= 10;
	}
	return (nbr);
}
