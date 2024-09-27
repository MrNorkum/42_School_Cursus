/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:00:25 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 19:00:26 by hkeles           ###   ########.tr       */
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

char
	*ft_strdup(const char *s1)
{
	register size_t	len;
	char			*dup;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	len = -1;
	while (s1[++len] != '\0')
		dup[len] = s1[len];
	dup[len] = '\0';
	return (dup);
}
