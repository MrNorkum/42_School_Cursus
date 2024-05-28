/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:20:00 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 18:20:01 by hkeles           ###   ########.tr       */
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

void	ft_putendl_fd(char *s, register int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putendl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
