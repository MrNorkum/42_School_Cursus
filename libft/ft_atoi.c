/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:38:10 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 14:38:34 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define false 0 
# define true 1
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	ft_isspaces(int c);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	ft_atoi(const char *str)
{
	int				res;
	register bool	sign;

	res = 0;
	sign = false;
	while (ft_isspaces(*str) == 1)
		str++;
	if (*str == '-')
		sign = true;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		res = (res * 10) + (*str++ & 15);
	if (sign == true)
		return (1 + ~res);
	return (res);
}

extern __inline__ int
	ft_isspaces(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}
