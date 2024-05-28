/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:26 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 18:29:27 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
#        */
#include "libft.h" /*
# size_t ft_strlen(const char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_putstr_fd(char *s, register int fd)
{
	write(fd, s, ft_strlen(s));
}

void
	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
