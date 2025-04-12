/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:36:34 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/23 14:44:45 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf()
#include <signal.h> // kill()
#include <unistd.h> // usleep()

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

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 2)
		printf("wrong number of arguments. LOOSER\n");
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR2);
	return (0);
}
