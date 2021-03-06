/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:20:10 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/27 16:22:54 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_buffer	g_buffer;

void	ft_init(void)
{
	ft_memset(g_buffer.buff, 0, 1000);
	g_buffer.count = 0;
	g_buffer.bit_count = 0;
}

void	ft_print(void)
{
	if (g_buffer.buff[g_buffer.count - 1] == '\0')
	{
		write(1, g_buffer.buff, ft_strlen(g_buffer.buff));
		write(1, "\n", 1);
		ft_init();
		if (kill(g_buffer.pid, SIGUSR2) != 0)
		{
			ft_putstr_fd("Error\nUnable to send signal to client\n", 2);
			exit(0);
		}
	}
}

void	store_bit(int bit)
{
	g_buffer.bit_max = 32768 >> g_buffer.bit_count;
	if (bit == 1)
		g_buffer.buff[g_buffer.count] = g_buffer.buff[g_buffer.count]
			| g_buffer.bit_max;
	g_buffer.bit_count++;
	if (g_buffer.bit_count == 16)
	{
		g_buffer.bit_count = 0;
		g_buffer.count++;
		if (g_buffer.count == 999)
		{
			write(1, g_buffer.buff, ft_strlen(g_buffer.buff));
			ft_init();
		}
		else
			ft_print();
	}
	if (kill(g_buffer.pid, SIGUSR1) != 0)
	{
		ft_putstr_fd("Error\nUnable to send signal to client\n", 2);
		exit(0);
	}
}

void	ft_receive_bit(int sig, siginfo_t *si, void *arg)
{
	(void)arg;
	g_buffer.pid = si->si_pid;
	if (sig != SIGUSR1 && sig != SIGUSR2)
	{
		ft_putstr_fd("Error\nThe received signal is not SIGUSR1 or SIGUSR2\n", 2);
		exit(0);
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			store_bit(0);
		else
			store_bit(1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putstr_fd("The PID is : ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	ft_init();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_receive_bit;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		usleep(1);
	return (0);
}
