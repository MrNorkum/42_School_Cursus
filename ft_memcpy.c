/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:01:32 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 18:01:33 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#        */
#include "libft.h" /*
#   void *ft_memmove(void *, const void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memcpy(void *dst, const void *src, register size_t n)
{
	return (ft_memmove(dst, src, n));
}
