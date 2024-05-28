/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:11:28 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:07:23 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#typedef u_int8_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memset(void *b, register int c, register size_t len)
{
	register size_t	i;

	i = -1;
	while (++i < len)
		((u_int8_t *)b)[i] = c;
	return (b);
}
