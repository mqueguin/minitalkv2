/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:15:15 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/27 16:19:42 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_pid(char *pid)
{
	if (!ft_is_digit(pid))
	{
		ft_putstr_fd("Error\nThe pid must contain only numbers\n", 2);
		return (0);
	}
	if (ft_atoi(pid) < 1 || ft_atoi(pid) > 4194304)
	{
		ft_putstr_fd("Error\nThe pid is not valid\n", 2);
		return (0);
	}
	return (1);
}
