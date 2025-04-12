/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_unpauser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:58:11 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/24 00:01:07 by jankruchina      ###   ########.fr       */
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

size_t	ft_strlen(const char *s) //static
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	send_strlen(pid_t pid, size_t strlen)
{
	int	i;
	i = sizeof(strlen) * 8;
	while (i)
	{
		if (strlen & 1)
			kill(pid, SIGUSR2); // 1
		else
			kill(pid, SIGUSR1); // 0
		strlen >>= 1;
		i--;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
