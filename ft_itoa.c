/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:42:38 by efriedma          #+#    #+#             */
/*   Updated: 2018/02/26 12:17:51 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isneg(int *n, int *isneg)
{
	if (*n < 0)
	{
		*isneg += 1;
		*n *= -1;
	}
}

static void	ft_len(int n, int *len, int isneg)
{
	if (n == 0)
		*len = 2;
	while (n /= 10)
		*len += 1;
	if (isneg)
		*len += 1;
	*len += 2;
}

static int	ft_end(int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		isneg;
	char	*ptr;
	int		len;

	isneg = 0;
	len = 0;
	if (ft_end(n))
		return (0);
	ft_isneg(&n, &isneg);
	ft_len(n, &len, isneg);
	ptr = (char*)malloc(sizeof(char) * (len));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || ptr == 0)
		return (!ptr ? 0 : ft_strcpy(ptr, "0"));
	ft_bzero(ptr, len--);
	ptr[--len] = '0' + n % 10;
	while (n /= 10)
		ptr[--len] = '0' + n % 10;
	if (isneg)
		ptr[0] = '-';
	return (ptr);
}
