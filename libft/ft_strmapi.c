/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:28:03 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 19:28:04 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#   void *malloc(size_t);
#        */
#include "libft.h" /*
# size_t ft_strlen(const char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	register size_t	idx;
	register size_t	s_len;
	char			*str;

	idx = -1;
	s_len = ft_strlen(s);
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (NULL);
	str[s_len] = '\0';
	while (s[++idx])
		str[idx] = f(idx, s[idx]);
	return (str);
}
