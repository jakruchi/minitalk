/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:27:00 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/23 13:18:16 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h> // printf()
#include <unistd.h> // getpid()
#include <stdio.h> // printf()
#include <signal.h> // kill()

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

void	send_signal(char c, pid_t pid)
{
	// printf("\n		%d", c);
	if ((c / 64) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		c -= 64;
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
	if ((c / 32) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		c -= 32;
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
	if ((c / 16) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		c -= 16;
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
	if ((c / 8) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		c -= 8;
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
	if ((c / 4) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		c -= 4;
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
	if ((c / 2) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		c -= 2;
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
	if ((c / 1) >= 1)
	{
		kill(pid, SIGUSR1);
		// write(1, "1", 1);
		usleep(66);
	}
	else
	{
		kill(pid, SIGUSR2);
		// write(1, "0", 1);
		usleep(66);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		printf("wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	printf("PID: %d\n", pid);
	printf("msg: %s\n", argv[2]);
	i = 0;
	while (argv[2][i] != 0)
	{
		send_signal(argv[2][i], pid);
		i++;
	}
	return (EXIT_SUCCESS);
}

// a
// 97
// 1	1	0	0	0	0	1
// 2^6 2^5 2^4 2^3 2^2 2^1 2^0

