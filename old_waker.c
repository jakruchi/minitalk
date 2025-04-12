/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:07:48 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/22 12:26:41 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int	char_to_int(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 2)
	{
		printf("incorrect number of arguments\n");
		exit (1);
	}
	pid = char_to_int(argv[1]);
	printf("PID entered: %d\n", pid);
	kill(pid, SIGUSR1);
	return (EXIT_SUCCESS);
}
