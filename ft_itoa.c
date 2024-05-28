/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:21:28 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:03:03 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef u_int8_t;
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ u_int8_t	ft_numlen(register long nb);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*ft_itoa(register int n)
{
	register long	nb;
	u_int8_t		len;
	char			*res;

	nb = n;
	len = ft_numlen(nb);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
		*res = '-';
	if (!nb)
		*res = '0';
	if (nb < 0)
		nb = 1 + ~nb;
	res[len] = '\0';
	while (!!nb)
	{
		res[--len] = nb % 10 + 48;
		nb /= 10;
	}
	return (res);
}

extern __inline__ u_int8_t
	ft_numlen(register long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb && ++i)
		nb /= 10;
	return (i);
}
