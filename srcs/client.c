/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:31:57 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/27 16:15:04 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_wait_sig;

static	int	ft_wait_sig(void)
{
	while (g_wait_sig == 0)
		usleep(10);
	if (g_wait_sig == 1)
		g_wait_sig = 0;
	return (1);
}

static	void	send_bit(int pid, unsigned char bit)
{
	int	i;

	i = -1;
	while (128 >> ++i)
	{
		usleep(100);
		if ((128 >> i) & bit)
		{
			if (kill(pid, SIGUSR2) != 0)
			{
				write(2, "Error\nUnable to send signal\n", 28);
				exit(0);
			}
			ft_wait_sig();
		}
		else
		{
			if (kill(pid, SIGUSR1) != 0)
			{
				write(2, "Error\nUnable to send signal\n", 28);
				exit(0);
			}
			ft_wait_sig();
		}
	}
}

static	void	ft_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Signal received\n", 1);
	g_wait_sig = 1;
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;

	if (ac != 3)
	{
		write(2, "Error\nExpected 2 arguments: pid and string\n", 43);
		return (-1);
	}
	if (!ft_check_pid(av[1]))
		return (-1);
	pid = ft_atoi(av[1]);
	i = -1;
	signal(SIGUSR1, ft_handler);
	while (av[2][++i])
		send_bit(pid, av[2][i]);
	send_bit(pid, '\0');
	return (0);
}
