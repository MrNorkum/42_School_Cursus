/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:35:41 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/04 00:21:35 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <signal.h> /*
# define SIGUSR2
# define SIGUSR1
#typedef pid_t;
#  sig_t signal(int, void (*func)(int));
#    int kill(pid_t, int);
#        */
#include <stdbool.h> /*
# define false
#        */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
#    int usleep(useconds_t);
#        */
#include <stdint.h> /*
#typedef u_int8_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ pid_t	ft_atoi(const char *s);
extern __inline__ void	received_signal(register int sig);
extern __inline__ void	signal_sender(pid_t pid, char c);
extern __inline__ bool	err_client(void);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char *argv[])
{
	register pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1)
			return (-1);
		signal(SIGUSR2, received_signal);
		while (*argv[2])
			signal_sender(pid, *argv[2]++);
		signal_sender(pid, '\0');
		return (0);
	}
	return (err_client());
}

extern __inline__ pid_t
	ft_atoi(const char *s)
{
	register bool	sign;
	pid_t			res;

	while (*s == ' ' || (9 <= *s && *s <= 13))
		s++;
	if (*s == '-')
		sign = true;
	if (*s == '-' || *s == '+')
		s++;
	while ('0' <= *s && *s <= '9')
		res = (res * 10) + (*s++ & 15);
	if (sign)
		return (1 + ~res);
	return (res);
}

extern __inline__ void
	received_signal(register int sig)
{
	if (sig == SIGUSR2)
		write(1, "Signal Received\n", 16);
}

extern __inline__ void
	signal_sender(pid_t pid, char c)
{
	register u_int8_t	idx;

	idx = -1;
	while (++idx < 8)
	{
		kill(pid, SIGUSR1 + !(c << idx & 128));
		usleep(200);
	}
}

extern __inline__ bool
	err_client(void)
{
	write(1, "$---------------------------------$\n", 36);
	write(1, "~> ./client <PID> <STRING to send>\n", 35);
	write(1, "$---------------------------------$\n", 36);
	return (!false);
}
