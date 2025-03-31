/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:10:21 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/28 22:22:28 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
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

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static void	send_strlen(pid_t pid, size_t strlen)
{
	short int	i;

	i = 0;
	while (i < 32)
	{
		if (strlen & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		strlen >>= 1;
		i++;
		usleep(1);
	}
}

static void	send_str(pid_t pid, char *str, size_t strlen)
{
	size_t	i;
	int		j;

	i = 0;
	while (i <= strlen)
	{
		j = 8;
		while (j)
		{
			if (str[i] & 0x01)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			str[i] >>= 1;
			j--;
			usleep(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	size_t		strlen;
	const char	*error;

	error = NULL;
	if (argc != 3)
		error = "Wrong number of arguments. You dummy.\n";
	else if (argv[2][0] == '\0')
		error = "You are sending an empty string. You dummy.\n";
	else if (ft_atoi(argv[1]) < 2)
		error = "PID has to be higher than 1. You dummy.\n";
	else if (ft_strlen(argv[2]) > 4294967295)
		error = "Message is too long. Message was not send. You dummy.\n";
	if (error)
	{
		write(1, error, ft_strlen(error));
		return (1);
	}
	pid = ft_atoi(argv[1]);
	strlen = ft_strlen(argv[2]);
	send_strlen(pid, strlen);
	usleep(1);
	send_str(pid, argv[2], strlen);
	return (0);
}
