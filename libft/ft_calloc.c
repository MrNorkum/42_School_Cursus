/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:04:21 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 15:04:24 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_calloc(register size_t count, register size_t size)
{
	register size_t	i;
	register size_t	countxsize;
	void			*ptr;

	i = -1;
	countxsize = count * size;
	ptr = malloc(countxsize);
	if (!!ptr)
	{
		while (++i < countxsize)
			((char *)ptr)[i] = 0;
	}
	return (ptr);
}
