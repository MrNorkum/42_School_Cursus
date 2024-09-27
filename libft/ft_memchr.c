/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:11 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:00:30 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memchr(const void *s, register int c, register size_t n)
{
	register size_t	i;

	i = -1;
	while (++i < n)
		if (((char *)s)[i] == (char)c)
			return ((void *)&s[i]);
	return (NULL);
}
