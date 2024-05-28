/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:24:42 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 18:24:43 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_putnbr_fd(register int n, register int fd)
{
	register long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = 1 + ~nb;
		write(fd, "-", 1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	write(fd, &"0123456789"[nb % 10], 1);
}

void
	ft_putnbr(register int n)
{
	register long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = 1 + ~nb;
		write(1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}
