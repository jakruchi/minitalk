/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:42:39 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/23 12:59:12 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// printf
#include <signal.h> // kill
#include <unistd.h> // pause
#include <stdlib.h> // malloc, exit, free

void	int_to_binary(unsigned short int c)
{
	char	*result;
	int		i;

	result = (char *)malloc(17 * sizeof(char));
	if (result == NULL)
	{
		exit(1);
	}
	i = 15;
	while (i >= 0)
	{
		if ((c % 2) == 1)
		{
			result[i] = '1';
		}
		else
			result[i] = '0';
		c = c >> 1;
		i--;
	}
	result[17] = '\0';
	printf("%s\n", result);
	free(result);
}

int	ft_isspace(int c) // static
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr) // static
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

unsigned short int ft_strlen(const char *s) //static
{
	unsigned short int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	send_str_lenght(unsigned short int len, pid_t pid) // static
{
	// printf("%lu\n", sizeof(len));
	int	i;

	i = 0;
	while (i <= (int)((sizeof(len)*8)-1))
	{
		if (len & 1)
		{
			printf("1");
			kill(pid, SIGUSR2); // 1
		}
		else
		{
			printf("0");
			kill(pid, SIGUSR1); // 0
		}
		len >>= 1;
		i++;
		usleep(10000);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	unsigned short int	len; // might change to unsigned short int
	pid_t	pid;

	if (argc != 3)
	{
		printf("Invalid number of arguments. You Dummy.");
		return (1);
	}
	len = ft_strlen(argv[1]);
	pid = ft_atoi(argv[2]);
	printf("sending: %hu\n", len);
	int_to_binary(len);
	send_str_lenght(len, pid);
	pause();
	kill(pid, SIGTERM);
	return (0);
}
