/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:06:43 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 19:06:44 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#   void *malloc(size_t);
#        */
#include "libft.h" /*
#   char *ft_strdup(const char *);
# size_t ft_strlen(const char *);
#   void *ft_memmove(void *, const void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strjoin(char const *s1, char const *s2)
{
	register size_t	i;
	register size_t	j;
	char			*str;

	if (!s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1);
	j = ft_strlen(s2) + 1;
	str = (char *)malloc(i + j);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, i + 1);
	ft_memmove(str + i, s2, j);
	str[i + j - 1] = '\0';
	return (str);
}
