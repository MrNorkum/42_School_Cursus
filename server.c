/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:38:34 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/04 00:22:14 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <signal.h> /*
# define SIGUSR2
# define SIGUSR1
# struct sigaction;
#typedef siginfo_t;
#    int sigaction(int, struct sigaction *, struct sigaction *);
#  pid_t getpid(void);
#    int kill(pid_t, int);
#        */
#include <stdint.h> /*
#typedef u_int8_t;
#        */
#include <stdbool.h> /*
# define true
#        */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
#    int pause(void);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	start_server(void);
extern __inline__ void	ft_putuint(register unsigned int n);
extern __inline__ void	signal_handler(register int sig, siginfo_t *info,
							void *context);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(void)
{
	struct sigaction	x;

	x.sa_flags = SA_SIGINFO;
	x.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &x, NULL);
	sigaction(SIGUSR2, &x, NULL);
	start_server();
	while (true)
		pause();
}

extern __inline__ void
	signal_handler(register int sig, siginfo_t *info, void *context)
{
	static u_int8_t	i = 0;
	static u_int8_t	c = 0;

	(void)context;
	c = (c << 1) | !!(sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
	}
}

extern __inline__ void
	start_server(void)
{
	write(1, "\n$------------$\n", 16);
	write(1, "PID ~> ", 8);
	ft_putuint(getpid());
	write(1, "\n$------------$\n", 16);
	write(1, "\n~> ", 4);
}

extern __inline__ void
	ft_putuint(register unsigned int n)
{
	if (n > 9)
		ft_putuint(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}
