/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:09:35 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:09:37 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#        */
#include "libft.h" /*
# size_t ft_strlen(const char *);  
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char	*ft_strrchr(const char *s, register int c)
{
	register int	idx;

	idx = ft_strlen(s) + 1;
	while (--idx >= 0)
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
	return (NULL);
}
